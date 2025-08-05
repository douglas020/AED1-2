/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int altura(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }

    int esq = altura(root->left);
    int dir = altura(root->right);

    if (esq > dir) {
        return esq + 1;
    } else {
        return dir + 1;
    }
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int esq = altura (root->left);
    int dir = altura (root->right);

    int fb = esq - dir;

    if (fb > 1 || fb < -1 ){
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}