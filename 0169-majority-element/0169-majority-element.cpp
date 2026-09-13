class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num]++;
        }
        int max=0;
        int maxElem=-1;
        for (const auto& pair : freq) {
        if (pair.second > max) {
            max = pair.second;
            maxElem = pair.first;
        }
    }
    return maxElem;
    }
};  //space complexity is not optimised