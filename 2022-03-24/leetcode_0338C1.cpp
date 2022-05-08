////
//// Created by 75510 on 2022/3/24.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    vector<int> countBits(int n) {
//        int ii = n&(n^(n-1));
//        vector<int> ans;
//        ans.push_back(0);
//        while(ans.size()<=n){
//            int len = ans.size();
//            for(int i = 0; i < len&&ans.size()<=n; ++i){
//                ans.push_back(1+ans[i]);
//            }
//        }
//    }
//};
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//string integerVectorToString(vector<int> list, int length = -1) {
//    if (length == -1) {
//        length = list.size();
//    }
//
//    if (length == 0) {
//        return "[]";
//    }
//
//    string result;
//    for(int index = 0; index < length; index++) {
//        int number = list[index];
//        result += to_string(number) + ", ";
//    }
//    return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        int n = stringToInteger(line);
//
//        vector<int> ret = Solution().countBits(n);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}