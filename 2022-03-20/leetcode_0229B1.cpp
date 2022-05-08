////
//// Created by 75510 on 2022/3/20.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    /********
//     * 随机
//     * @param vector
//     * @return
//     */
//    vector<int> help1(vector<int> &vector1) {
//        vector<int> ans;
//        int len = vector1.size();
//        int n = vector1.size()/4;
//        n = max(100,n);
//        while (n--){
//            if(ans.size()>1){
//                break;
//            }
//            int m = rand()%len;
//            int cnt = 0;
//            for(int i = 0; i < len; ++i){
//                if(vector1[i] == vector1[m]){
//                    ++cnt;
//                    if(cnt>len/3){
//                        int f=0;
//                        for(auto q:ans){
//                            if(vector1[m]==q){
//                                f = 1;
//                            }
//                        }
//                        if(!f){
//                            ans.push_back(vector1[m]);
//                        }
//                    }
//                }
//            }
//        }
//        return ans;
//    }
//
//    /**********
//     * Boyer-Moore(摩尔投票法)
//     * @param nums
//     * @return
//     */
//    vector<int> help2(vector<int> &vector1) {
//        vector<int> ans;
//        int countA = 0,countB=0;
//        int selectA=-1,selectB = -1;
//        for(auto i:vector1){
//            if(i==selectA){
//                countA++;
//            } else if(i==selectB){
//                countB++;
//            } else if(countA==0){
//                countA=1;
//                selectA=i;
//            } else if(countB==0){
//                countB=1;
//                selectB=i;
//            } else{
//                countB--;
//                countA--;
//            }
//        }
//        countA=0,countB=0;
//        for(int i:vector1){
//            if(i==selectA){
//                countA++;
//            } else if(i==selectB){
//                countB++;
//            }
//        }
//        if(countA > vector1.size() / 3){
//            ans.push_back(selectA);
//        }
//        if(countB > vector1.size() / 3){
//            ans.push_back(selectB);
//        }
//    }
//
//    vector<int> majorityElement(vector<int>& nums) {
//        return help1(nums);
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
//
//        vector<int> ret = Solution().majorityElement(nums);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}