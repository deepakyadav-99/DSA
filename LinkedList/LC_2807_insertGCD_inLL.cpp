/*
    Leetcode Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
*/

//overall tc = O(N)
class Solution {
private:
    // gcd best logic with TC = log(phi)min(a,b)
    // eucledian algo : gcd(a,b) == gcd(a-b, b) if(a>b)
    // modified algo  : gcd(a,b) == gcd(a%b, b) if(a>b)
    int gcd(int a, int b){

        while(a > 0 && b > 0){
            if(a>b) a = a%b;
            else b = b%a;
        }

        if(a == 0) return b;
        return a; 
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next == NULL) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while(curr != NULL){
            int hcf = gcd(prev->val,curr->val);
            ListNode* newNode = new ListNode(hcf);
            newNode->next = curr;
            prev ->next = newNode;
            prev = curr;
            curr = curr->next;
        }
        return head;

    }
};