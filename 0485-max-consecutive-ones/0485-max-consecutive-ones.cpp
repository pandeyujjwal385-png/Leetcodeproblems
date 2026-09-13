class Solution {
public://sliding window approach
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int current=0;
        int maxsum=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==1){
                current++;
                maxsum= max(current,maxsum);
            }
            else{
                current=0;
            }
        }
        return maxsum;
    }
};