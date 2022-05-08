////
//// Created by 75510 on 2022/3/22.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        return help2(root, p, q);
//    }
//
//    /**
//     * dfs 遍历路径
//     * @param root
//     * @param p
//     * @param q
//     * @return
//     */
//    stack<TreeNode*> s;
//    TreeNode* help1(TreeNode* root, TreeNode* p, TreeNode* q) {
//        vector<TreeNode*> v1,v2;
//        getPath(root,p);
//        while (!s.empty()){
//            v1.push_back(s.top());
//            s.pop();
//        }
//        getPath(root,q);
//        while (!s.empty()){
//            v2.push_back(s.top());
//            s.pop();
//        }
//        TreeNode* ans=root;
//        int len1,len2;
//        len1 = v1.size();
//        len2 = v2.size();
//        for(int i = 1; i <= min(len1, len2); ++i){
//            if(v1[len1 - i]==v2[len2 - i]){
//                ans = v1[len1 - i];
//            } else{
//                break;
//            }
//        }
//        return ans;
//    }
//
//    bool getPath(TreeNode* root, TreeNode* p){
//        s.push(root);
//        if(!root){
//            return false;
//        }
//        if(root==p){
//            return true;
//        }
//        if(getPath(root->right, p))
//            return true;
//        s.pop();
//        if(getPath(root->left, p))
//            return true;
//        s.pop();
//        return false;
//    }
//
//    /***********
//     * 递归
//     * @param root
//     * @param p
//     * @param q
//     * @return
//     */
//    TreeNode* ans;
//    TreeNode* help2(TreeNode* root, TreeNode* p, TreeNode* q) {
//        getAns(root, p, q);
//        return ans;
//    }
//
//    bool getAns(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if(!root){
//            return false;
//        }
//
//        bool l = getAns(root->left, p, q);
//        bool r = getAns(root->right, p, q);
//        if(l&&r || ((root->val == p->val || root->val == q->val) && (l||r))){
//            ans = root;
//        }
//
//        if(root==p||root==q||l||r){
//            return true;
//        }
//        return false;
//    }
//
//    /****
//     *
//     * 递归优化
//     */
//    TreeNode* help3(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if(root == nullptr || root == p || root == q) return root;
//        TreeNode *left = lowestCommonAncestor(root->left, p, q);
//        TreeNode *right = lowestCommonAncestor(root->right, p, q);
//        if(left == nullptr) return right;
//        if(right == nullptr) return left;
//        return root;
//    }
//};