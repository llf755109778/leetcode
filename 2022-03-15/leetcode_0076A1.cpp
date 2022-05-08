////
//// Created by 75510 on 2022/3/15.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//
///********************
// *
// * 滑动窗口模板
// *
//int left = 0, right = 0;
//
//while (right < s.size()) {
//// 增大窗口
//    window.add(s[right]);
//    right++;
//
//    while (window needs shrink) {
//        // 缩小窗口
//        window.remove(s[left]);
//        left++;
//    }
//}
// */
//
//
//class Solution {
//public:
//    string minWindow(string s, string t) {
//        unordered_map<char, int> hs, ht;
//        for(auto i:t){
//            hs[i]++;
//        }
//
//        int r=0,l=0,cnt=0;
//        string res;
//        while(r<s.size()){
//            ht[s[r]]++;
//            if (hs[s[r]] >= ht[s[r]]) cnt++;
//            while(cnt==t.size()&&hs[s[l]] < ht[s[l]]){
//                ht[s[l++]]--;
//            }
//            if(cnt==t.size()&&(res==""||r-l+1<res.size())){
//                res = s.substr(l, r - l + 1);
//            }
//            r++;
//        }
//        return res;
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
//        getline(cin, line);
//        string t = stringToString(line);
//
//        string ret = Solution().minWindow(s, t);
//
//        string out = (ret);
//        cout << out << endl;
//    }
//    return 0;
//}