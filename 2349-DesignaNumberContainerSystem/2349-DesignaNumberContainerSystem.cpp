class NumberContainers {
public:
    unordered_map<int, int> indexToNumbersMap;
    unordered_map<int, set<int>> numbersToSmallestIndexMap;

    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (indexToNumbersMap.find(index) != indexToNumbersMap.end()) {
            int previousNumber = indexToNumbersMap[index];
            numbersToSmallestIndexMap[previousNumber].erase(index);
        } 
        
        indexToNumbersMap[index] = number;
        numbersToSmallestIndexMap[number].insert(index);
    }
    
    int find(int number) {
        if (numbersToSmallestIndexMap.find(number) != numbersToSmallestIndexMap.end()) {
            for (auto ele : numbersToSmallestIndexMap[number]) {
                return ele;
            }
        } else {
            return -1;
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */