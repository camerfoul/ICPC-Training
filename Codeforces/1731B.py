MOD = int(1e9 + 7)

T = int(input())
for _ in range(T):
    n = int(input())
    result = (n * (n + 1) * (4 * n - 1)) // 6
    print((result * 2022) % MOD)