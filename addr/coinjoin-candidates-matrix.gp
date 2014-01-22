set term postscript enhanced eps color 
set output "coinjoin-candidates-matrix.eps"
set size 0.65,0.65
#set title "Ins and Outs for CoinJoin candidate transactions"

set xlabel "outs"
set ylabel "ins"

set tic scale 0

set palette gray
set palette negative

set cbrange [10:10000]
set logscale cb
#unset cbtics

set xrange [4:9]
set yrange [2:9]

set view map

splot 'coinjoin-candidates-matrix.data' matrix with image
