def fib(number_of_terms):
   counter = 0

   first = 0
   second = 1
   temp = 0

   while counter <= number_of_terms:
      print(first)
      temp = first + second
      first = second
      second = temp
      counter += 1

# Driver Code
fib(10)
