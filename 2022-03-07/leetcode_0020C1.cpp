//
// Created by 75510 on 2022/3/7.
//
//#include "bits/stdc++.h"
//using namespace std;


/********
 *
 * 栈  可以有map优化多个循环
 *
 */
//class Solution {
//public:
//    bool isValid(string s) {
//        bool res = true;
//        stack<char> stack;
//        for(auto item:s){
//            if(!res){
//                break;
//            }
//            if(item=='}'){
//                res = (!stack.empty())&&stack.top()=='{';
//                stack.pop();
//            } else if(item==')'){
//                res = (!stack.empty())&&stack.top()=='(';
//                stack.pop();
//            } else if(item==']'){
//                res = (!stack.empty())&&stack.top()=='[';
//                stack.pop();
//            }else{
//                stack.push(item);
//            }
//        }
//        return res&&stack.empty();
//    }
//};



/*************
 *@剽窃某大佬思路，我稍作改进
 *执行用时：47 ms, 在所有 Java 提交中击败了5.62%的用户
 *内存消耗：41.4 MB, 在所有 Java 提交中击败了5.01%的用户
 *2022年2月8日 21:22
**/
//class Solution {
//public:
//    bool isValid(string s) {
//        while(true){
//            int l=s.length();
//            s=s.replace(s.find("()"),2,"");
//            s=s.replace(s.find("{}"),2,"");
//            s=s.replace(s.find("[]"),2,"");
//            if(s.length()==l){return l==0;}
//        }
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
//
//        bool ret = Solution().isValid(s);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}