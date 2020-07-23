# https://www.math.utah.edu/~carlson/hsp2004/PythonShortCourse.pdf

def gcd(a,b):
    r = a % b
    while r > 0:
        # print a, b, r
        a, b, r = b, r, b%r
    return b

def diophantine(a, b, c):
    q, r = divmod(a, b)
    if r == 0:
        return(0, c / b)
    else:
        sol = diophantine(b, r, c)
        u = sol[0]
        v = sol[1]
        return(v, u - q * v)

# print(diophantine(10, 15, 5))

# Multiplicative inverse using LDE
def divide(a, b, n):
    sol = diophantine(a, n, b)
    x = sol[0]
    x = (x % n + n) % n
    return x

# print(divide(2, 3, 5))
