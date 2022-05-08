////
//// Created by 75510 on 2022/3/27.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///**************
// * 合并二叉树
// * 想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
// * 你需要将这两棵树合并成一棵新二叉树。
// * 合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
// * 否则，不为 null 的节点将直接作为新二叉树的节点。
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
//    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
//
//        if(!t1)
//            return t2;
//        if(!t2)
//            return t1;
//        t1->val += t2->val;
//        t1->left = mergeTrees(t1->left,t2->left);
//        t1->right = mergeTrees(t1->right,t2->right);
//        return t1;
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
//        TreeNode* root1 = stringToTreeNode(line);
//        getline(cin, line);
//        TreeNode* root2 = stringToTreeNode(line);
//
//        TreeNode* ret = Solution().mergeTrees(root1, root2);
//
//        string out = treeNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}