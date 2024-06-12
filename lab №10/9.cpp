mod = 999999893
N = 2e6 + 5

def pw(x, y):
    if y == 0:
        return 1
    if y % 2:
        return x * pw(x, y - 1) % mod
    res = pw(x, y // 2)
    return res * res % mod


if __name__ == "__main__":
    n = int(input())
    p = 2 * (pw(2, n // 2) - 1) % mod
    q = pw(2, (n + 1) // 2)
    div = (p * p + (mod - q) * q * 2) % mod
    res = 2 * (mod - p) * pw(div, mod - 2) % mod
    print(res)
