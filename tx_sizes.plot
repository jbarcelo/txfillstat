clear
reset
set key off
set border 3

# Add a vertical dotted line at x=0 to show centre (mean) of distribution.
set yzeroaxis

# Each bar is half the (visual) width of its x-range.
set boxwidth 0.05 absolute
set style fill solid 1.0 noborder

bin_width = 50;

bin_number(x) = floor(x/bin_width)

rounded(x) = bin_width * ( bin_number(x) + 0.5 )

set xrange [0:1500]
set yrange [0:5000000]
set terminal png size 1000,800 enhanced font "Helvetica,20"
set output 'tx_sizes.png'
plot 'tx_sizes.data' using (rounded($1)):(1) smooth frequency with boxes

