////
//// Created by 75510 on 2022/3/27.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///*************
// * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
// * 回文字符串 是正着读和倒过来读一样的字符串。
// * 子字符串 是字符串中的由连续字符组成的一个序列。
// * 有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
// */
//class Solution {
//public:
//    int countSubstrings(string s) {
//        int ans = 0;
//        for(int i = 0; i < s.size(); ++i){
//            for(int j = 0; j <= min(i,(int)s.size()-i-1); ++j){
//                if(s[i+j] == s[i-j]){
//                    ans++;
//                } else{
//                    break;
//                }
//            }
//            for(int j = 0; j <= min(i,(int)s.size()-i-2); ++j){
//                if(s[i+j+1] == s[i-j]){
//                    ans++;
//                } else{
//                    break;
//                }
//            }
//        }
//        return ans;
//    }
//};
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
//          result.push_back(currentChar);
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
//        int ret = Solution().countSubstrings(s);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}