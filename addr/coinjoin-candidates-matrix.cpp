#include <bitcoin/bitcoin.hpp>
#include <leveldb/db.h>

#define SIZE 10
using namespace bc;

int main()
{
    int matrix[SIZE][SIZE]={0};
    int noins, noouts;
    leveldb::DB* db;
    leveldb::Options options;
    leveldb::Status status = leveldb::DB::Open(options, "../blockchain/tx", &db);
    assert(status.ok());

    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        const uint8_t* value =
            reinterpret_cast<const uint8_t*>(it->value().data());
        const size_t size = it->value().size();
        BITCOIN_ASSERT(size > 8);
        transaction_type tx;
        satoshi_load(value + 8, value + size, tx);
        std::set<std::string> ins, outs;
        for (auto inp: tx.inputs)
        {
            payment_address addr;
            if (!extract(addr, inp.script))
                continue;
            ins.insert(addr.encoded());
        }
        for (auto outp: tx.outputs)
        {
            payment_address addr;
            if (!extract(addr, outp.script))
                continue;
            outs.insert(addr.encoded());
        }
        noins = ins.size();
        noouts = outs.size();
        if ((1<noins)&&(noins<SIZE)&&(3<noouts)&&(noouts<SIZE))
            matrix[noins][noouts]++;
    }
    assert(it->status().ok());
    delete it;
    delete db;

    for (noins=0; noins<SIZE; noins++)
    {
        for (noouts=0; noouts<SIZE; noouts++)
            std::cout << matrix[noins][noouts] << " ";
        std::cout << std::endl;
    }
      
    return 0;
}

