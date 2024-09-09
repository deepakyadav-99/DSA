/*
   Leetcode Link : https://leetcode.com/problems/spiral-matrix-iv/description/
 */

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;

        vector<vector<int>> matrix(m, vector<int> (n, -1)); 

        while(top <= bottom && left <= right && head != NULL){
            //traverse top row
            for(int i=left; i<=right; i++){
                if(head != NULL){
                    matrix[top][i] = head->val;
                    head = head->next;
                }
            }
            top++;

            //traverse right col
            for(int i=top; i<=bottom; i++){
                if(head != NULL){
                    matrix[i][right] = head->val;
                    head = head->next;
                }
            }
            right--;

            //traverse bottom row
            if(top<=bottom){
                for(int i=right; i>=left; i--){
                   if(head != NULL){
                    matrix[bottom][i] = head->val;
                    head = head->next;
                   } 
                } 
            }
            bottom--;

            //traverse left col
            if(left<=right){
                for(int i=bottom; i>=top; i--){
                    if(head != NULL){
                        matrix[i][left] = head->val;
                        head = head->next;
                    }
                }
            }
            left++;

        }

        return matrix;

    }
};