//
// Created by 75510 on 2022/3/6.
//
//#include "bits/stdc++.h"
//using namespace std;

/********
 *
 *
 *
 给你一个字符串s和一个字符规律p，请你来实现一个支持 '.'和'*'的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个元素
所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。

 */


//class Solution {
//public:
//    int cnt;
//    bool isMatch(string s, string p) {
//        cnt = 0;
//        int flag = p[0]=='*'?1:0;
//        for (int i = 1; i < p.size(); i++){
//            if(p[i] == '*'){
//                if(flag)
//                    p[i-1]='-';
//                flag = 1;
//            } else{
//                flag = 0;
//            }
//        }
//        string str = "";
//        for(int i = 0; i < p.size(); i++){
//            if(p[i]!='-'){
//                str+=p[i];
//            }
//        }
//        solve(s,str);
//        return cnt>0;
//    }
//
//    void solve(string s, string p){
//        if(cnt){
//            return;
//        }
//        if(s.size()==0&&p.size()==0){
//            ++cnt;
//        }
//        if(s.size()==0){
//            return ;
//        }
//        if(p.size()==0){
//            return ;
//        }
//        if(p[0]=='.'){
//            solve(s.substr(1,s.size()),p.substr(1,p.size()));
//        } else if(isalpha(p[0])){
//            if(p[0]==s[0]){
//                solve(s.substr(1,s.size()),p.substr(1,p.size()));
//            } else{
//                return ;
//            }
//        } else{
//            for (int i = 0; i <= s.size(); ++i) {
//                solve(s.substr(i,s.size()),p.substr(1,p.size()));
//            }
//        }
//    }
//};


/*******
 *
 *
 *
    1、将p中的通配符 按照 . 和 * 分开处理
    2、如果p为空 有两种情况 (1).p本身为空 s不为空 返回false (2).p为空 s也为空 证明正常处理完成 返回true
    3、先考虑通配符是 '.' 的情况 如果s中的第一个字符和p中第一个字符相等 或者 p中的第一个字符是 '.' 将s 和 p 中对应的字符去掉
        设定一个Boolean来接收 后面会根据Boolean值判断
    4、在考虑通配符是 '*' 的情况 判断当前p的长度是否大于2 并且第二个字符是 * （这么做的目的：看是否需要匹配 如果匹配 去掉s中的一个字符
        不匹配去掉p中的两个字符）// 很重要

 * @param input
 * @return
 */

//
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        //1. 如果 p 为空 则返回false 如果p 为空 s也为空 返回true(证明匹配完毕)
//        if (p.empty()) {
//            return s.empty();
//        }
//        //2. 先考虑 . 的情况  如果s的第一位和p的第一位相等 || s 的第一位 和 p 的第一位是 . 将两个字符串的第一个字符去掉 继续匹配后面的字符
//        bool result = !s.empty() && (s[0] == p[0] || p[0] == '.');
//        //3. 在考虑 * 的情况
//        // 3.1 当p的长度大于2(*的时候要取* 前面的那个字符 ) 并且 p中第二个字符是 * 可以匹配s中任意0 个或多个 p.charAt(0) 字符
//        if (p.length() >= 2 && p[1] == '*') {
//            // 如果进行匹配： 相当于去掉s 中的一个字符
//            // 如果不进行匹配(匹配0次)：s不变 p向后去掉两位
//            return isMatch(s, p.substr(2)) || (result && isMatch(s.substr(1), p));
//        }
//        // 这是 第二情况 如果为true的时候返回的
//        return result && isMatch(s.substr(1), p.substr(1));
//    }
//};


/*********
 *
 *
 *
 https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/
 */
//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int m = s.size();
//        int n = p.size();
//
//        auto matches = [&](int i, int j) {
//            if (i == 0) {
//                return false;
//            }
//            if (p[j - 1] == '.') {
//                return true;
//            }
//            return s[i - 1] == p[j - 1];
//        };
//
//        vector<vector<int>> f(m + 1, vector<int>(n + 1));
//        f[0][0] = true;
//        for (int i = 0; i <= m; ++i) {
//            for (int j = 1; j <= n; ++j) {
//                if (p[j - 1] == '*') {
//                    f[i][j] |= f[i][j - 2];
//                    if (matches(i, j - 1)) {
//                        f[i][j] |= f[i - 1][j];
//                    }
//                }
//                else {
//                    if (matches(i, j)) {
//                        f[i][j] |= f[i - 1][j - 1];
//                    }
//                }
//            }
//        }
//        return f[m][n];
//    }
//};


//string stringToString(string input) {
//    assert(input.length() >= 2);
//    string result;
//    for (int i = 1; i < input.length() -1; i++) {
//        char currentChar = input[i];
//        if (input[i] == '\\') {
//            char nextChar = input[i+1];
//            switch (nextChar) {
//                case '\"': result.push_back('\"'); break;
//                case '/' : result.push_back('/'); break;
//                case '\\': result.push_back('\\'); break;
//                case 'b' : result.push_back('\b'); break;
//                case 'f' : result.push_back('\f'); break;
//                case 'r' : result.push_back('\r'); break;
//                case 'n' : result.push_back('\n'); break;
//                case 't' : result.push_back('\t'); break;
//                default: break;
//            }
//            i++;
//        } else {
//            result.push_back(currentChar);
//        }
//    }
//    return result;
//}
//
//string boolToString(bool input) {
//    return input ? "True" : "False";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        string s = stringToString(line);
//        getline(cin, line);
//        string p = stringToString(line);
//
//        bool ret = Solution().isMatch(s, p);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}