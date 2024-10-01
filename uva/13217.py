import sys
from math import sqrt
f = [sqrt(2) + sqrt(3) + sqrt(6)]
for i in range(10):
    f.append((f[i]*f[i]-5)/(2*f[i]+4))

while True:
    try:
        line = input()
        if len(line) == 1 and int(line) < 3:
            print("%.10lf" % f[int(line)])
        else:
            n = (ord(line[-1]) - ord('0')) % 2
            if n == 0:
                print("%.10lf" % f[4])
            else:
                print("%.10lf" % f[3])
    except EOFError:
        break
