import decimal
import math
from decimal import Decimal as Dec

ROUND = decimal.getcontext().prec = 15
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

def L1(a1, b1):
    l1 = Dec(str(a1 + Dec("0.382")*(b1-a1)))
    return l1

def L2(a2, b2):
    l2 = Dec(str(a2 + Dec("0.618")*(b2-a2)))
    return l2

def Form(q):
    f = pow(q,2) - 6*q
    return f

count = 1
a = Dec(input("а = "))
b = Dec(input("b = "))
e: Dec = Dec(input("точность = "))
#step = int(input("количество шагов: "))

while (b-a)/2 >= e:
    if abs(b-a) < e:
        break
    #for count in range(1,step+1):
    print("\nШаг ", count)
    count += 1
    l_1 = L1(a, b)
    l_2 = L2(a, b)
    F1 = Form(l_1)
    F2 = Form(l_2)
    print("L1 = ", l_1)
    print("L2 = ", l_2)
    print("l1 = ", F1)
    print("l2 = ", F2)
    if Dec(str(Form(l_1))) > Dec(str(Form(l_2))):
        a = l_1
        F2 = F1
        print("a = ", a)
    else:
        b = l_2
        F1 = F2
        print("b = ", b)
x = (a + b) / 2
print("результат:\n", round(x, 5), "\n", round(Form(x), 5))

