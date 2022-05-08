////
//// Created by 75510 on 2022/3/17.
////
//#include "bits/stdc++.h"
//using namespace std;
//
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
//
/////***********
//// * bfs 层次遍历
//// */
////class Solution {
////public:
////    vector<vector<int>> levelOrder(TreeNode* root) {
////        vector<vector<int>> ans;
////        queue<pair<TreeNode*,int>> q;
////        if(!root){
////            return ans;
////        }
////        q.push(pair<TreeNode*,int>(root,0));
////        while (!q.empty()){
////            pair<TreeNode*,int> tmp = q.front();
////            if(tmp.first->left){
////                q.push(pair<TreeNode*,int>(tmp.first->left,tmp.second+1));
////            }
////            if(tmp.first->right){
////                q.push(pair<TreeNode*,int>(tmp.first->right,tmp.second+1));
////            }
////            if(ans.size()<=tmp.second){
////                ans.push_back(vector<int>());
////            }
////            ans[tmp.second].push_back(tmp.first->val);
////            q.pop();
////        }
////        return ans;
////    }
////};
//
///*********
// *
// * dfs 深度遍历
// * @param input
// */
//class Solution {
//public:
//    vector<vector<int>> ret;
//    void level(TreeNode* root, int lev) {
//        if(!root) return;
//        if (lev >= ret.size()) {
//            ret.push_back(vector<int>());
//        }
//        ret[lev].push_back(root -> val);
//        level(root -> left, lev + 1);
//        level(root -> right, lev + 1);
//    }
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        level(root, 0);
//        return ret;
//    }
//};
//
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
//        Solution().levelOrder(root);
//
//    }
//    return 0;
//}