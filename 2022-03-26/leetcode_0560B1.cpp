////
//// Created by 75510 on 2022/3/26.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///*********
// * 和为 K 的子数组
// */
//class Solution {
//public:
//    /**********
//     * 前缀和+hashmap优化
//     * @param nums
//     * @param k
//     * @return
//     */
//    int subarraySum(vector<int>& nums, int k) {
//        unordered_map<int,int> m;
//        int cnt=0;
//        int ans=0;
//        m[0]=1;
//        for(int i = 0; i < nums.size(); ++i){
//            cnt+=nums[i];
//            ans+=m[cnt-k];
//            m[cnt]++;
//        }
//        return ans;
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
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> nums = stringToIntegerVector(line);
//        getline(cin, line);
//        int k = stringToInteger(line);
//
//        int ret = Solution().subarraySum(nums, k);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}