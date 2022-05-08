////
//// Created by 75510 on 2022/3/7.
////
//
//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    /************
//     *     //DFS
//     * @param left
//     * @param right
//     * @param rs
//     * @param str
//     */
//
//    void generateParenthesis_(int left,int right,vector<string>& rs,string str){
//        if (left == 0 && right == 0) {
//            rs.push_back(str);
//            return;
//        }
//        if (left > 0) generateParenthesis_(left - 1, right, rs, str + "(");
//        if (left < right) generateParenthesis_(left, right - 1, rs, str + ")");
//    }
//
//    vector<string> generateParenthesis(int n) {
//        vector<string> rs;
//        generateParenthesis_(n,n,rs,"");
//        return rs;
//    }
//
//
///************
// *     //DFS
// * @param left
// * @param right
// * @param rs
// * @param str
// */
//    vector<string> generateParenthesis2(int n) {
//        vector<string> rs;
//        queue<pair<string, pair<int, int>>>q; // pair<当前的括号, pair<左括号剩余, 右括号剩余>>
//        q.push({"",{n,n}});
//        while (!q.empty()) {
//            auto top = q.front();
//            q.pop();
//            string str = top.first;
//            int left = top.second.first;
//            int right = top.second.second;
//            if (left == 0 && right == 0) {
//                rs.push_back(str);
//            }
//            if (left > 0) {
//                q.push({str + '(',{left-1,right}});
//            }
//            if (right > 0 && right > left) {
//                q.push({str + ')',{left,right-1}});
//            }
//        }
//        return rs;
//    }
//};