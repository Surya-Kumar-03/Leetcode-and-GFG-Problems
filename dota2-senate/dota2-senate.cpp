class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> ourQueue;
        int rBanned = 0, dBanned = 0;
        int rCount = 0, dCount = 0;
        for(char c : senate){
            ourQueue.push(c);
            if(c == 'D') dCount++; 
            else rCount++;
        }

        while(rCount && dCount){
            char top = ourQueue.front();
            ourQueue.pop();
            if(top == 'D'){
                if(dBanned){
                    dCount--;
                    dBanned--;
                } else {
                    rBanned++;
                    ourQueue.push('D');
                }
            } else {
                if(rBanned){
                    rCount--;
                    rBanned--;
                } else {
                    dBanned++;
                    ourQueue.push('R');
                }
            }
        }
        return rCount ? "Radiant" : "Dire";
    }
};