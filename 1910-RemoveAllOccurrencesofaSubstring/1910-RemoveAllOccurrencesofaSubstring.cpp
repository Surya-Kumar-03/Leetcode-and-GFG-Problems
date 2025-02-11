class Solution {
public:
    bool canRemovePart(stack<char>& pending, string& part) {
        stack<char> copy = pending;
        int pSize = part.size();

        for (int pi = pSize - 1; pi >= 0; pi--) {
            if (copy.top() != part[pi]) {
                return false;
            }

            copy.pop();
        }

        return true;
    }

    string removeOccurrences(string s, string part) {
        stack<char> pending;
        int sSize = s.size();
        int pSize = part.size();

        for (int si = 0; si < sSize; si++) {
            pending.push(s[si]);

            if (pending.size() >= pSize && canRemovePart(pending, part)) {
                for (int pi = 0; pi < pSize; pi++) {
                    pending.pop();
                }
            }
        }

        string output = "";
        while (pending.empty() == false) {
            output = pending.top() + output;
            pending.pop();
        }
        
        return output;
    }
};