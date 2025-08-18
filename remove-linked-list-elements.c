#include <stdlib.h>

struct ListNode* cria(){
    struct ListNode* nova = malloc (sizeof(struct ListNode));

    nova->next = NULL;

    return nova;
}

void fim (struct ListNode* head,int x){
    struct ListNode* new = cria();
    new->val = x;

    struct ListNode*p = head;

    while (p->next != NULL){
        p = p->next;
    }

    p->next =  new;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
     if (head == NULL) return NULL;
    struct ListNode* nova = NULL;
    struct ListNode* p = head;


    while (p != NULL){
        if (p->val != val){

            if (nova == NULL){
                nova = cria();
                nova->val = p->val;
                
            }else{
                fim(nova,p->val);
            }
            
        }

        p = p->next;
    }


    return nova;
}