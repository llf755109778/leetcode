////
//// Created by 75510 on 2022/3/17.
////
//#include "bits/stdc++.h"
//using namespace std;
//
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
//    void flatten(TreeNode* root) {
//        root = help(root);
//    }
//    TreeNode* help(TreeNode* root){
//        TreeNode* tmp;
//        TreeNode* tmp2;
//        if(!root){
//            return nullptr;
//        }
//        TreeNode* r = root->right;
//        TreeNode* l = root->left;
//        if(r){
//            tmp = help(root->right);
//            if(!l){
//                return tmp;
//            }
//        }
//        if(l){
//            tmp2 = help(root->left);
//            root->right=l;
//            root->left= nullptr;
//            if(r){
//                tmp2->right=r;
//                return tmp;
//            }
//            return tmp2;
//        }
//        return root;
//    }
//
//    /**********
//     * 优化版 牛皮
//     * @param r
//     * @return
//     */
//    TreeNode* help2(TreeNode* r){
//        if(r->left== nullptr&&r->right==nullptr) return r;
//        TreeNode* t=r->right;
//        TreeNode* l=r;
//        if(r->left!=nullptr){
//            l=help2(r->left);
//            r->right=r->left;
//            r->left=nullptr;
//            l->right=t;
//        }
//        if(t!=nullptr)
//            return help2(t);
//        return l;
//    }
//
//};
//
//
///********
// * class Solution {
//    public void flatten(TreeNode root) {
//        TreeNode curr = root;
//        while (curr != null) {
//            if (curr.left != null) {
//                TreeNode next = curr.left;
//                TreeNode predecessor = next;
//                while (predecessor.right != null) {
//                    predecessor = predecessor.right;
//                }
//                predecessor.right = curr.right;
//                curr.left = null;
//                curr.right = next;
//            }
//            curr = curr.right;
//        }
//    }
//}
//https://assets.leetcode-cn.com/solution-static/114/1.png
// * @param input
// */
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
//        Solution().flatten(root);
//
//        string out = treeNodeToString(root);
//        cout << out << endl;
//    }
//    return 0;
//}