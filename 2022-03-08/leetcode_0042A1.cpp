////
//// Created by 75510 on 2022/3/8.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int m=0;
//        int sum=0;
//        for(int i = 0; i < height.size(); ++i){
//            m=max(m,height[i]);
//            sum+=height[i];
//        }
//        vector<int> v;
//        for(int i = 0; i < height.size(); ++i){
//            if(m==height[i]){
//                v.push_back(i);
//            }
//        }
//        int l=v[0],r=v[v.size()-1];
//        int s=m*(r-l+1);
//        int h=0;
//        for(int i = 0; i < l ; ++i){
//            h=max(h,height[i]);
//            s+=h;
//        }
//        h=0;
//        for(int i = height.size() - 1; i > r; --i){
//            h=max(h,height[i]);
//            s+=h;
//        }
//        return s - sum;
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
//        int ret = Solution().trap(height);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}