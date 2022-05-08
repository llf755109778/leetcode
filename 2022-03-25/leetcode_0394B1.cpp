////
//// Created by 75510 on 2022/3/25.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    string decodeString(string s) {
//        return help1(s);
//    }
//
//    string help1(string s) {
//        string ans;
//        int r=0,l=0,start=0;
//        int cnt = 0;
//        for(int i = 0; i < s.size(); ++i){
//            if(!l&&isdigit(s[i])){
//                cnt = cnt * 10 + s[i] - '0';
//            } else if(s[i]=='['){
//                if(!l){
//                    start = i+1;
//                }
//                ++l;
//            } else if(s[i]==']'){
//                ++r;
//            }
//            if(!cnt){
//                ans += s[i];
//            }
//            if(r&&r==l){
//                string tmp = help1(s.substr(start,i-start));
//                for(int j = 0; j < cnt; ++j){
//                    ans += tmp;
//                }
//                r=l=cnt=start=0;
//            }
//
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
//        string ret = Solution().decodeString(s);
//
//        string out = (ret);
//        cout << out << endl;
//    }
//    return 0;
//}