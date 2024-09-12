class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        priority_queue<int> p;
        for(int i:people)
        {
            p.push(i);
        }
        deque<int> dq;
        while(!p.empty())
        {  int k=p.top();
           p.pop();
           dq.push_back(k);
        }
        
        int count=0;
        while(!dq.empty())
        {
            int k=limit;
            k-=dq.front();
            dq.pop_front();
            if(k>0 && !dq.empty() && dq.back()<=k)
            dq.pop_back();
            count++;
        }
        return count;
    }
};