/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<vector<NestedInteger>::iterator> begins, ends;
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }
    
    int next() {
        if(!hasNext()) {
            return -1;
        }
        int ans = begins.top()->getInteger();
        begins.top()++;
        return ans;
    }
    
    bool hasNext() {
        while(!begins.empty()) {
            if(begins.top() == ends.top()) {
                begins.pop(), ends.pop(); //This Vector is Finished
            } else {
                auto itr = begins.top();
                if(itr->isInteger()) {
                    return true;
                } else {
                    begins.top()++;
                    auto begin = itr->getList().begin();
                    auto end = itr->getList().end();
                    begins.push(begin);
                    ends.push(end);
                }
            }
        }   
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */