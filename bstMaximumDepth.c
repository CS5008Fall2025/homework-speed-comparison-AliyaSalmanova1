/**
 * Maximum Depth of Binary Tree
 *
 * @author: Aliya Salmanova
 * @class: CS 5008
 * @term: Fall 2025
 */

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

/*
I compared my solution to other solutions on leetcode. 
The solutions I saw look a bit differently than mine, as it is possible to solve this without a helper function. 
However, the logic of the solutions are similar. 

This problem helped me practice thinking recursively. 
*/
