import sys

def solve():
    # Read all inputs from standard input
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    T = int(input_data[0])
    idx = 1
    MOD = 10**9 + 7

    for _ in range(T):
        m = int(input_data[idx])
        K = int(input_data[idx+1])
        idx += 2

        # 1. Construct the big number as a string
        n_str_parts = []
        for _ in range(K):
            a = int(input_data[idx])
            b = int(input_data[idx+1])
            # Create a string of digit 'a' repeated 'b' times
            n_str_parts.append(str(a) * b)
            idx += 2

        # Join the parts and convert to a Python arbitrary-precision integer
        N = int("".join(n_str_parts))

        # 2. Bruteforce loop to count multiples of m
        count = 0
        for x in range(1, N + 1):
            if x % m == 0:
                count += 1

        # 3. Output the required modulo
        print(count % MOD)

if __name__ == '__main__':
    solve()