#include <bitcoin/bitcoin.hpp>
#include <leveldb/db.h>
using namespace bc;

int main()
{
    std::map<std::string,int> outs_map;
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
        std::set<std::string> outs;
        for (auto outp: tx.outputs)
        {
            payment_address addr;
            if (!extract(addr, outp.script))
                continue;
            outs.insert(addr.encoded());
            if (!outs_map.count(addr.encoded()))
                outs_map[addr.encoded()]=0;
            outs_map[addr.encoded()]++;
        }
    }
    assert(it->status().ok());
    delete it;
    delete db;

    // show content:
    for (std::map<std::string,int>::iterator it=outs_map.begin(); it!=outs_map.end(); ++it)
        std::cout << it->second << '\n';

    return 0;
}

