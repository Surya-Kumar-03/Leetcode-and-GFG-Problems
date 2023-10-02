class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if(n < 3) return false; // Bob wins no matter what the case

        int Amoves = 0, Bmoves = 0;
        int cur = 1;
        bool flag;
        if(colors[0] == 'A') {
            flag = true;
        } else {
            flag = false;
        }

        for(int i = 1; i < n; i++) {
            if((colors[i] == 'A' && flag == true) || (colors[i] == 'B' && flag == false)) 
            {
                cur++;
                if(cur == 3) {
                    if(flag) Amoves++;
                    else Bmoves++;
                    cur--;
                }
            }
            else {
                cur = 1;
                flag = (colors[i] == 'A') ? true : false;
            }
        }

        return Amoves > Bmoves;
    }
};