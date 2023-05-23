class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> ourPq;
    int kGlobal;
    KthLargest(int k, vector<int>& nums) {
        kGlobal = k; //passing to global variable for function access
        //keeping a min heap of k size (top element will kth largest)
        for(int i = 0; i < nums.size(); i++)
        {
            ourPq.push(nums[i]);
            if(ourPq.size() > k) ourPq.pop();
        }
    }
    
    int add(int val) {
        //push new value
        ourPq.push(val);
        //pop if size greater than k
        if(ourPq.size() > kGlobal) ourPq.pop();
        return ourPq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */