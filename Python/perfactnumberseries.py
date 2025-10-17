perfect=[]

for j in range(1,10000):
    n=j

    sum = sum(i for i in range(1,n) if (n%i==0))
    if(sum==n):
        perfect.append(n)

print(perfect)