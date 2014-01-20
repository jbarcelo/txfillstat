#set term postscript enhanced eps color "NimbusSanL-Regu,17" fontfile "/usr/share/texlive/texmf-dist/fonts/type1/urw/helvetic/uhvr8a.pfb"
set term postscript enhanced eps color 
set size 0.60,0.60
#set terminal png enhanced font arial 14 size 800, 600
set output "address_reuse.eps"
set xlabel "times used (capped at 100)"
set ylabel "number of addresses"
set xrange [0:100]
set title "Address re-use in the first 234507 blocks"
binwidth=1
bin(x,width)=width*floor(x/width)
set table 'address_reuse.table'
plot 'address_reuse.data' using (bin($1,binwidth)):(1.0) smooth freq with boxes
unset table
set logscale y
plot 'address_reuse.table' u 1:2:(binwidth) w boxes
