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
    int maxDepth(TreeNode *root) {
        if (NULL == root) {
            return 0;
        }

        set<TreeNode*> visited;
        stack<TreeNode*> s;
        s.push(root);
        int h = 0;
        int maxDepth = 0;
        while (!s.empty()) {
            TreeNode *node = s.top();
            // 检查node是否已经被访问过
            if (visited.count(node) == 0) {
                h++;
                visited.insert(node);

                if (!isLeaf(node)) {
                    if (NULL != node->left)
                        s.push(node->left);
                } else {
                    if (h > maxDepth) {
                        maxDepth = h;
                    }
                    s.pop();
                    h--;
                }

            } else {
                // 检查是否左右孩子都已经被访问，是则pop该节点
                if (isChildVisited(node, visited)) {
                    s.pop();
                    h--;
                } else {
                    s.push(node->right);
                }

            }
        }

        return maxDepth;
    }

    bool isChildVisited(TreeNode *node, const set<TreeNode*> &visited) {
        bool ret = false;
        if (node->left != NULL && node->right != NULL)
            ret = visited.count(node->left) > 0 && visited.count(node->right) > 0;
        else if (node->left == NULL && node->right != NULL)
            ret = visited.count(node->right) > 0;
        else if (node->left != NULL && node->right == NULL)
            ret = visited.count(node->left) > 0;

        return ret;
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
