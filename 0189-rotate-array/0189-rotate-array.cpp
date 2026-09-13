class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        int d= k%n;
        vector<int>temp;

        for(int i=0;i<d;i++){
            temp.push_back(nums[n-d+i]);
        }
        for(int i= n-d-1;i>=0;i--){
            nums[i+d]=nums[i];
        }
        for(int i=0; i<d;i++){
            nums[i]=temp[i];
        }


    }
};