class Solution
{
    public:
    bool hasPathSum(Node *node, int sum) {
    if (node == NULL) {
        return (sum == 0);
    }

    bool ans = false;
    int subSum = sum - node->data;

    if (subSum == 0 and node->left == NULL and node->right == NULL) return true;

    if (node->left) ans = ans || hasPathSum(node->left, subSum);
    if (node->right) ans = ans || hasPathSum(node->right, subSum);
    return ans;
}
};