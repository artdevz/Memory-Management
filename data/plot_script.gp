set terminal pngcairo size 1920,1080 enhanced font 'Arial,18'
set output 'plots/fifo_plot.png'
set title 'Comparação FIFO x Aging'
set xlabel 'Número de Molduras'
set xtics 1
set ylabel 'Falta de Páginas'
set key outside
plot \
    'data/output_data.txt' using 1:2 with linespoints lt rgb 'green' lw 2 title 'FIFO', \
    'data/output_data.txt' using 1:3 with linespoints lt rgb 'red' lw 2 title 'Aging', \
    'data/output_data.txt' using 1:2:4 with labels offset char 0,1 notitle, \
    'data/output_data.txt' using 1:3:5 with labels offset char 0,-1 notitle
