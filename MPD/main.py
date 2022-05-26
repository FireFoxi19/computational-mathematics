import math
from decimal import Decimal as Dec
import decimal


ROUND = decimal.getcontext().prec = 15
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

def F(q):
    res = q**2-3
    return res

a = Dec(input("enter a: "))
b = Dec(input("enter b: "))
e: Dec = Dec(input("enter e: "))

res = F(a)*F(b)   #значение ф-ии в крайних точках
print('F(a)*F(b) = ', res)

count = 0
eps = abs(b-a)/2
c = (a+b)/2
C = F(c)
#print('F(c) = ', C, '\n', eps)
while eps > e:
    if eps <= e:
        break
    count += 1
    print('Шаг ', count)
    c = (a+b)/2
    print('В новых интервалах:   (', a, ' ; ', c, ')', '\n\t\t\t\t\t', '(', c, ' ; ', b, ')')
    if F(a)*F(c) < 0:
        f1 = F(a)*F(c)
        print('F(a)*F(c) = ', round(f1, 11))
        b = c
    elif F(c)*F(b) < 0:
        f2 = F(c)*F(b)
        print('F(c)*F(b) = ', round(f2, 11))
        a = c
        print('c = ', c, '\n')
    eps = abs(b-a)/2





