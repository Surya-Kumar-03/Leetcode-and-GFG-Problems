class Solution
{
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int minLength = INT_MAX;
        int start = 0;
        unordered_map<char,int> targetCharCount;
        for(auto it: t)
            targetCharCount[it]++;
        int missingChars = targetCharCount.size();

        if(targetCharCount.find(s[right]) != targetCharCount.end()){
            targetCharCount[s[right]]--;
            if(targetCharCount[s[right]] == 0)
                missingChars--;
        }

        while(right < s.length()){
            if(missingChars > 0){
                right++;
                if(targetCharCount.find(s[right]) != targetCharCount.end()){
                    targetCharCount[s[right]]--;
                    if(targetCharCount[s[right]] == 0)
                        missingChars--;
                }
            }
            else if(missingChars == 0){
                if(right - left + 1 < minLength){
                    minLength = right - left + 1;
                    start = left;
                }
                while(missingChars == 0){
                    if(targetCharCount.find(s[left]) != targetCharCount.end()){
                        targetCharCount[s[left]]++;
                        if(targetCharCount[s[left]] == 1){
                            missingChars++;
                            if(minLength > right - left + 1){
                                minLength = right - left + 1;
                                start = left;
                            }
                        }
                        left++;
                    }
                    else
                        left++;
                }
            }
        }
        string result = "";
        if(minLength != INT_MAX)
            return result.append(s.substr(start, minLength));
        else
            return result;
    }
};