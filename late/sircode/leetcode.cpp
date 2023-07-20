/**
 * Definition for singly-linked list->
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void insert(int data,ListListNode *tl)
    {
        ListNode *n=new ListNode;
        ListNode *t;
        t=start;
        int i;
        n->item=data;
        n->next=NULL;
        if(t!=NULL)
        {
            for(i=0;t->next;i++)
                t=t->next;
            t->next=n;
        }
        else
        {   
            start=n;
        }
        
        
    }
    ListListNode* mergeTwoLists(ListListNode* list1, ListListNode* list2) {
     ListListNode *l1=list1,*l2=list2,*l3=NULL;
     while(l1 && l2)
     {
         if(l1->val>=l2->val)
         {
            insert(l1->val,l3);
            l1=l1->next;
         }
         else
        {
            insert(l2->val,l3);
            l2=l2->next;
        }
     }
     while(l1)
    {
        insert(l1->val,l3);
        l1=l1->next;
    }
    while(l2)
    {
        insert(l2->val,l3);
            l2=l2->next;
    }


    }
};