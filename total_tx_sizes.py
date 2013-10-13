import leveldb
db = leveldb.LevelDB("blockchain/tx")
total = 0
for tx_hash, tx_data in db.RangeIter():
    total += len(tx_data)
print total, "bytes"

