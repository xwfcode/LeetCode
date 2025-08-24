// struct TreeNode* invertTree(struct TreeNode* root) {
//     if(root == NULL)
//         return NULL;
//     if((root->left == NULL) && (root->right == NULL))
//         return root;
//     struct TreeNode* TmpNode;
//     TmpNode = root->left;
//     root->left = root->right;
//     root->right = TmpNode;
//     invertTree(root->left);
//     invertTree(root->right);
//     return root;
// }
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
        return NULL;
    struct TreeNode* left = invertTree(root->left);
    struct TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}