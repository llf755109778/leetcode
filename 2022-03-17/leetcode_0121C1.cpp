////
//// Created by 75510 on 2022/3/17.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//
////class Solution {
////public:
////    int maxProfit(vector<int>& prices) {
////        int m=-1,n=1e7;
////        for(auto i:prices){
////            n = min(n,i);
////            m = max(m,i-n);
////        }
////        return m;
////    }
////};
//
//
//
///**********
// * 单调栈
// */
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        int ans = 0;
//        vector<int> St;
//        prices.emplace_back(-1); \\ 哨兵👨‍✈️
//        for (int i = 0; i < prices.size(); ++ i){
//            while (!St.empty() && St.back() > prices[i]){ \\ 维护单调栈📈
//                ans = std::max(ans, St.back() - St.front()); \\ 维护最大值
//                St.pop_back();
//            }
//            St.emplace_back(prices[i]);
//        }
//
//        return ans;
//    }
//};
//
//
//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> prices = stringToIntegerVector(line);
//
//        int ret = Solution().maxProfit(prices);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}