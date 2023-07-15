a,b,r,n = [int(x) for x in input().split(' ')]
# t = sum((1 if x%n<=r else 0 for x in range(max(a,n),b+1)))
if (b<n and r < b):
    print(0)
    exit(0)

if b-a == 0:
    print(1)
    exit(0)

if r >= b:
    print(b-a+1)
    exit(0)

fisrt_div = -1
last_div = -1

for i in range(max(a,n),b+1):
    if i%n==0:
        fisrt_div = i
        break

fisrt_div = fisrt_div if a>=n else a

last_div = b//n if b//n else b
last_div*= n if b//n else 1

zeroes = (b+r)//n - fisrt_div//n
result = zeroes+zeroes*r-(last_div+r-b)
if (a<n and r>=a):
    result += r-fisrt_div+a
print(result)