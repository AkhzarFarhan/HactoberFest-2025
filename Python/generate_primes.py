# generate primes in certain range
lower_bound = int(input("Enter lower range: "))  
upper_bound = int(input("Enter upper range: "))  
  
for num in range(lower_bound,upper_bound + 1):  
   if num > 1:  
       for i in range(2,num):  
           if (num % i) == 0:  
               break  
       else:  
           print(num)  
