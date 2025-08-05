/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct no {
    int valor;
    struct no *direita, *esquerda;
} NoArv;

void insere(NoArv **raiz, int x) {
    NoArv *aux = *raiz;

    while (aux) {
        if (x < aux->valor) {
            raiz = &aux->esquerda;
        } else {
            raiz = &aux->direita;
        }
        aux = *raiz;
    }

    aux = malloc(sizeof(NoArv));
    aux->valor = x;
    aux->direita = NULL;
    aux->esquerda = NULL;
    *raiz = aux;
}

void insere_lista(struct ListNode** head, int x) {  // Mudei para receber double pointer
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = x;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
        return;
    }

    struct ListNode* p = *head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
}

void insere_ordem(NoArv *raiz, struct ListNode** head) {  // Mudei para double pointer
    if (raiz == NULL) {
        return;
    }

    insere_ordem(raiz->esquerda, head);
    insere_lista(head, raiz->valor);  // Passa o endereço do ponteiro
    insere_ordem(raiz->direita, head);
}

void libera_arvore(NoArv *raiz) {
    if (raiz == NULL) {
        return;
    }
    libera_arvore(raiz->esquerda);
    libera_arvore(raiz->direita);
    free(raiz);
}

struct ListNode* insertionSortList(struct ListNode* head) {
    NoArv *arvore = NULL;
    struct ListNode *retorna = NULL;  // Inicializa como NULL

    // Constroi a árvore com os valores da lista
    struct ListNode *current = head;
    while (current != NULL) {
        insere(&arvore, current->val);
        current = current->next;
    }

    // Constrói a lista ordenada a partir da árvore
    insere_ordem(arvore, &retorna);  // Passa o endereço de retorna

    // Libera a memória da árvore
    libera_arvore(arvore);

    return retorna;
}