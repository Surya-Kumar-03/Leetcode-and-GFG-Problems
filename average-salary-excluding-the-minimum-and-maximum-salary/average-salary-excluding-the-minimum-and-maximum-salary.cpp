class Solution {
public:
    double average(vector<int>& salary) {
        int minEle = salary[0];
        int maxEle = salary[0];
        int sum = salary[0];
        for(int i = 1; i < salary.size(); i++){
            sum += salary[i];
            cout << sum << ' '<< minEle <<' ' << maxEle << endl;
            if(salary[i] < minEle){
                minEle = salary[i];
            }
            if(salary[i] > maxEle) {
                maxEle = salary[i];
            }
        }
        return (double) (sum - (minEle + maxEle))/ (salary.size() - 2);
    }
};