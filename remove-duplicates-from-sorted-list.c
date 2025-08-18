#include <stdio.h>
#include <stdlib.h>

struct ListNode* cria (int x){
    struct ListNode *nova = malloc (sizeof(struct ListNode));
    nova->val = x;
    nova->next = NULL;

    return nova;
}

void inseri (int x,struct ListNode* list){
    struct ListNode  *nova = cria(x);

    struct ListNode *p = list;
    
    while (p->next != NULL){
        p = p->next;
    }

    p->next = nova;
}


struct ListNode* deleteDuplicates(struct ListNode* head) {
   if (head == NULL || head->next == NULL) {
        return head;
    } 
    struct ListNode *nova= cria(head->val);

    

    struct ListNode *p = head;
    struct ListNode *pp = p->next;

    while (pp != NULL){

        if(p->val != pp->val ){

            inseri(pp->val,nova);

        }

        p = pp;

        pp = pp->next;

    }

    return nova;
}