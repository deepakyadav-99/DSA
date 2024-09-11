/*
    Leetcode link : https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
*/

//overall time complexity is O(log N)
// bcox xor is constant time operator , and we are doing right shift 
// means always dividing number by 2
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int xorr = start^goal;
        int count = 0;
        while(xorr){
            if(xorr & 1) count++;
            xorr = xorr>>1;
        }
        return count;
    }
};