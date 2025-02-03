class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n<=0)
        return n;

        int max_i_length=1;
        int max_d_length=1;
        int current_i=1;
        int current_d=1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]){
                max_i_length=max(max_i_length,current_i);
                max_d_length=max(max_d_length,current_d);
                current_i=1;
                current_d=1;
            }
            else if(nums[i+1]>nums[i]){
               
                max_d_length=max(max_d_length,current_d);
                current_i++;;
                current_d=1;
            }
            else{
                max_i_length=max(max_i_length,current_i);
                current_i=1;
                current_d++;
            }
            
        }

        max_i_length=max(max_i_length,current_i);
        max_d_length=max(max_d_length,current_d);

        

        return max(max_i_length,max_d_length);
        
    }
};