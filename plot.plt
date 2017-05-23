#!/usr/bin/gnuplot

set xlabel "{/:Italic x}"
set ylabel "{/:Italic y}"

plot "air.dat" using 2:3 w p title "air, {/:Italic k} = 0.1", "vacuum.dat" using 2:3 w p title "vacuum", "parabola.dat" u 1:2 w l title "parabola"

pause -1

