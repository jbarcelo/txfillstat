import leveldb
import obelisk
db = leveldb.LevelDB("../blockchain/tx")
for tx_hash, tx_data in db.RangeIter():
    # [ height:4 ] [ index:4 ] [ raw_tx ]
    raw_tx = tx_data[8:]
    tx = obelisk.serialize.deser_tx(raw_tx)
    print len(tx.inputs), len(tx.outputs)

