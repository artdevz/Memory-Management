set terminal pngcairo size 1920,1080 enhanced font 'Arial,18'
set output 'plots/fifo_plot.png'
set title 'Comparação FIFO x Aging'
set xlabel 'Número de Molduras'
set xtics 1
plot \
    'data/output_data.txt' using 1:2 with linespoints lt rgb 'green' lw 2 title 'FIFO', \
    'data/output_data.txt' using 1:3 with linespoints lt rgb 'red' lw 2 title 'Aging'
