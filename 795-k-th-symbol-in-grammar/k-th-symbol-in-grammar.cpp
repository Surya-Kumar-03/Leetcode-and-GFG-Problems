class Solution {
public:
    int recursion(int n, int k) {
        if (n == 1) {
            return 0;
        }

        int totalElements = pow(2, (n - 1));
        int halfElements = totalElements / 2;

        // return the opposite of the other half
        if (k > halfElements) {
            return !kthGrammar(n, k - halfElements);
        }

        return recursion(n - 1, k);
    }

    int kthGrammar(int n, int k) {
        return recursion(n, k);
    }
};

// class Solution {
// public:
//     int kth(int n, string cur, int tn, int tk) {
//         if(n == tn) {
//             return cur[tk - 1] - '0';
//         }
//         string newCur = "";
//         int cn = cur.size();
//         for(int i = 0; i < cn; i++) {
//             if(cur[i] == '0') {
//                 newCur += "01";
//             } else {
//                 newCur += "10";
//             }
//         }
//         return kth(n + 1, newCur, tn, tk);
//     }

//     int kthGrammar(int n, int k) {
//         return kth(1, "0", n, k);
//     }
// };