class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> denom(3, 0); //stores count of 5, 10, 20 rup we have
        int n = bills.size();
        for(int i = 0; i < n; i++) {
            // Loading the given bill - 5
            if(bills[i] == 5) denom[0]++;
            else if(bills[i] == 10) denom[1]++;
            else denom[2]++;
            //check if the guy has change
            int change = bills[i] - 5;
            // see his change and give him back
            if(change != 0) {
                while(denom[2] > 0 && change >= 20) {
                    change -= 20;
                    denom[2]--;
                }
                while(denom[1] > 0 && change >= 10) {
                    change -= 10;
                    denom[1]--;
                }
                while(denom[0] > 0 && change >= 5) {
                    change -= 5;
                    denom[0]--;
                }
                if(change != 0) return false;
            }
        }
        return true;
    }
};