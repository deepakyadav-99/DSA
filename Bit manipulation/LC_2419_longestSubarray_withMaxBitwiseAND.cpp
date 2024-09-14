/*
    Leetcode Link : https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/
*/

//overall TC : O(nums.size)==O(N)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        /* 
            observation: bitwise AND of any two numbers will be equal to less than those numbers
            it never can be more than those numbers.
            So in an array , max value of array is going to be our maximum possible bitwise AND,
            and then the questions boils down to finding the longest streak of max value. 
        */
        int maxVal = 0;
        int result = 0;
        int streak = 0;

        for(auto it : nums){
            if(it > maxVal){
                maxVal = it;
                result = 0; 
                streak = 1; //resetting the streak of maxVal
            }

            else if(it == maxVal){
                streak ++;
            }

            else{
                streak = 0;
            }

            result = max(result, streak);
        }


        return result;


        // this solution also correct but above is much more observative

        // int k = nums[0];
        // for(int i=1; i<nums.size(); i++){
        //     k = max(k, nums[i]);
        // }

        // int i=0;
        // int Longest = 1;
        // for(int j=0; j<nums.size(); j++){
        //     int bitwiseAND = nums[i] & nums[j];
            
        //     if(bitwiseAND == k){
        //         int length = j-i+1;
        //         Longest = max(Longest, length);
        //     }
        //     else {
        //         i = j+1;
        //     }
        // }
        // return Longest;
    }
};