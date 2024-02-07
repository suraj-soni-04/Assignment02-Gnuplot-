set xrange [0:16]
set xrange [0:16]
sideA = 5
sideB = 12
sideC = 13
x1 = 2
y1 = 2 
x2 = x1 + 5
y2 = y1
x3 = (x1^2 + 12^2 - 13^2) / (2 * 5)
y3 = y1 + sqrt(12^2 - (x3 - x1)^2)
set object 1 polygon from x1, y1 to x2, y2 to x3, y3 to x1, y1 fc rgb 'orange'
plot x
