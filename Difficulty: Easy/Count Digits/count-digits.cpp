int countDigits(int n) {
    // code here
    int digitCount = 0;
    while (n > 0) {
        digitCount++;
        n /= 10;
    }
    
    return digitCount;
}