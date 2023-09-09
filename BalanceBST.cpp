//DSW Algorithm
int bstToVine(TreeNode* grand)
{
    int count = 0;
 
    // Make tmp pointer to traverse
    // and right flatten the given BST.
    TreeNode* tmp = grand->right;
 
    // Traverse until tmp becomes NULL
    while (tmp) {
         
        // If left exist for node
        // pointed by tmp then
        // right rotate it.
        if (tmp->left) {
            TreeNode* oldTmp = tmp;
            tmp = tmp->left;
            oldTmp->left = tmp->right;
            tmp->right = oldTmp;
            grand->right = tmp;
        }
 
        // If left dont exists
        // add 1 to count and
        // traverse further right to
        // flatten remaining BST.
        else {
            count++;
            grand = tmp;
            tmp = tmp->right;
        }
    }
 
    return count;
}
 
// Function to compress given tree
// with its root as grand->right.
void compress(TreeNode* grand, int m)
{
    // Make tmp pointer to traverse
    // and compress the given BST.
    TreeNode* tmp = grand->right;
 
    // Traverse and left-rotate root m times
    // to compress given vine form of BST.
    for (int i = 0; i < m; i++) {
        TreeNode* oldTmp = tmp;
        tmp = tmp->right;
        grand->right = tmp;
        oldTmp->right = tmp->left;
        tmp->left = oldTmp;
        grand = tmp;
        tmp = tmp->right;
    }
}
 
// Function to implement the algorithm
TreeNode* balanceBST(TreeNode* root)
{
    // create dummy node with value 0
    TreeNode* grand = new TreeNode(0);
 
    // assign the right of dummy node as our input BST
    grand->right = root;
 
    // get the number of nodes in input BST and
    // simultaneously convert it into right linked list.
    int count = bstToVine(grand);
 
    // gets the height of tree in which all levels
    // are completely filled.
    int h = log2(count + 1);
 
    // get number of nodes until second last level
    int m = pow(2, h) - 1;
 
    // Left rotate for excess nodes at last level
    compress(grand, count - m);
 
    // Left rotation till m becomes 0
    // Step is done as mentioned in algo to
    // make BST balanced.
    for (m = m / 2; m > 0; m /= 2) {
        compress(grand, m);
    }
 
    // return the balanced tree
    return grand->right;
}
