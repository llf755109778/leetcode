////
//// Created by 75510 on 2022/3/26.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///*******
// * 给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
// * 使每个节点 node的新值等于原树中大于或等于node.val的值之和。
// */
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    int cnt=0;
//    TreeNode* convertBST(TreeNode* root) {
//        dfs(root);
//        return root;
//    }
//
//    /**********
//     * 简单dfs
//     * @param root
//     * @return
//     */
//    TreeNode* help(TreeNode* root) {
//        dfs(root);
//        return root;
//    }
//
//    void dfs(TreeNode* root) {
//        if(!root){
//            return;
//        }
//        dfs(root->right);
//        cnt +=root->val;
//        root->val =cnt;
//        dfs(root->left);
//    }
//
//    /********
//     * Morris 遍历Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其反序中序遍历规则总结如下：
//     * 如果当前节点的右子节点为空，处理当前节点，并遍历当前节点的左子节点；
//     * 如果当前节点的右子节点不为空，找到当前节点右子树的最左节点（该节点为当前节点中序遍历的前驱节点）；
//     * 如果最左节点的左指针为空，将最左节点的左指针指向当前节点，遍历当前节点的右子节点；
//     * 如果最左节点的左指针不为空，将最左节点的左指针重新置为空（恢复树的原状），处理当前节点，并将当前节点置为其左节点；
//     * 重复步骤 1 和步骤 2，直到遍历结束。
//     * @param root
//     * @return
//     */
//    TreeNode* help2(TreeNode* root) {
//        int sum = 0;
//        TreeNode* node = root;
//
//        while (node != nullptr) {
//            if (node->right == nullptr) {
//                sum += node->val;
//                node->val = sum;
//                node = node->left;
//            } else {
//                TreeNode* succ = getSuccessor(node);
//                if (succ->left == nullptr) {
//                    succ->left = node;
//                    node = node->right;
//                } else {
//                    succ->left = nullptr;
//                    sum += node->val;
//                    node->val = sum;
//                    node = node->left;
//                }
//            }
//        }
//        return root;
//    }
//
//    TreeNode* getSuccessor(TreeNode* node) {
//        TreeNode* succ = node->right;
//        while (succ->left != nullptr && succ->left != node) {
//            succ = succ->left;
//        }
//        return succ;
//    }
//};
//
//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//TreeNode* stringToTreeNode(string input) {
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    if (!input.size()) {
//        return nullptr;
//    }
//
//    string item;
//    stringstream ss;
//    ss.str(input);
//
//    getline(ss, item, ',');
//    TreeNode* root = new TreeNode(stoi(item));
//    queue<TreeNode*> nodeQueue;
//    nodeQueue.push(root);
//
//    while (true) {
//        TreeNode* node = nodeQueue.front();
//        nodeQueue.pop();
//
//        if (!getline(ss, item, ',')) {
//            break;
//        }
//
//        trimLeftTrailingSpaces(item);
//        if (item != "null") {
//            int leftNumber = stoi(item);
//            node->left = new TreeNode(leftNumber);
//            nodeQueue.push(node->left);
//        }
//
//        if (!getline(ss, item, ',')) {
//            break;
//        }
//
//        trimLeftTrailingSpaces(item);
//        if (item != "null") {
//            int rightNumber = stoi(item);
//            node->right = new TreeNode(rightNumber);
//            nodeQueue.push(node->right);
//        }
//    }
//    return root;
//}
//
//string treeNodeToString(TreeNode* root) {
//    if (root == nullptr) {
//        return "[]";
//    }
//
//    string output = "";
//    queue<TreeNode*> q;
//    q.push(root);
//    while(!q.empty()) {
//        TreeNode* node = q.front();
//        q.pop();
//
//        if (node == nullptr) {
//            output += "null, ";
//            continue;
//        }
//
//        output += to_string(node->val) + ", ";
//        q.push(node->left);
//        q.push(node->right);
//    }
//    return "[" + output.substr(0, output.length() - 2) + "]";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//
//        TreeNode* ret = Solution().convertBST(root);
//
//        string out = treeNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}