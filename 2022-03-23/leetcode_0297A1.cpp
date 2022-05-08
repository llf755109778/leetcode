////
//// Created by 75510 on 2022/3/23.
////
//#include "bits/stdc++.h"
//using namespace std;
///*********
// * 二叉树序列化与反序列化
// */
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//class Codec {
//public:
//
//    // Encodes a tree to a single string.
//    string serialize(TreeNode* root) {
//        string str;
//        if(!root){
//            return "[]";
//        }
//        queue<TreeNode*> q;
//        q.push(root);
//        str = to_string(root->val) + ",";
//        while (!q.empty()){
//            int size = q.size();
//            for(int i = 0; i < size; ++i){
//                TreeNode* tmp = q.front();
//                if(tmp){
//                    q.push(tmp->left);
//                    if(tmp->left){
//                        str += to_string(tmp->left->val) + ",";
//                    } else{
//                        str += "null,";
//                    }
//                    q.push(tmp->right);
//                    if(tmp->right){
//                        str += to_string(tmp->right->val) + ",";
//                    } else{
//                        str += "null,";
//                    }
//                }
//                q.pop();
//            }
//        }
//        return "["+str.substr(0, str.size()-1)+"]";
//    }
//
//    // Decodes your encoded data to tree.
//    TreeNode* deserialize(string data) {
//        return stringToTreeNode(data);
//    }
//    TreeNode* stringToTreeNode(string input) {
//        trimLeftTrailingSpaces(input);
//        trimRightTrailingSpaces(input);
//        input = input.substr(1, input.length() - 2);
//        if (!input.size()) {
//            return nullptr;
//        }
//
//        string item;
//        stringstream ss;
//        ss.str(input);
//
//        getline(ss, item, ',');
//        TreeNode* root = new TreeNode(stoi(item));
//        queue<TreeNode*> nodeQueue;
//        nodeQueue.push(root);
//
//        while (true) {
//            TreeNode* node = nodeQueue.front();
//            nodeQueue.pop();
//
//            if (!getline(ss, item, ',')) {
//                break;
//            }
//
//            trimLeftTrailingSpaces(item);
//            if (item != "null") {
//                int leftNumber = stoi(item);
//                node->left = new TreeNode(leftNumber);
//                nodeQueue.push(node->left);
//            }
//
//            if (!getline(ss, item, ',')) {
//                break;
//            }
//
//            trimLeftTrailingSpaces(item);
//            if (item != "null") {
//                int rightNumber = stoi(item);
//                node->right = new TreeNode(rightNumber);
//                nodeQueue.push(node->right);
//            }
//        }
//        return root;
//    }
//    void trimLeftTrailingSpaces(string &input) {
//        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//            return !isspace(ch);
//        }));
//    }
//
//    void trimRightTrailingSpaces(string &input) {
//        input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//            return !isspace(ch);
//        }).base(), input.end());
//    }
//
//};
//
//// Your Codec object will be instantiated and called as such:
//// Codec ser, deser;
//// TreeNode* ans = deser.deserialize(ser.serialize(root));
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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//
//        string ret = Codec().serialize(root);
//
//        string out = (ret);
//        cout << out << endl;
//    }
//    return 0;
//}