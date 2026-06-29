/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        

        ListNode* temp=list1;

        ListNode* start;
        int c=1;
        while(temp!=NULL){
            if(c==a){
                start=temp;
            }

            if(c==b+1){
                break;
            }
            c++;
            temp=temp->next;
        }
        temp=temp->next;

        start->next=list2;
        ListNode* temp1=list2;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }

        temp1->next=temp;

        return list1;
    }
};