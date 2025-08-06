/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int somar(struct TreeNode* root, int x) {
    if (root == NULL) {
        return 0;
    }

    int soma = 0;

    if (x <= root->val) {
        soma += root->val;
    }

    soma += somar(root->right, x);
    soma += somar(root->left, x);

    return soma;
}

void inserir(struct TreeNode** root, int x) {
    struct TreeNode** aux = root;  // Use double pointer to track insertion point

    while (*aux) {
        if (x < (*aux)->val) {
            aux = &(*aux)->left;
        } else {
            aux = &(*aux)->right;
        }
    }

    *aux = malloc(sizeof(struct TreeNode));
    (*aux)->val = x;
    (*aux)->left = NULL;
    (*aux)->right = NULL;
}

void copia(struct TreeNode** retornar, struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
 
    inserir(retornar, root->val);
    copia(retornar, root->left);
    copia(retornar, root->right);
}

void soma_elementos(struct TreeNode* retornar, struct TreeNode* root) {
    if (retornar == NULL) {  // Check retornar instead of root
        return;
    }

    int aux = somar(root, retornar->val);
    retornar->val = aux;

    soma_elementos(retornar->left, root);
    soma_elementos(retornar->right, root);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* retornar = NULL;
    copia(&retornar, root);
    soma_elementos(retornar, root);

    return retornar;
}