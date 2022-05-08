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
//    unordered_map<int, int> index;
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        int n = preorder.size();
//        for (int i = 0; i < n; ++i) {
//            index[inorder[i]] = i;
//        }
//        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
//    }
//
//    TreeNode* helper( vector<int>& preorder, int l, int r, vector<int>& inorder, int l1, int r1){
//        if(l > r){
//            return nullptr;
//        }
//        TreeNode* tmp = new TreeNode(preorder[l]);
//
//        /*******
//         * 可以优化为         int i=index[preorder[l]];
//         */
//        int i;
//        for(i = l1; i <= r1; ++i){
//            if(tmp->val == inorder[i]){
//                break;
//            }
//        }
//        TreeNode* left = helper(preorder, l+1, i - l1 + l, inorder, l1, i - 1);
//
//        TreeNode* rigth = helper(preorder, i - l1 + l + 1, r, inorder, i + 1, r1);
//        tmp->left = left;
//        tmp->right = rigth;
//        return tmp;
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
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
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
//        vector<int> preorder = stringToIntegerVector(line);
//        getline(cin, line);
//        vector<int> inorder = stringToIntegerVector(line);
//
//        TreeNode* ret = Solution().buildTree(preorder, inorder);
//
//        string out = treeNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}