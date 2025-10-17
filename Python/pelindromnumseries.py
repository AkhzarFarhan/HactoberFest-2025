y=[]

for i in range(1, 1001):
    n=i
    s = 0

    while n > 0:
        digit = n % 10
        s = (s*10)+digit
        n //= 10

    if s == i:
        y.append(i)

print(y)