class Solution {
public:
    string intToRoman(int num) {
        vector<string> thou = {"", "M", "MM", "MMM"}; //since constraints stop at 3999
        vector<string> hund = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        return thou[num/1000] + hund[(num/100) % 10] + tens[(num/10) % 10] + ones[(num) % 10];
    }
};