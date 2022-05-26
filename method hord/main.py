from math import *
import decimal
from decimal import Decimal as Dec

ROUND = decimal.getcontext().prec = 15
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

def F(q):
    res = 0
    res = q ** 2 - 3
    return res

def FormC(a1, b1):
    res1 = 0
    res1 = Dec(str((a1 * F(b1) - b1 * F(a1)) / (F(b1) - F(a1))))
    return res1


a = Dec(input("а = "))
b = Dec(input("b = "))
E: Dec = Dec(input("точность = "))

count = 0
Cn = 0
m = 1
c = FormC(a, b)

while m >=E:
    if m < E:
        break
    count += 1
    print("Шаг ", count, "\n")
    c = FormC(a, b)
    m = abs(c - Cn)
    Cn = c
    print("Новый интервал:", a, ";",c, ")", "\n\t\t", "(", c, ";", b, ")")
    if F(a) * F(c) < 0:
        print("F(a)*F(c) = ", round(F(a) * F(c), 11))
        b = c
    elif F(c) * F(b) < 0:
        print("F(c)*F(b) = ", round(F(c) * F(b), 11))
        a = c
        print("c = ", round(c, 6))
        print()