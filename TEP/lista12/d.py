def p(a, b):
    print(f"{a} {b}")

s = input()
a,b,n = [int(x) for x in s.split(' ')]

if n <= a:
    p(a-n,b)
elif n <= (a+b):
    p(0, b-(n-a))
else:
    p(0, 0)
