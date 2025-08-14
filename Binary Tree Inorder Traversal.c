void insere(int **array, int* returnSize, int x) {
    *returnSize += 1;
    *array = realloc(*array, *returnSize * sizeof(int));
    (*array)[(*returnSize) - 1] = x;
}

void percorre(struct TreeNode* root, int **array, int* returnSize) {
    if (root == NULL) {
        return;
    }
    percorre(root->left, array, returnSize);
    insere(array, returnSize, root->val);
    percorre(root->right, array, returnSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int *array = NULL;
    *returnSize = 0;
    percorre(root, &array, returnSize);
    return array;
}