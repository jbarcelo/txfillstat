#include <cassert>
#include <iostream>
#include <unistd.h>
#include <bitcoin/bitcoin.hpp>
#include <gmp.h>
#include <leveldb/db.h>

using namespace bc;

uint64_t remainder(const uint8_t* hash_data, const uint64_t divisor)
{
    mpz_t integ;
    mpz_init(integ);
    mpz_import(integ, 32, 1, 1, 1, 0, hash_data);
    uint64_t remainder = mpz_fdiv_ui(integ, divisor);
    mpz_clear(integ);
    return remainder;
}

void count_txs()
{
    leveldb::DB* db;
    leveldb::Options options;
    leveldb::Status status = leveldb::DB::Open(options, "blockchain/tx", &db);
    assert(status.ok());

    size_t tx_counter = 0;
    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next())
        ++tx_counter;
    assert(it->status().ok());
    delete it;
    delete db;

    std::cout << "total_tx = " << tx_counter << std::endl;
}

void compute_bucket_frequencies(size_t buckets_size)
{
    leveldb::DB* db;
    leveldb::Options options;
    leveldb::Status status = leveldb::DB::Open(options, "blockchain/tx", &db);
    assert(status.ok());

    size_t* buckets_tally = new size_t[buckets_size];
    // Zero out array
    for (size_t i = 0; i < buckets_size; ++i)
        buckets_tally[i] = 0;

    leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next())
    {
        const uint8_t* hash_data =
            reinterpret_cast<const uint8_t*>(it->key().data());
        assert(it->key().size() == 32);
        uint64_t index = remainder(hash_data, buckets_size);
        assert(index < buckets_size);
        buckets_tally[index] += 1;
    }
    assert(it->status().ok());
    delete it;
    delete db;

    size_t freqs_size = 20;
    size_t freqs[freqs_size];
    for (size_t i = 0; i < freqs_size; ++i)
        freqs[i] = 0;

    for (size_t i = 0; i < buckets_size; ++i)
    {
        size_t count = buckets_tally[i];
        // Put all outliers in the last element
        if (count < freqs_size - 1)
            freqs[count] += 1;
        else
            freqs[freqs_size - 1] += 1;
    }

    delete [] buckets_tally;

    // Display frequency totals
    std::cout << "[";
    for (size_t i = 0; i < freqs_size; ++i)
    {
        if (i > 0)
            std::cout << ", ";
        std::cout << freqs[i];
    }
    std::cout << "]";
}

int main()
{
    size_t page_size = sysconf(_SC_PAGESIZE);
    std::cout << "page_size = " << page_size << std::endl;

    count_txs();

    std::cout << "bucket_freqs = {" << std::endl;
    size_t begin = 25000000, step = begin;
    assert(begin + 31 * step == 800000000);
    for (size_t i = 0; i < 31; ++i)
    {
        if (i != 0)
            std::cout << "," << std::endl;
        size_t buckets_size = begin + i * step;
        std::cout << "  " << buckets_size << ": ";
        compute_bucket_frequencies(buckets_size);
    }
    std::cout << std::endl << "}" << std::endl;

    return 0;
}

