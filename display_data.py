from buckets_data import *

# uin64_t = 8 bytes
offset_ptr_size = 8

bucket_sizes = bucket_freqs.keys()
bucket_sizes.sort()

for bucket_size in bucket_sizes:
    volumes = bucket_freqs[bucket_size]
    file_size = bucket_size * offset_ptr_size / 1000 / 1000
    print "%s Mb header (%s buckets)" % (file_size, bucket_size)
    for i, fill in enumerate(volumes):
        if i == 0:
            empty_percent = (fill * 100.0) / bucket_size
            print "  %.2f %% of buckets are empty" % empty_percent
            continue
        percent_filled = (fill * i * 100.0) / total_tx
        print "  %s: %.2f %% (%s)" % (i, percent_filled, fill)

