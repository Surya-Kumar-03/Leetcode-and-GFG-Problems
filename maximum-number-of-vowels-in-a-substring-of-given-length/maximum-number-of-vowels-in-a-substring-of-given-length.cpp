class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
        else
            return false;
    }
    int maxVowels(string s, int k)
    {
        int curVowel = 0;
        int j;
        for (j = 0; j < k; j++)
        {
            if (isVowel(s[j]))
            {
                curVowel++;
            }
        }
        int maxVowel = curVowel;
        int i = 0;
        j = k;
        while (j < s.size())
        {
            if (isVowel(s[i]))
            {
                curVowel--;
            }

            if (isVowel(s[j]))
            {
                curVowel++;
                maxVowel = max(maxVowel, curVowel);
            }

            i++, j++;
        }
        return maxVowel;
    }
};