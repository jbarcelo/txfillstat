import leveldb
db = leveldb.LevelDB("blockchain/tx")
cumulative = False
step = 50
# Vast majority of txs are below 2k bytes
categories = [0] * (2000 / step)
tx_total = 0
for tx_hash, tx_data in db.RangeIter():
    category = len(tx_data) / step
    if category >= len(categories):
        category = len(categories) - 1
    if cumulative:
        # Cumulative version.
        for i in range(category, len(categories)):
            categories[i] += 1
    else:
        # Categorised by size
        categories[category] += 1
    # -----------------
    tx_total += 1
    #if tx_total > 30:
    #    break
if cumulative:
    # Cumulative assert
    assert categories[-1] == tx_total
else:
    # Categorised assert
    assert sum(categories) == tx_total
print "labels:"
labels = []
for i, freq in enumerate(categories):
    labels.append(str(i * step))
print labels, ","
print "data:"
print categories

