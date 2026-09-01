class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=1;
        int m=0;
        int cm=1;
        int n= nums.size();
        while(cm<n){
            if(nums[cm]==nums[cm-1]){
                cm++;
                continue;
            }
               if(nums[cm]!=nums[cm-1]){
                nums[m+1]=nums[cm];
                m++;
                cm++;
                res++;
        }
        }
        return res;
    }
};