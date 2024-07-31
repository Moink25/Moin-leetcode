class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> result;
    //      std::sort(strs.begin(), strs.end(), [](const std::string &a, const std::string &b) {
    //     return a.size() < b.size();
    // });
    //     map<char,int> count_start;
    //     string s="";
    //     for(int i=0;i<strs.size();i++)
    //     {   
            
    //         s=strs[i];
    //         for (char c : strs[i]) {
    //             count_start[c]++;
    //         }
    //         map<char,int> count_second;
    //         vector<string> r;
    //         // int count=0;
    //         r.push_back(strs[i]);
    //         for(int j=i+1;j<strs.size() && strs[j].length()==strs[i].length();j++)
    //         {   s=strs[j];
    //             for (char c : strs[j]) {
    //             count_second[c]++;
    //         }

    //             if(count_start==count_second)
    //             {
                    
    //                 r.push_back(s);
    //                 strs.erase(strs.begin()+j);
    //                 j--;
    //             }
    //             count_second.clear();
    //         }
            
            
            
    //         count_start.clear();
    //         result.push_back(r);
    //     }
    //     return result;

    vector<vector<string>> result;
    unordered_map<string,vector<string>> p;
    for(auto a:strs)
    {
        string w=a;
        sort(w.begin(),w.end());
        p[w].push_back(a);
    }

    for(auto x:p)
    result.push_back(x.second);

    return result;
    }
};