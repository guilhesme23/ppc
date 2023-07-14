# Problem: https://vjudge.net/contest/565749#problem/F
n1, n2, k1, k2 = [int(x) for x in input().split(' ')]

while all([n1, n2]):
    n1 -= 1
    n2 -= 1

if n1:
    print('First')
else:
    print('Second')