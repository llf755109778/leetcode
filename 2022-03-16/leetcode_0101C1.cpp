////
//// Created by 75510 on 2022/3/16.
////
//
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
//    bool isSymmetric(TreeNode* root) {
//        return method1(root,root);
//    }
//
//    bool method1(TreeNode* left,TreeNode* right){
//        if(left == nullptr&&right == nullptr){
//            return true;
//        }
//        if(left == nullptr&&right != nullptr){
//            return false;
//        }
//        if(left != nullptr&&right == nullptr){
//            return false;
//        }
//        /**
//         *
//         if(left == nullptr&&right != nullptr){
//            return false;
//        }
//        if(left != nullptr&&right == nullptr){
//            return false;
//        }
//         可以优化未
//         if(!left || !right){
//            return false;
//        }
//         */
//        if(left->val==right->val){
//            if(!method1(left->left,right->right)){
//                return false;
//            }
//            return method1(left->right,right->left);
//        } else{
//            return false;
//        }
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
//        bool ret = Solution().isSymmetric(root);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}