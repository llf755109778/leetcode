//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        std::unordered_map <int,int> hash;
//        vector<int> ans;
//
////        int idx = 0;
////        for(auto &&i:nums){
////            if(hash.find(target-i)!=hash.end()){
////                ans.push_back(idx++);
////                ans.push_back(hash[target-i]);
////                return ans;
////            }
////            hash.insert(pair<int,int>(i,idx++));
//////            hash[i]=idx++;
////        }
////        return ans;
//
//
//        for(int i = 0; i < nums.size(); i++){
//            if(hash[target - nums[i]]!=0){
//                ans.push_back(i);
//                ans.push_back(hash[target-nums[i]] - 1);
//                return ans;
//            }
//            hash[nums[i]]= i + 1;
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
//        vector<int> nums = stringToIntegerVector(line);
//        getline(cin, line);
//        int target = stringToInteger(line);
//
//        vector<int> ret = Solution().twoSum(nums, target);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}