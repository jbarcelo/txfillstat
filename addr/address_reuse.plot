set terminal png enhanced font arial 14 size 800, 600
set output "address_reuse.png"
set xlabel "times used"
set ylabel "number of addresses"
binwidth=1
bin(x,width)=width*floor(x/width)
set table 'address_reuse.table'
plot 'address_reuse.data' using (bin($1,binwidth)):(1.0) smooth freq with boxes
unset table
set logscale y
plot 'address_reuse.table' u 1:2:(binwidth) w boxes
