is_fahrenheit = int(input())
temperature = float(input())
def Temperature():
    if is_fahrenheit == 1:
        return round((temperature-32)*5/9,4)
    if is_fahrenheit == 0:
        return round((temperature*9/5)+32,4)
print(Temperature())
