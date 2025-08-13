void insere(int x, struct ListNode **nodo) {
    struct ListNode *new = malloc(sizeof(struct ListNode));
    new->val = x;
    new->next = NULL;
    if (*nodo == NULL) {
        *nodo = new;
        return;
    }
    struct ListNode *p = *nodo;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
   
    bool flag = false;
    int soma = 0;
    int aux;
    struct ListNode *p1 = l1,*p2 =l2;
    struct ListNode *retorna = NULL;


    while (p1 != NULL || p2 != NULL){
        
        soma = 0;

        if (p1 != NULL){

            soma = p1->val;

            p1 = p1->next;
        }

        if (p2 != NULL){

          soma += p2->val;

            p2 = p2->next;
        }

        if (soma < 10 ){

            if (flag == false){

                insere(soma,&retorna);

            }else{

                soma += 1;

                if (soma >= 10){

                    aux = soma % 10;

                    insere(aux,&retorna);

                    flag = true;
                }else{

                    insere(soma,&retorna);

                    flag = false;
                }

            }

        }else{

            if (flag == true){

                soma += 1;

                aux = soma % 10;

                insere(aux,&retorna);

            }else{

                aux = soma % 10;

                insere(aux,&retorna);

                flag = true;

            }

        }
    }
    
    if (flag == true){

        insere(1,&retorna);
    }
 

 return retorna;
}