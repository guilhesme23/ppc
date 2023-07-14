original_string = input()
stringLen = len(original_string)
if stringLen%2 == 0:
    p1 = original_string[0:stringLen//2]
    p2 = original_string[stringLen//2:][::-1]
else:
    p1 = original_string[0:(stringLen//2+1)]
    p2 = original_string[(stringLen//2+1):][::-1]

count = 0
for i in range(stringLen//2):
    if p1[i] != p2[i]:
        count += 1

print(count)

