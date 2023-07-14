k = int(input())
l = int(input())
n = -1
while l%k==0:
    l//=k
    n+=1
if n >= 0 and l == 1:
    print('YES')
    print(n)
else:
    print('NO')