////
//// Created by 75510 on 2022/3/16.
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
///*************
// * 递归中序遍历
// * @param input
// */
////class Solution {
////public:
////    long long a=LONG_LONG_MIN;
////    bool flag = true;
////    bool isValidBST(TreeNode* root) {
////        if(!flag){
////            return flag;
////        }
////        if(root==nullptr){
////            return true;
////        }
////        isValidBST(root->left);
////        if(root->val<=a){
////            flag = false;
////        } else{
////            a = root->val;
////        }
////        isValidBST(root->right);
////        return flag;
////    }
////};
//
//
//
///*******
// * 栈中序遍历
// * @param input
// */
//
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        stack<TreeNode*> s;
//        long long a = LONG_LONG_MIN;
//        while (root||!s.empty()){
//            while (root){
//                s.push(root);
//                root=root->left;
//            }
//            TreeNode* h = s.top();
//            s.pop();
//            if(a>=h->val){
//                return false;
//            }
//            a=h->val;
//            root=h->right;
//        }
//        return true;
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
//string boolToString(bool input) {
//    return input ? "True" : "False";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//
//        bool ret = Solution().isValidBST(root);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}