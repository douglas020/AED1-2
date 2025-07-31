#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    int valor;
    struct no *direita, *esquerda;

}NoArv;

NoArv* inserir_versao_1(NoArv *raiz,int x){

    if (raiz == NULL){

        NoArv *new = malloc (sizeof (NoArv));

        new->valor = x;

        new->esquerda = NULL;

        new->direita = NULL;

        return new;
    }else{

        if(x < raiz->valor){

            raiz->esquerda = inserir_versao_1(raiz->esquerda,x);

        }else{

            raiz->direita = inserir_versao_1(raiz->direita,x);

        }

        return raiz;
    }
}

void inserir_versao_2(NoArv **raiz , int x){

    if (*raiz == NULL){

        *raiz = malloc (sizeof(NoArv));

        (*raiz)->valor = x;

        (*raiz)->esquerda = NULL;

        (*raiz)->direita = NULL;

    }else{

        if (x < (*raiz)->valor){

            inserir_versao_2(& ( (*raiz)->esquerda) , x  );
        }else{

            inserir_versao_2(& ( (*raiz)->direita) , x);
        }


    }
}

void inserir_versao_3(NoArv **raiz , int x){

    NoArv *aux = *raiz;

    while (aux)
    {
       if (x < aux->valor ){
            raiz = &aux->esquerda;
       }else{
            raiz = &aux->direita;
       }

       aux = *raiz;
    }

    aux = malloc (sizeof(NoArv));
    aux->valor = x;
    aux->direita = NULL;
    aux->esquerda = NULL;
    *raiz = aux;
}

void imprimir_versao_1(NoArv *raiz){

    if (raiz != NULL){
        printf ("%d ",raiz->valor);

        imprimir_versao_1 (raiz->esquerda);
        imprimir_versao_1 (raiz->direita);
    }

}

void imprimir_versao_2(NoArv *raiz){

    if (raiz != NULL){

        imprimir_versao_2 (raiz->esquerda);

        printf ("%d ",raiz->valor);

        imprimir_versao_2 (raiz->direita);

    }

}

NoArv* buscar_versao_1 (NoArv *raiz , int x){

    if (raiz == NULL){
        return NULL;
    }else{

        if (raiz->valor == x){

            return raiz;
        }

        else if (raiz->valor < x ){

            return buscar_versao_1 (raiz->esquerda , x);

        }else{

            return buscar_versao_1 (raiz->direita , x);
        }

    }
}

NoArv* buscar_versao_2 (NoArv *raiz , int x){

    while (raiz != NULL){

        if (x < raiz->valor ){

            raiz = raiz->esquerda;

        }else if (x > raiz->direita){

            raiz = raiz->direita;
        }else{
            return raiz;
        }

    }
    return NULL;
}

int quatidade_nos (NoArv *raiz){

    if (raiz == NULL){
        return 0;
    }else{
        return 1 + quatidade_nos (raiz->esquerda) + quatidade_nos (raiz->direita);
    }
}

int altura (NoArv *raiz){

    if (raiz == NULL){
        return -1;
    }else{

        int esq = altura (raiz->esquerda);

        int dir = altura (raiz->direita);
        
        if (esq > dir ){

            return esq + 1;
        }else{

            return dir + 1;
        }
         
    }
}

int main (){

    NoArv *raiz = NULL;

    int opcao,valor;

    do
    {
        printf ("1: inserir \n 2: imprimir \n 0: Sair \n");
        scanf ("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf ("Digite um valor \n");
            scanf ("%d",&valor);

            inserir_versao_3(&raiz,valor);
            break;
        case 2:

            imprimir_versao_2 (raiz);

            printf ("\n");

            break;
        default:
            if (opcao != 0 ){
                printf ("Valor invalido \n");

            }
            break;
        }


    } while (opcao != 0);

}