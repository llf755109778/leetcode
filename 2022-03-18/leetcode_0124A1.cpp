////
//// Created by 75510 on 2022/3/18.
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
//struct Status {
//    int lmax;   //  左边含自己
//    int rmax;
//    int l; // 左边
//    int r;
//    int m;  //  全部
//    Status() : lmax(-1e5), rmax(-1e5), l(-1e5), r(-1e5), m(-1e5) {}
//};
//class Solution {
//public:
//    int maxPathSum(TreeNode* root) {
//        Status s = help(root);
//        return max(max(max(max(s.rmax,s.lmax),s.r),s.l),s.m);
//    }
//
//    Status help(TreeNode* root){
//        if(root== nullptr){
//            return Status();
//        }
//        Status l = help(root->left);
//        Status r = help(root->right);
//        Status ans;
//        ans.l = max(max(max(max(l.l,l.lmax),l.m),l.r),l.rmax);
//        ans.r = max(max(max(max(r.l,r.lmax),r.m),r.r),r.rmax);
//        ans.lmax = max(max(root->val,root->val+l.lmax),root->val+l.rmax);
//        ans.rmax = max(max(root->val,root->val+r.lmax),root->val+r.rmax);
//        ans.m = ans.lmax + ans.rmax - root->val;
//        return ans;
//    }
//
//    /***********
//     * 优化版
//     */
//    int maxSum = INT_MIN;
//    int help2(TreeNode* node) {
//        if (node == nullptr) {
//            return 0;
//        }
//
//        // 递归计算左右子节点的最大贡献值
//        // 只有在最大贡献值大于 0 时，才会选取对应子节点
//        int leftGain = max(help2(node->left), 0);
//        int rightGain = max(help2(node->right), 0);
//
//        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
//        int priceNewpath = node->val + leftGain + rightGain;
//
//        // 更新答案
//        maxSum = max(maxSum, priceNewpath);
//
//        // 返回节点的最大贡献值
//        return node->val + max(leftGain, rightGain);
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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//
//        int ret = Solution().maxPathSum(root);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}