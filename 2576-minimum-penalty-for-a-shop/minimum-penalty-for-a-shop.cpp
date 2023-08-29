class Solution {
public:
    int bestClosingTime(string customers) {
        int max_score = 0, score = 0, best_hour = -1;
        for(int i = 0; i < customers.size(); ++i) {
            score += (customers[i] == 'Y') ? 1 : -1;
            if(score > max_score) {
                max_score = score;
                best_hour = i;
            }
        }
        return best_hour + 1;
    }
};

// class Solution {
// public:
//     int bestClosingTime(string customers) {
//         int yCount = 0;
//         int n = customers.size();
//         vector<int> yCounts(n);
//         for(int i = n - 1; i >= 0; i--) {
//             if(customers[i] == 'Y') yCount++;
//             yCounts[i] = yCount;
//         }

//         int nCount = 0;
//         int minPenalty = yCounts[0];
//         int minHour = 0;
//         for(int i = 0; i < n - 1; i++) {   
//             if(customers[i] == 'N') nCount++;
//             int curPenalty = yCounts[i + 1] + nCount;
//             if(curPenalty < minPenalty) {
//                 minPenalty = curPenalty;
//                 minHour = i + 1;
//             }
//         }
//         if(nCount < minPenalty) { // for YYYY then close after last hour
//             minHour = n;
//         }
//         return minHour;
//     }
// };