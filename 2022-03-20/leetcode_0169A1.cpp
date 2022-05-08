////
//// Created by 75510 on 2022/3/20.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//
//    /********
//     * 随机
//     * @param vector
//     * @return
//     */
//    int help1(vector<int> &vector) {
//        int len = vector.size();
//        while (1){
//            int m = rand()%len;
//            int cnt = 0;
//            for(int i = 0; i < len; ++i){
//                if(vector[i] == vector[m]){
//                    ++cnt;
//                    if(cnt>len>>1){
//                        return vector[m];
//                    }
//                }
//            }
//        }
//    }
//
//    /**********
//     * Boyer-Moore(摩尔投票法)
//     * @param nums
//     * @return
//     */
//    int help2(vector<int> &vector) {
//        int count = 0;
//        int select = -1;
//        for(auto i:vector){
//            if(i==select){
//                ++count;
//            } else if (--count < 0) {
//                select = i;
//                count = 1;
//            }
//        }
//        return select;
//    }
//
//    int majorityElement(vector<int>& nums) {
//        return help2(nums);
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
//        vector<int> nums = stringToIntegerVector(line);
//
//        int ret = Solution().majorityElement(nums);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}