n, c = 444444, 0
dic = {}
m = 7
for _ in range(10008):
    print(n)
    for __ in range(10006):
        n = n * 10 + 4
        n %= m

