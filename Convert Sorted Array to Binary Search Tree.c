/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Função auxiliar para calcular a altura de um nó

int height(struct TreeNode *node) {
    if (node == NULL)
        return 0;
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Função para calcular o fator de balanceamento
int balanceFactor(struct TreeNode *node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Rotação simples à direita
struct TreeNode *rotateRight(struct TreeNode *y) {
    struct TreeNode *x = y->left;
    struct TreeNode *T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    return x;
}

// Rotação simples à esquerda
struct TreeNode *rotateLeft(struct TreeNode *x) {
    struct TreeNode *y = x->right;
    struct TreeNode *T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    return y;
}

// Função principal de inserção na AVL
struct TreeNode *insertAVL(struct TreeNode *node, int val) {
    // 1. Inserção normal de BST
    if (node == NULL) {
        struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < node->val)
        node->left = insertAVL(node->left, val);
    else if (val > node->val)
        node->right = insertAVL(node->right, val);
    else // Valores iguais não são permitidos na BST
        return node;

    // 2. Obtém o fator de balanceamento deste nó
    int balance = balanceFactor(node);

    // 3. Se o nó ficar desbalanceado, então há 4 casos

    // Caso Esquerda-Esquerda
    if (balance > 1 && val < node->left->val)
        return rotateRight(node);

    // Caso Direita-Direita
    if (balance < -1 && val > node->right->val)
        return rotateLeft(node);

    // Caso Esquerda-Direita
    if (balance > 1 && val > node->left->val) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Caso Direita-Esquerda
    if (balance < -1 && val < node->right->val) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Retorna o ponteiro do nó (inalterado)
    return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    struct TreeNode* raiz = NULL;

    if (numsSize == 0){
        return raiz;
    }

    for (int i=0;i<numsSize;i++){
        raiz = insertAVL(raiz,nums[i]);
    }
    return raiz;
}