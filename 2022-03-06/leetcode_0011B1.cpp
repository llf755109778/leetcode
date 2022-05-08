//
// Created by 75510 on 2022/3/6.
//
//#include <bits/stdc++.h>
//using namespace std;
//
///******
// *  暴力
// */
////class Solution {
////public:
////    int maxArea(vector<int>& height) {
////        int res = 0;
////        for(int i = 0; i < height.size(); i++){
////            for(int j = i + 1; j < height.size(); j++){
////                res = max(res, (j - i) * min(height[i], height[j]));
////            }
////        }
////        return res;
////    }
////};
//
//
//
///*******************
// *
// * 双指针
// *      在初始时，左右指针分别指向数组的左右两端，它们可以容纳的水量为 \min(1, 7) * 8 = 8min(1,7)∗8=8。
// *  此时我们需要移动一个指针。移动哪一个呢？直觉告诉我们，应该移动对应数字较小的那个指针（即此时的左指针）。
// *
// * @param input
// */
//
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int res = 0;
//        int l = 0,r=height.size() - 1;
//        while (l < r){
//            res = max(res,(r-l)*min(height[r],height[l]));
//            if(height[r]>height[l]){
//                ++l;
//            } else{
//                --r;
//            }
//        }
//        return res;
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
//        vector<int> height = stringToIntegerVector(line);
//
//        int ret = Solution().maxArea(height);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}