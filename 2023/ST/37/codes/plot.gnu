set terminal pngcairo enhanced color size 600,400
set output '../figs/cdf_plot_Y.png'
plot './y_data.txt' using 1:2 with lines title 'CDF(Y)'