n, m = [int(x) for x in input().split(' ')]

total = 0
circle = [x for x in range(1,n+1)]
i = 0
while (total+circle[i]<=m):
    if total + circle[i] <= m:
        total += circle[i]
    i = (i+1)%n

print(max(0, m-total))