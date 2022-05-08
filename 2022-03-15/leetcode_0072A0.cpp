////
//// Created by 75510 on 2022/3/15.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//
//    int minDistance(string word1, string word2) {
//        int dp[510][510];
//        int flag = 0;
//        for(int i = 0; i < word1.size(); ++i){
//            if(!flag&&word2[0]==word1[i]){
//                flag=1;
//            };
//            dp[0][i] = flag;
//        }
//        flag = 0;
//        for(int i = 0; i < word2.size(); ++i){
//            if(!flag&&word1[0]==word2[i]){
//                flag=1;
//            };
//            dp[i][0] = flag;
//        }
//        for(int i = 1; i < word2.size(); ++i){
//            for(int j = 1; j < word1.size(); ++j){
//                dp[i][j] = max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(word2[i]==word1[j]?1:0));
//            }
//        }
//        return max(word2.size(),word1.size()) - dp[word2.size()-1][word1.size()-1];
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
//        string word1 = stringToString(line);
//        getline(cin, line);
//        string word2 = stringToString(line);
//
//        int ret = Solution().minDistance(word1, word2);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}