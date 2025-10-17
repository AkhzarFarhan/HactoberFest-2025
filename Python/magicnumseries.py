y=[]
for i in range(1,10000):
    a = i
    s = 0

    while (a>0):
        digit = a%10
        s += digit
        a//=10

    z = s
    s_rev = 0
    t= s

    while(t>0):
        digit1 = t%10
        s_rev = s_rev*10 + digit1
        t//=10

    if(z*s_rev==i):
        y.append(i)

print(y)