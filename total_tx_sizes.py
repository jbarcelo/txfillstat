import leveldb
import math
db = leveldb.LevelDB("blockchain/tx")
sum_x = 0
sum_x2 = 0
n = 0
for tx_hash, tx_data in db.RangeIter():
    sum_x += len(tx_data)
    sum_x2 += len(tx_data)**2
    n += 1
print n, "txs"
print sum_x, "bytes total"
# Force calcs to floats
n = float(n)
mean = sum_x / n
print "mean =", mean
stdev = math.sqrt((sum_x2 / n) - (mean * mean))
print "stdev =", stdev

