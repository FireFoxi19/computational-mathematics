from decimal import Decimal as Dec
import decimal
import math

ROUND = decimal.getcontext().prec = 40
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

def F(q):
    res = q**2 - 3
    return res

def F1(t):
    res1 = 2*t
    return res1

def  F2():
    res2 = 2
    return res2

a = Dec(input('a = '))
b = Dec(input('b = '))
e: Dec = Dec(input('e = '))
eps = abs(b-a)/2
count = 0

if F2() < 0 and F(a) < 0 or F2() > 0 and F(a) > 0:
    x0 = a
    print('x0 = ', round(x0, 11))
elif F2() < 0 and F(b) < 0 or F2() > 0 and F(b) > 0:
    x0 = b
    print('x0 = ', round(x0, 11))

while eps > e:
    x1 = x0
    count += 1
    print('Шаг ', count)
    x0 -= (F(x0)/F1(x0))
    print('X = ', round(x0,11))
    if (abs(x1-x0) < e):
        break
