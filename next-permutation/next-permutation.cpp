class Solution {
public:
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }

template <typename A>
void __print(const A &x) {
    bool first = true;
    cout << '{';
    for (const auto &i : x) {
        cout << (first ? "" : ", ");
        __print(i);
        first = false;
    }
    cout << '}';
}

template <typename A, typename B>
void __print(const pair<A, B> &p) {
    cout << '(';
    __print(p.first);
    cout << ", ";
    __print(p.second);
    cout << ')';
}

template <typename... A>
void __print(const tuple<A...> &t) {
    bool first = true;
    cout << '(';
    apply([&first](const auto &...args) {
        ((cout << (first ? "" : ", "), __print(args)), ...);
        first = false;
    }, t);
    cout << ')';
}

template <typename T>
void __print(stack<T> s) {
    vector<T> debugVector;
    while (!s.empty()) {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    __print(debugVector);
}

template <typename T>
void __print(queue<T> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}

template <typename T, typename... U>
void __print(priority_queue<T, U...> q) {
    vector<T> debugVector;
    while (!q.empty()) {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}

void _print() { cout << "]\n"; }

template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T) {
    __print(H);
    if (sizeof...(T))
        cout << ", ";
    _print(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...)                                                 \
    cout << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define debug(...)
#endif

    void nextPermutation(vector<int>& nums) {
        int breakIndex = -1;
        int size = nums.size();
        int i = size - 1;
        int curMax = INT_MIN;
        while(i >= 0) {
            if(nums[i] < curMax) {
                breakIndex = i;
                break;
            } else curMax = nums[i];
            i--;
        }
        debug(breakIndex);
        if(breakIndex == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            i = breakIndex + 1;
            int justBigger = INT_MAX;
            int justBiggerIndex = breakIndex;
            while(i < size) {
                if(nums[i] > nums[breakIndex] && nums[i] < justBigger) {
                    justBiggerIndex = i;
                } 
                i++;
            }
            swap(nums[breakIndex], nums[justBiggerIndex]);
            debug(nums);
            reverse(nums.begin() + breakIndex + 1, nums.end());
        }
    }
};