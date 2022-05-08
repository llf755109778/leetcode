////
//// Created by 75510 on 2022/3/24.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///*************
// *  "()())()"删除无效的括号 返回所有可能的结果
// *  1. dfs+剪枝
// *  2. bfs+剪枝
// */
//class Solution {
//public:
//    set<string> ans;
//    string s;
//    int len, n,mx;
//    vector<string> removeInvalidParentheses(string s) {
//
//    }
//
//    /************
//     * dfs+剪枝
//     *      1.但事实上，我们可以通过预处理，得到最后的「应该删除的左括号数量」和「应该删掉的右括号数量」，来直接得到最终的 len。
//     *      2.set 去重
//     *      3.dfs score>mx
//     * @param s
//     * @return
//     */
//    vector<string> help1(string s){
//        this->s = s;
//        this->n = s.size();
//        int remove = 0;
//        int l=0,r=0,lenL=0,lenR=0;
//        for(auto&i:s){
//            if(i=='('){
//                lenL++;
//            }else if(i == ')'){
//                lenR++;
//            }
//
//            if(lenR > lenL){
//                r += lenR - lenL;
//                lenL = lenR = 0;
//            }
//        }
//        int c1 = 0, c2 = 0;
//        for(auto&i:s){
//            if (i == '(') c1++;
//            else if (i == ')') c2++;
//        }
//        mx = min(c1, c2);
//
//        l = max(l, lenL - lenR);
//        this->len = n - l - r;
//        dfs(l,r,0,"",0);
//        vector<string> ans;
//        for (auto & str : this->ans) {
//            ans.emplace_back(str);
//        }
//        return ans;
//    }
//    void dfs(int l, int r, int idx, string str, int score){
//        if(l<0||r<0||score<0||score>mx){
//            return;
//        }
//        if (l == 0 && r == 0) {
//            if (str.size() == len) ans.emplace(str);
//        }
//        if(idx == n) return;
//        char c = s[idx];
//        if (c == '(') {
//            dfs(l, r, idx + 1, str + c, score + 1);
//            dfs(l - 1, r,idx + 1, str,  score);
//        } else if (c == ')') {
//            dfs( l, r, idx + 1, str + c,score - 1);
//            dfs(l, r - 1, idx + 1, str, score);
//        } else {
//            dfs(l, r,idx + 1, str + c,  score);
//        }
//    }
//
//    /**********
//     * 2. bfs+剪枝
//     *    去重 if (i > 0 && str[i] == str[i - 1]) continue;
//     * @param s
//     * @return
//     */
//    vector<string> help2(string s) {
//        vector<string> ans;
//        unordered_set<string> currSet;
//
//        currSet.insert(s);
//        while (true) {
//            for (auto & str : currSet) {
//                if (isValid(str))
//                    ans.emplace_back(str);
//            }
//            if (ans.size() > 0) {
//                return ans;
//            }
//            unordered_set<string> nextSet;
//            for (auto & str : currSet) {
//                for (int i = 0; i < str.size(); i++) {
//                    if (i > 0 && str[i] == str[i - 1]) {
//                        continue;
//                    }
//                    if (str[i] == '(' || str[i] == ')') {
//                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
//                    }
//                }
//            }
//            currSet = nextSet;
//        }
//    }
//
//    bool isValid(string str) {
//        int count = 0;
//
//        for (char c : str) {
//            if (c == '(') {
//                count++;
//            } else if (c == ')') {
//                count--;
//                if (count < 0) {
//                    return false;
//                }
//            }
//        }
//
//        return count == 0;
//    }
//};
//
//int main(){
//    string str;
//    while (cin >> str){
//        auto ans=Solution().removeInvalidParentheses(str);
//        for(auto &i:ans){
//            cout << i << ",";
//        }
//        cout << endl;
//    }
//}