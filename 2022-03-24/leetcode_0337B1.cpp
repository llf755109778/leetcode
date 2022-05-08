////
//// Created by 75510 on 2022/3/24.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
///*************
// * 小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为root。
// * 除了root之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，
// * 聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
// * 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
// */
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};
//
//class Solution {
//public:
//    int rob(TreeNode* root) {
//        return max(help1(root).mx,help1(root).maxL);
//    }
//
//    struct Status{
//        int maxL;
//        int mx;
//    };
//
//    Status help1(TreeNode* root) {
//        if(!root){
//            return {0,0};
//        }
//
//        Status r = help1(root->right);
//        Status l = help1(root->left);
//
//        Status ans{};
//        ans.mx = l.maxL + r.maxL + root->val;
//        ans.maxL = max(l.mx, l.maxL) + max(r.mx, r.maxL);
//
//        return ans;
//    }
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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        TreeNode* root = stringToTreeNode(line);
//
//        int ret = Solution().rob(root);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}