//
// Created by 75510 on 2022/3/8.
//

#include "bits/stdc++.h"
using namespace std;

///********
// *
// * dp 合法的字串 结尾一定是  ")" ：统计")"结尾我len（max）
// */
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        int dp[40000];
//        int res=0;
//        for(int i = 1; i <= s.size(); ++i){
//            if(i>1&&s[i-1] == ')'&&(i-dp[i-1]-2>=0)&&s[i-dp[i-1]-2]=='('){
//                dp[i] = dp[i-1] + 2 +dp[i-dp[i-1]-2];
//                res = max(res, dp[i]);
//            } else{
//
//                dp[i]=0;
//            }
//        }
//        return res;
//    }
//};


///*********
// *
// * 栈 波浪线原理
// *
// */
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        stack<int> v;
//        v.push(0);
//        int res = 0;
//        int i=0;
//        while (++i <= s.size()){
//            if(s[i-1]=='('){
//                v.push(i);
//            } else{
//                v.pop();
//                if(v.empty()){
//                    v.push(i);
//                } else{
//                    res = max(res,i-v.top());
//                }
//            }
//        }
//        return res;
//    }
//};

//
///*********
// *  在此方法中，我们利用两个计数器 \textit{left}left 和 \textit{right}right 。首先，我们从左到右遍历字符串，对于遇到的每个 \text{‘(’}‘(’，我们增加 \textit{left}left 计数器，对于遇到的每个 \text{‘)’}‘)’ ，我们增加 \textit{right}right 计数器。每当 \textit{left}left 计数器与 \textit{right}right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串。当 \textit{right}right 计数器比 \textit{left}left 计数器大时，我们将 \textit{left}left 和 \textit{right}right 计数器同时变回 00。
//
//这样的做法贪心地考虑了以当前字符下标结尾的有效括号长度，每次当右括号数量多于左括号数量的时候之前的字符我们都扔掉不再考虑，重新从下一个字符开始计算，但这样会漏掉一种情况，就是遍历的时候左括号的数量始终大于右括号的数量，即 (() ，这种时候最长有效括号是求不出来的。
//
//解决的方法也很简单，我们只需要从右往左遍历用类似的方法计算即可，只是这个时候判断条件反了过来：
//
//当 \textit{left}left 计数器比 \textit{right}right 计数器大时，我们将 \textit{left}left 和 \textit{right}right 计数器同时变回 00
//当 \textit{left}left 计数器与 \textit{right}right 计数器相等时，我们计算当前有效字符串的长度，并且记录目前为止找到的最长子字符串
//
//作者：LeetCode-Solution
//链接：https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
// * @param input
// * @return
// */
//class Solution {
//public:
//    int longestValidParentheses(string s) {
//        int res = 0;
//        int r=0,l=0;
//        for(int i = 0; i < s.size(); i++){
//            if(s[i]=='('){
//                ++l;
//            } else{
//                ++r;
//            }
//            if(l == r){
//                res = max(res,r*2);
//            } else if(l < r){
//                r=l=0;
//            }
//        }
//        r=l=0;
//        for(int i = s.size() - 1; i >= 0; --i){
//            if(s[i]==')'){
//                ++l;
//            } else{
//                ++r;
//            }
//            if(l == r){
//                res = max(res,r*2);
//            } else if(l < r){
//                r=l=0;
//            }
//        }
//        return res;
//    }
//};
//
//
//
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
//        int ret = Solution().longestValidParentheses(s);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}
