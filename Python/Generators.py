# This is a simple program in which we are using generator

def generator():
    for i in range(10):
        yield i

data = generator()

for values in data:
    print(values)
