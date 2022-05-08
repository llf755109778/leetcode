////
//// Created by 75510 on 2022/3/24.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///**********
// * 最佳买卖股票时机含冷冻期
// * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// */
//class Solution {
//public:
//    /*********
//     *   下标    -2 -1 0  1  2  3  4
//     * prices         1  2  3  0  2
//     * dp        0  0 0  1  2  2  3     max(dp[i-1],price[i] - price[x-1] + dp[x-3])  1<=x<i
//     * m              -1 -1 -1 1  1     m[i] = max(m[i-1],- price[x-1] + dp[x-3])
//     *
//     * 同 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/
//     * @param prices
//     * @return
//     */
//    int maxProfit(vector<int>& prices) {
//        vector<int> dp(prices.size()+10,0); // 最大
//        vector<int> m(prices.size()+10,0);  //
//        m[0] = -prices[0];
//        for(int i = 1; i < prices.size(); ++i){
//            dp[i + 3] = max(dp[i+2],prices[i] + m[i - 1]);
//            m[i] = max(m[i-1], dp[i+1] - prices[i]);
//        }
//        return dp[prices.size()+2];
//    }
//};
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