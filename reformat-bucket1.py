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

print "labels:", [size * 8 / 1000000 for size in bucket_sizes]
print

print "{"
color = random_color()
print '    fillColor: "rgba(%s, 0.2)",' % color
print '    strokeColor: "rgba(%s, 1)",' % color

percentages = []
for bucket_size in bucket_sizes:
    volumes = bucket_freqs[bucket_size]
    fill = volumes[1]
    percent_filled = (fill * 100.0) / total_tx
    percentages.append(percent_filled)

print "    data:", percentages
print "},"

