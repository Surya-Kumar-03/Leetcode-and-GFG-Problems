int countDigits(int n) {
    // code here
    int digitCount = 0;
    int copyNum = n;
    while (copyNum > 0) {
        digitCount++;
        copyNum /= 10;
    }
    
    return digitCount;
}