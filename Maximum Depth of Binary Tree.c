 int altura (struct TreeNode* root){

    if (root == NULL){
        return -1;
    }

    int esq = altura (root->left);
    int dir = altura (root->right);

    if (esq > dir){
        return esq + 1;
    }else{
        return dir + 1;
    }

 }
int maxDepth(struct TreeNode* root) {
    
    int  a = 1 + altura(root);

    return a;

}