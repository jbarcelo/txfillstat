import leveldb
db = leveldb.LevelDB("blockchain/tx")
for tx_hash, tx_data in db.RangeIter():
    print len(tx_data)

