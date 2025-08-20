#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Função de comparação para o qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

struct ListNode* insere(struct ListNode* Node, int x) {
    struct ListNode *new = malloc(sizeof(struct ListNode));
    new->next = NULL;
    new->val = x;
    if (Node == NULL) {
        return new;
    }
    struct ListNode* p = Node;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
    return Node;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    int size = 0 , index =0;

    if (listsSize == 0) {
        return NULL;
    }

    struct ListNode* retorna = NULL;

    for (int i = 0; i < listsSize; i++) {
        struct ListNode *p = lists[i];
        while (p != NULL) {
           size++;
           p = p->next;
        }
    }

    int *array = malloc (size *  sizeof(int));

        for (int i = 0; i < listsSize; i++) {
        struct ListNode *p = lists[i];
        while (p != NULL) {

           array[index] = p->val;

           p = p->next;
           index++;
        }
    }

    qsort(array, size, sizeof(int), compare);
    for (int i = 0; i < size; i++) {
        retorna = insere(retorna, array[i]);
    }
    free(array);
    return retorna;
}