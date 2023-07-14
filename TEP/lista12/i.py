r,g,b=[int(x) for x in input().split(' ')]
total = -1
car = 0
t = 0
while(any([r,g,b])):
    t += 1
    if r and not car:
        r = max(min(r-1, r-2), 0)
        total += t
        t=0
    if g and car == 1:
        g = max(min(g-1, g-2), 0)
        total += t
        t=0
    if b and car == 2:
        b = max(min(b-1, b-2), 0)
        total += t
        t=0
    car += 1
    car = car%3
print(total+30)