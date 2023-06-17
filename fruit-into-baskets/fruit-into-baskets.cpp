class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> basket; // stores fruit type with its count
        int i = 0, j = 0;
        int n = fruits.size();
        int maxFruits = 0;
        while(j < n) {
            basket[fruits[j]]++; // add the current fruit in basket
            while(basket.size() > 2) { //more fruit types are there so remove
                basket[fruits[i]]--;
                if(basket[fruits[i]] == 0) basket.erase(fruits[i]);
                i++;
            }
            maxFruits = max(maxFruits, j - i + 1);
            j++;
        }
        return maxFruits;
    }
};