_, d = [int(x) for x in input().split(' ')]
l = [int(x) for x in input().split(' ')]
total = 0

for i, el in enumerate(l):
    if (i+1 < len(l)) and (l[i] >= l[i+1]):
        t = l[i] - l[i+1]
        s = t//d if t else 1
        s = s if s and t%d==0 else s + 1
        l[i+1] += s*d
        if l[i] == l[i+1]:
            s += 1
            l[i+1] += d
        total += s

print(total)