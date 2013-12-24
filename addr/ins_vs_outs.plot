#set xrange [0:1500]
#set yrange [0:10000000]
set terminal png size 1000,800 enhanced font "Helvetica,20"
set output 'ins_vs_outs.png'
plot 'ins_vs_outs.data' using 1:2

