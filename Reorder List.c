struct ListNode* insere (struct ListNode* head , int x){

    struct ListNode* new = malloc (sizeof (struct ListNode));
    new->val = x;

    if (head == NULL){
        new->next = NULL;
        return new;
    }

    new->next = head;

    return new;
}
void reorderList(struct ListNode* head) {
  
    if (head == NULL || head->next == NULL){
        return;
    }

    struct ListNode* p , *temp , *inverso = NULL;
    bool flag = false;
    int size = 0;

    p = head;

    while (p != NULL){
        size++;
        inverso = insere(inverso,p->val);
        p = p->next;
    }

    p = head;

    for (int i = 0 ; i < size -1 ; i++){

        if (flag == false ){

            temp = p->next;

            p->next = inverso;

            inverso = inverso->next;

            flag = true;

        }else{

            p->next = temp;

            flag = false;


        }

        p = p->next;

    }

    p->next = NULL;
}