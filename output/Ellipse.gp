set parametric
set size ratio -1
set xrange [-16:16]
set yrange [-8:8]
plot 8 * cos(t), 4 * sin(t) with lines title 'Ellipse'
