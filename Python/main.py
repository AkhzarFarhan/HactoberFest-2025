import math

def decimal_to_binary(n):
    return bin(n).replace("0b", "")

def decimal_to_octal(n):
    return oct(n).replace("0o", "")

def decimal_to_hexadecimal(n):
    return hex(n).replace("0x", "").upper()

def binary_to_decimal(b):
    return int(b, 2)

def octal_to_decimal(o):
    return int(o, 8)

def hexadecimal_to_decimal(h):
    return int(h, 16)

def convert_number(value, base_from, base_to):
    if base_from == 'decimal':
        number = int(value)
    elif base_from == 'binary':
        number = binary_to_decimal(value)
    elif base_from == 'octal':
        number = octal_to_decimal(value)
    elif base_from == 'hexadecimal':
        number = hexadecimal_to_decimal(value)
    else:
        raise ValueError("Unsupported base")

    if base_to == 'decimal':
        return str(number)
    elif base_to == 'binary':
        return decimal_to_binary(number)
    elif base_to == 'octal':
        return decimal_to_octal(number)
    elif base_to == 'hexadecimal':
        return decimal_to_hexadecimal(number)
    else:
        raise ValueError("Unsupported base")

def scientific_function(func, value, y=None):
    if func == 'sin':
        return math.sin(math.radians(value))
    elif func == 'cos':
        return math.cos(math.radians(value))
    elif func == 'tan':
        return math.tan(math.radians(value))
    elif func == 'log':
        return math.log(value)
    elif func == 'exp':
        return math.exp(value)
    elif func == 'sqrt':
        return math.sqrt(value)
    elif func == 'power':
        if y is not None:
            return math.pow(value, y)
        else:
            raise ValueError("Power function requires two arguments.")
    elif func == 'epower':
        return math.exp(value)
    else:
        raise ValueError("Unsupported function")

# Main interactive loop
if __name__ == "__main__":
    while True:
        print("\nChoose an option:")
        print("1. Base Conversion")
        print("2. Scientific Functions")
        print("3. Exit")
        
        choice = input("Enter your choice (1/2/3): ")
        
        if choice == '1':
            base_from = input("Enter the base to convert from (decimal/binary/octal/hexadecimal): ").lower()
            value = input(f"Enter the value in {base_from}: ")
            base_to = input("Enter the base to convert to (decimal/binary/octal/hexadecimal): ").lower()
            
            try:
                result = convert_number(value, base_from, base_to)
                print(f"{value} in {base_from} is {result} in {base_to}.")
            except ValueError as e:
                print(e)
        
        elif choice == '2':
            func = input("Enter the scientific function (sin/cos/tan/log/exp/sqrt/power/epower): ").lower()
            value = float(input("Enter the value: "))
            
            if func == 'power':
                y = float(input("Enter the exponent (y): "))
                try:
                    result = scientific_function(func, value, y)
                    print(f"The result of {value}^{y} is {result}.")
                except ValueError as e:
                    print(e)
            else:
                try:
                    result = scientific_function(func, value)
                    print(f"The result of {func}({value}) is {result}.")
                except ValueError as e:
                    print(e)
        
        elif choice == '3':
            print("Exiting the calculator.")
            break
        
        else:
            print("Invalid choice. Please select 1, 2, or 3.")
