class Solution {
public:
    int getLucky(string s, int k) {
        string result="";
        for(char c:s)
        {
            if(int(c)>96)
            result=to_string(c-'a'+1)+result;
            else
            result=c+result;
        }
        int r;
         r=0;
        for(char c:result)
        {
                r+=c-'0';
        }
        if(k==1)
        return r;
        for(int i=0;i<k-1;i++)
        {   
            int p=0;
            while(r>0)
            {
                p+=r%10;
                r=r/10;
            }
            r=p;
        }
        return r;
    }
};