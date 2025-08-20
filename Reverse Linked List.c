struct ListNode* insere (struct ListNode* node , int x){

    struct ListNode* new = malloc (sizeof(struct ListNode));
    new->val = x;
    
    if (node == NULL ){
        new->next = NULL;
        return new;
    }

    new->next = node;

    return new;
}

struct ListNode* reverseList(struct ListNode* head) {
    
    if (head == NULL){
        return NULL;
    }

    struct ListNode* retorna = NULL;

    while (head != NULL){
        
        retorna = insere(retorna,head->val);
        head = head->next;
    }

    return retorna;
}   