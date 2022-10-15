def kap_diff(n : int) -> int:
    digits = []
    for i in range(4):
        digits.append(n % 10)
        n //= 10
    digits.sort()
    big = 0
    for i in range(4):
        big += digits[i]*(10**(i))
    digits.sort(reverse=True)
    small = 0
    for i in range(4):
        small += digits[i]*(10**(i))
    return big-small


def kaprekar_const(n : int) -> list:
    seq = [n]
    
    while (kap_diff(n) != n):
        n = kap_diff(n)
        kaprekar_const(n)
        seq.append(n)
    return seq
    
print(kaprekar_const(7299))