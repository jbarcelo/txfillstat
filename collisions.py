import leveldb
import resource
page_size = resource.getpagesize()
print "pagesize:", page_size
# There are 26 million Bitcoin txs
buckets_size = 100000000
print "buckets_size:", buckets_size
db = leveldb.LevelDB("blockchain/tx")
counts = list(0 for i in range(buckets_size))
print "Looping..."
tx_idx = 0
for tx_hash in db.RangeIter(include_value=False):
    tx_idx += 1
    #if tx_idx % 100000 == 0:
    #    print tx_idx
    val = int(tx_hash.encode("hex"), 16)
    index = val % buckets_size
    counts[index] += 1
print "Finished:", tx_idx
print counts
print "Generating summary..."
totals = list(0 for i in range(20 + 1))
for count in counts:
    print "count:", count
    if count < 20:
        totals[count] += 1
    else:
        totals[20] += 1
print totals
assert sum(totals[1:]) == tx_idx

