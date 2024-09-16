/*
    Leetcode Link : https://leetcode.com/problems/minimum-time-difference/description/
*/


class Solution {
public:
    //overall TC: O(nlogn), space = O(n)
    int findMinDifference(vector<string>& timePoints) {
        //step 1 : convert the time into minutes
        int n = timePoints.size();
        vector<int> minutes(n);
        for(int i=0; i<n; i++){
          string time = timePoints[i];

          string hourSubstr = time.substr(0,2);//HH
          string mintSubstr = time.substr(3);//MM

          int hourInt = stoi(hourSubstr);
          int mintInt = stoi(mintSubstr);

          minutes[i] = hourInt*60 + mintInt;
        }
     
        sort(minutes.begin(), minutes.end());
        int mini = INT_MAX;
        for(int i=1; i<n; i++){
            int diff = minutes[i] - minutes[i-1];
            mini = min(mini, diff); 
        }
        int wrap_around_diff = 1440 - minutes[n-1] + minutes[0]; //closest can be possible to 00:00 , first and last element;
        mini = min(mini, wrap_around_diff);

        return mini;
    }
};