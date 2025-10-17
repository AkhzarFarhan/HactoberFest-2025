from math import factorial

lower = int(input("enter starting no :"))

upper = int(input("enter ending no :"))
y=[]

for num in range(lower, upper + 1): 
    sum = 0
    temp = num

    while temp > 0:
        digit = temp % 10
        sum += factorial(digit)
        temp //= 10

    if num == sum:
        y.append(num)

print(y)