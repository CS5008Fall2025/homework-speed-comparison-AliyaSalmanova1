/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepthHelper(struct TreeNode* node, int depth){
    if (node == NULL) return depth;
    //find the max of the left side of the tree
    int maxLeft = maxDepthHelper(node->left, depth + 1);
    //find the max of the right side of the tree
    int maxRight = maxDepthHelper(node->right, depth + 1);

    //return the greater max depth of the sides
    if (maxLeft > maxRight) return maxLeft;
    return maxRight;
    
}

int maxDepth(struct TreeNode* root) {
    return maxDepthHelper(root, 0);
}

//I tested this on leetcode 
