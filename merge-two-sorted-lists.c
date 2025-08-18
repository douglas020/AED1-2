/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void inserir(struct ListNode** list, int x){
    struct ListNode *nova = malloc (sizeof(struct ListNode));
    nova->val = x;
    nova->next = NULL;
    if (*list == NULL) {
        *list = nova;
    } else {
        struct ListNode *p = *list;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = nova;
    }
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *nova = NULL;
    while (list1 != NULL && list2 != NULL){
        if (list1->val <= list2->val){
            inserir(&nova, list1->val);
            list1 = list1->next;
        }else{
            inserir(&nova, list2->val);
            list2 = list2->next;
        }
    }
    while (list1 != NULL){
        inserir(&nova, list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL){
        inserir(&nova, list2->val);
        list2 = list2->next;
    }
    return nova;
}
