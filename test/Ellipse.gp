set parametric
set size ratio -1
set xrange [-46:46]
set yrange [-8:8]
plot 23 * cos(t), 4 * sin(t) with lines title 'Ellipse'
