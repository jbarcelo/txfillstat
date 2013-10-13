from buckets_data import *
import random

def random_color():
    # This is not production code
    color = ""
    color += str(random.randint(0, 255))
    color += ","
    color += str(random.randint(0, 255))
    color += ","
    color += str(random.randint(0, 255))
    return color

bucket_sizes = bucket_freqs.keys()
bucket_sizes.sort()
# We reverse so that smaller graphs can show on top.
bucket_sizes = bucket_sizes[::-1]

for bucket_size in bucket_sizes:
    volumes = bucket_freqs[bucket_size]
    print "{"
    color = random_color()
    print '    fillColor: "rgba(%s, 0.2)",' % color
    print '    strokeColor: "rgba(%s, 1)",' % color
    percentages = []
    for i, fill in enumerate(volumes[1:], 1):
        percent_filled = (fill * i * 100.0) / total_tx
        percentages.append(percent_filled)
    print "    data:", percentages
    print "},"

