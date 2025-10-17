prime=[]

for j in range(1,101):

    n=j

    s = sum((n%i==0) for i in range(1,n+1))
    if(s==2):

        prime.append(n)

print(prime)