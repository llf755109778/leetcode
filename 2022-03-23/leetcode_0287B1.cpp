////
//// Created by 75510 on 2022/3/23.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int findDuplicate(vector<int>& nums) {
//        return help1(nums);
//    }
//
//    /*******
//     * 二分查找 nlog(n)
//     * @param nums
//     * @return
//     */
//    int help1(vector<int>& nums){
//        int r = nums.size() - 1,l=0;
//        int mid;
//        while(r>=l){
//            mid = (r + l) / 2;
//            int ans = 0;
//            for(int i = 0; i < nums.size(); ++i){
//                if(nums[i] <= mid){
//                    ans++;
//                }
//            }
//            if(ans > mid){
//                r = mid - 1;
//            }else{
//                l = mid + 1;
//            }
//        }
//        int ans = 0;
//        for(int i = 0; i < nums.size(); ++i){
//            if(nums[i] <= mid){
//                ans++;
//            }
//        }
//        if(ans <= mid){
//            ++mid;
//        }
//        return mid;
//    }
//
//    /****
//     *「Floyd 判圈算法」（又称龟兔赛跑算法）快慢指针
//     * 我们对 nums 数组建图，每个位置 i 连一条 i→nums[i] 的边。由于存在的重复的数字 target，
//     * 因此 target 这个位置一定有起码两条指向它的边，因此整张图一定存在环，
//     * 并且只要一个点被多个target指向
//     * @param nums
//     * @return
//     */
//    int help2(vector<int>& nums) {
//        int slow = 0, fast = 0;
//        do {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        } while (slow != fast);
//        slow = 0;
//        while (slow != fast) {
//            slow = nums[slow];
//            fast = nums[fast];
//        }
//        return slow;
//    }
//
//
//    /*****
//     * 二进制 类似help1
//     * 考虑到第 i 位，我们记 nums 数组中二进制展开后第 i 位为 1 的数有 x 个，
//     * 数字[1,n] 这 n 个数二进制展开后第 i 位为 1 的数有 y 个，那么重复的数第 i 位为 1 当且仅当 x>y
//     * https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/。
//     * @param nums
//     * @return
//     */
//    int help3(vector<int>& nums){
//        int n = nums.size(), ans = 0;
//        // 确定二进制下最高位是多少
//        int bit_max = 31;
//        while (!((n - 1) >> bit_max)) {
//            bit_max -= 1;
//        }
//        for (int bit = 0; bit <= bit_max; ++bit) {
//            int x = 0, y = 0;
//            for (int i = 0; i < n; ++i) {
//                if (nums[i] & (1 << bit)) {
//                    x += 1;
//                }
//                if (i >= 1 && (i & (1 << bit))) {
//                    y += 1;
//                }
//            }
//            if (x > y) {
//                ans |= 1 << bit;
//            }
//        }
//        return ans;
//    }
//
//    /*********
//     * hash 把原数组看成一个哈希表，对于每一个元素n，比较数组下标为(n - 1)的元素，
//     * 如果相等，则找到重复数字，如果不相等，则将该数字换到数组下标(n - 1)的位置，直到找到重复元素
//     * @param nums
//     * @return
//     */
//    int help4(vector<int>& nums){
//        for(int i = 0; i < nums.size(); ){
//            int tmp = nums[i] - 1;
//            if(tmp != i){
//                if(nums[tmp] == nums[i])
//                    return nums[i];
//                else
//                    swap(nums[tmp], nums[i]);
//            }
//            else
//                i++;
//        }
//        return 0;
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
//        int ret = Solution().findDuplicate(nums);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}