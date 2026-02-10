bool isPrime(int n) {
    if (n <= 1)
        return false;
    
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int primesc = sizeof(primes) / sizeof(primes[0]);
    for (int i = 0; i<primesc; i++) {
        if (n == primes[i])
            return true;
        if (n % primes[i] == 0)
            return false;
    }
    
    int arr[] = {1, 7, 11, 13, 17, 19, 23, 29};
    int arrc = sizeof(arr)/sizeof(arr[0]);
    // 30k + 1, 30k + 7
    for (int i = 30; i * i <= n; i += 30)
        for (int j = 0; j < arrc; j++)
            if (n % (i+arr[j]) == 0)
                return false;

    return true;
}