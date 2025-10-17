def is_even1(n):
    if n == 0:
        return True
    else:
        return is_odd1(n - 1)

def is_odd1(n):
    if n == 0:
        return False
    else:
        return is_even1(n - 1)

def is_even2(n):
    return n % 2 == 0
def is_odd2(n):
    return n % 2 == 1

print(is_odd1(5))
