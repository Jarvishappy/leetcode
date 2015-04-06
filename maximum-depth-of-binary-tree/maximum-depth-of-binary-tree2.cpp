#include <iostream>
#include <stack>
#include <set>

using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    /**
     * 思路：
     * 采用递归先序遍历，当抵达叶子节点时记录最大深度，回溯上一个节点。
     * 需要注意的是，参数h不能是引用类型，因为如果是引用类型，那么在回溯之后，
     * h中的值仍然是回溯前栈帧中的值，h必须以passing by value的方式进行递归调用
     *
     */
    int maxDepth(TreeNode *root) {
        int maxDepth = 0, h = 1;
        recursive_traverse(root, h, maxDepth);
        return maxDepth;
    }

    void recursive_traverse(TreeNode *node, int h, int &maxDepth) {
        if (node != NULL) {
            // base case
            if (isLeaf(node)) {
                if (h > maxDepth)
                    maxDepth = h;
                return;
            }

            recursive_traverse(node->left, h + 1, maxDepth);
            recursive_traverse(node->right, h + 1, maxDepth);
        }
    }

    bool isLeaf(TreeNode *node) {
        return node->left == NULL && node->right == NULL;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    return 0;
}
