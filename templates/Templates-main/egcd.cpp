int egcd(int a, int b, int& x, int& y) {
    x = 1; y = 0;
    int x1 = 0, y1 = 1;
    while (b) {
        int q = a / b, t = b;
        b = a % b; a = t;
        t = x1; x1 = x - q * x1; x = t;
        t = y1; y1 = y - q * y1; y = t;
    }
    return a;
}