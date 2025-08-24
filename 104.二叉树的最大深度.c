int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    else 
        return 1 + fmax(maxDepth(root->left),maxDepth(root->right));
    
}
