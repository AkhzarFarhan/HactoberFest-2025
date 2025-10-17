n=int(input("Enter Range:"))

sum=0

print("Numbers are:",end=" ")

for i in range(1,n+1):
    print(i,end=",")

print("\nSquere are:",end=" ")

for i in range(1,n+1):
    print(i*i,end=",")
    sum += i*i

print("\nSum of Series:",sum)