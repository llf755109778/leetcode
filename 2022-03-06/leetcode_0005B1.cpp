//
// Created by 75510 on 2022/3/6.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 1050


/**
 * dp  dp[j][i] = dp[j+1][i-1];
 * @param input
 * @return
 */

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int len = s.size();
//        if(len==0||len==1)
//            return s;
//        vector<vector<int>> dp(MAX,vector<int>(MAX));
//        for(int i = 0; i < MAX; i++){
//
//            for(int j = 0; j < MAX;j++){
//                dp[i][j] = 0;
//            }
//            dp[i][i] = 1;
//        }
//        int start=0,end=0,res=0;
//        for(int i = 0; i < len; i++){
//            for(int j = 0; j < i; j++){
//                if(i - j > 2){
//                    if(s[i]==s[j]){
//                        dp[j][i] = dp[j+1][i-1];
//                    }
//                } else{
//                    if(s[i]==s[j]){
//                        dp[j][i] = 1;
//                    }
//                }
//                if(dp[j][i])
//                    if(i - j > res){
//                        res = i - j;
//                        start = i;
//                        end = j;
//                    }
//
//            }
//        }
//        return s.substr(end,start-end+1);
//    }
//};


/****
 *
 * 中心扩展法
 *      回文中心的两侧互为镜像。因此，回文可以从他的中心展开，
 *      并且只有 2n-1 个这样的中心（一个元素为中心的情况有 n 个，
 *      两个元素为中心的情况有 n-1 个）
 */
//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int len = s.size();
//        if(len < 2){
//            return s;
//        }
//        int start = 0, res = 0;
//        for(int i = 0; i < len ;i++){
//            int len1 = getAoa(s, i,i );
//            int len2 = getAoa(s, i,i + 1);
//            if(max(len1,len2) > res){
//                res = max(len1,len2);
//                start = i - (res - 1)/ 2;
//            }
//        }
//        return s.substr(start,res);
//    }
//
//    int getAoa(string s,int l,int r){
//        while (l>=0&&r<s.size()&&s[l]==s[r]){
//            r++;l--;
//        }
//        return r - l - 1;
//    }
//};
//


/************
 *
 *
 * 解法 5：Manacher
 *      这是一个专门用作处理最长回文子串的方法，思想很巧妙，比较难以理解，这里直接借用了别人的讲解方法。其实主要思想是，
 *  把给定的字符串的每一个字母当做中心，向两边扩展，这样来找最长的子回文串，这个叫中心扩展法，但是这个方法还要考虑到处理
 *  abba 这种偶数个字符的回文串。Manacher 法将所有的字符串全部变成奇数个字符。
 *          较难未写
 *
 */




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
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        string s = stringToString(line);
//
//        string ret = Solution().longestPalindrome(s);
//
//        string out = (ret);
//        cout << out << endl;
//    }
//    return 0;
//}