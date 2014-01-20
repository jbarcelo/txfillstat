#set term postscript enhanced eps color "NimbusSanL-Regu,17" fontfile "/usr/share/texlive/texmf-dist/fonts/type1/urw/helvetic/uhvr8a.pfb"
set terminal png
set output "coinjoin-candidates-matrix.eps"
set size ratio 0.5
set title "Ins and Outs for CoinJoin candidate transactions"

set xlabel "outs"
set ylabel "ins"

set tic scale 0

set palette gray
set palette negative

set cbrange [1:8000]
set logscale cb
#unset cbtics

set xrange [4:9]
set yrange [2:9]

set view map

splot 'coinjoin-candidates-matrix.data' matrix with image
