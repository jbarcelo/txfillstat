from buckets_data import *

# uin64_t = 8 bytes
offset_ptr_size = 8

for bucket_size, volumes in bucket_freqs.iteritems():
    file_size = bucket_size * offset_ptr_size / 1000 / 1000
    print "%s Mb header" % file_size
    for i, fill in enumerate(volumes):
        if i == 0:
            empty_percent = (fill * 100.0) / bucket_size
            print "  %.2f %% of buckets are empty" % empty_percent
            continue
        percent_filled = (fill * i * 100.0) / total_tx
        print "  %s: %.2f %%" % (i, percent_filled)

