////
//// Created by 75510 on 2022/3/21.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        return help2(nums, k);
//    }
//
//    /*******
//     * 堆排序
//     * @param nums
//     * @param k
//     * @return
//     */
//    int help1(vector<int>& nums, int k) {
//        priority_queue<int>p;
//        int len = nums.size()-k+1;
//        for(int i = 0; i < len; ++i){
//            p.push(nums[i]);
//        }
//        for(int i = len; i < nums.size(); ++i){
//            if(nums[i]<p.top()){
//                p.pop();
//                p.push(nums[i]);
//            }
//        }
//        return p.top();
//    }
//
//    int help2(vector<int>& nums, int k) {
//
//        int l = 0, r = nums.size();
//        while (true){
//            int tmp = partitionSort(nums,l,r);
//            if(tmp >= k){
//                l = r - tmp;
//            } else if(tmp + 1 == k){
//                return nums[r - tmp - 1];
//            }else{
//                k = k - tmp - 1;
//                r = r - tmp - 1;
//            }
//        }
//    }
//
//    int partitionSort(vector<int>& nums, int l, int  r) {
//        int pivot = nums[r-1];
//        int tmp = r;
//        for(int i = tmp - 2; i >= l; --i){
//            if(nums[i]>pivot){
//                --r;
//                swap(nums[i], nums[r-1]);
//            }
//        }
//        swap(nums[tmp-1], nums[r-1]);
//        return tmp - r;
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
//        int ret = Solution().findKthLargest(nums, k);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}