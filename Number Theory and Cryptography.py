# https://www.math.utah.edu/~carlson/hsp2004/PythonShortCourse.pdf

def gcd(a,b):
    r = a % b
    while r > 0:
        # print a, b, r
        a, b, r = b, r, b%r
    return b
# print(gcd(10, 15))

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

def FastModularExponentiation(x, y, m):
    return pow(x, y, m)
print(FastModularExponentiation(34, 60, 77))

def ModuloInverse(a, m):
    x0, x1, m0 = 0, 1, m

    if (m == 1):
        return 0

    while (a > 1):
        q, t = a // m, m
        m, a, t = a % m, t, x0
        x0, x1 = x1 - q * x0, t

    x1 = (x1 % m0 + m0) % m0;
    return x1

"""
    Chinese Remainder Theorem:
    - If GCD(a, b) = 1, then there exists a number n such that n % a = ra and n % b = rb, for any pair (ra, rb).
    - If there are two such integers n1 and n2, n1 ≡ n2 (mod a * b).
    Proof:
    - GCD(a, b) = 1, so a * x + b * y = 1 for some integer (x, y).
    - ax ≡ 1 (mod b), by ≡ 1 (mod a)
    - n = ra * b * y +  rb * a * x
"""

def ChineseRemainderTheorem(n1, r1, n2, r2):
    n = n1 * n2
    res = r1 * ModuloInverse(n2, n1) * n2
    res = res + r2 * ModuloInverse(n1, n2) * n1
    # print(res % n1, res % n2)
    return res % n
# print(ChineseRemainderTheorem(686579304, 295310485, 26855093, 8217207))

/*
    RSA Encryption:
    - Public key E: Used to encrypt code, Available for everyone 
    - Private key D: Used to decrypt code, Only available to Bob
    
    Algorithm
    - Generate 2 big random primes: p and q 
    - To avoid attacks: 2048 bits long, |p - q| should be large, use proper seed to avoid insufficient randomness, add random padding to m before encryption
    - n = p * q
    - Generate random number e coprime with (p - 1) * (q - 1)
    - E = (n, e)
    - D = (p, q)

    Encryption
    - Convert message to sequence of bits
    - Length in bits should be between 0 and (n - 1). (p, q, should be sufficiently large)
    - Ciphertext c = pow(m, e) % n
    - Decryption: Precompute d such that ed ≡ 1 mod (p - 1) * (q - 1) (Using Extended Euclid's Algorithm) (e'th Mdoular root of c)
*/
