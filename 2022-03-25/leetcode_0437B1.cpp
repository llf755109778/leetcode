////
//// Created by 75510 on 2022/3/25.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///***************
// * 给定一个二叉树的根节点 root，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
// * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
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
//    int pathSum(TreeNode* root, int targetSum) {
//        return help1(root, targetSum);
//    }
//
//    /*********
//     * 深度优先搜索
//     * @param root
//     * @param targetSum
//     * @return
//     */
//    int help1(TreeNode* root, int targetSum) {
//        dfs(root, targetSum);
//        return cnt;
//    }
//
//    vector<long long> dfs(TreeNode* root, int targetSum){
//        if(!root){
//            return {};
//        }
//        vector<long long> ans;
//        vector<long long> l = dfs(root->left, targetSum);
//        vector<long long> r = dfs(root->right, targetSum);
//        for(auto &item:l){
//            if(item+root->val==targetSum){
//                ++cnt;
//            }
//            ans.push_back(item+root->val);
//        }
//        for(auto &item:r){
//            if(item+root->val==targetSum){
//                ++cnt;
//            }
//            ans.push_back(item+root->val);
//        }
//        if(root->val==targetSum){
//            cnt++;
//        }
//        ans.push_back(root->val);
//        return ans;
//    }
//
//    /**********
//     * 前缀和
//     * @param root
//     * @param targetSum
//     * @return
//     */
//    int help2(TreeNode* root, int targetSum) {
//        prefix[0] = 1;
//        return dfs(root, 0, targetSum);
//    }
//    unordered_map<long long, int> prefix;
//
//    int dfs(TreeNode *root, long long curr, int targetSum) {
//        if (!root) {
//            return 0;
//        }
//
//        int ret = 0;
//        curr += root->val;
//        if (prefix.count(curr - targetSum)) {
//            ret = prefix[curr - targetSum];
//        }
//
//        prefix[curr]++;
//        ret += dfs(root->left, curr, targetSum);
//        ret += dfs(root->right, curr, targetSum);
//        prefix[curr]--;
//
//        return ret;
//    }
//
//
//
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
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//        getline(cin, line);
//        int targetSum = stringToInteger(line);
//
//        int ret = Solution().pathSum(root, targetSum);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}