class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> seen;
        int maxlength=0,start=0;
        for(int end=0;end<s.length();end++)
        {
            if(seen.find(s[end])!=seen.end() && seen[s[end]]>=start)
            {
                start=seen[s[end]]+1;
            }
            maxlength=max(maxlength,end-start+1);
            seen[s[end]]=end;
        }
        return maxlength;
    }
};