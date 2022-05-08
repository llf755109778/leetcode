////
//// Created by 75510 on 2022/3/18.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//
//
//class Solution {
//public:
//    int longestConsecutive(vector<int>& nums) {
//        return help3(nums);
//    }
//
//    /********
//     * hash 表  T:O(n)
//     * @param nums
//     * @return
//     */
//    int help1(vector<int>& nums){
//        unordered_set<int> s;
//        for(auto &i:nums){
//            s.insert(i);
//        }
//
//        int m=0;
//        for(auto item:nums){
//            // 连续的最左边 的左边没用数字
//            if(s.find(item-1)==s.end()){  // 多次出现会浪费时间，可以优化 移除 item。 s.erase(item - tmp);
//                int tmp = 1;
//                while (tmp){
//                    if(s.find(++item)!=s.end()){
//                        tmp++;
//                    } else{
//                        s.erase(item - tmp);
//                        break;
//                    }
//                }
//                m = max(tmp, m);
//            }
//        }
//        return m;
//    }
//
//    /*************
//     * dp
//        具体做法是：
//        遍历nums数组中的所有数字num
//        当num是第一次出现时：
//        （1）分别获取到左相邻数字num-1的连续区间长度left和右相邻数字num+1的连续区间长度right；
//        （2）计算得到当前的区间长度为curLen=left+right+1curLen=left+right+1；
//        （3）更新最长区间长度ans以及左右边界的区间长度。
//
//     * @param nums
//     * @return
//     */
//    int help2(vector<int>& nums){
//        unordered_map<int, int> m;
//        int ans = 0;
//        for (int num : nums) {
//            // 当map中不包含num，也就是num第一次出现
//            if (m.find(num)==m.end()) {
//                // left为num-1所在连续区间的长度，更进一步理解为：左连续区间的长度
//                int left = (m.find(num - 1)!=m.end())?m.find(num - 1)->second:0;
//                // right为num+1所在连续区间的长度，更进一步理解为：右连续区间的长度
//                int right = m.find(num + 1)!=m.end()?m.find(num + 1)->second:0;
//                // 当前连续区间的总长度
//                int curLen = left + right + 1;
//                ans = max(ans, curLen);
//                // 将num加入map中，表示已经遍历过该值。其对应的value可以为任意值。
//                m[num]=-1;
//                // 更新当前连续区间左边界和右边界对应的区间长度
//                m[num - left]= curLen;
//                m[num + right]=curLen;
//            }
//        }
//        return ans;
//    }
//
//
//    /**************
//     * 并查集
//     * @param nums
//     * @return
//     */
//    unordered_map<int, int> p, cnt;
//
//    int help3(vector<int>& nums){
//        if(nums.size() == 0) return 0;
//        for (int num : nums) p[num] = num, cnt[num] = 1;
//
//        for (int num : nums)
//            if (p.count(num + 1))
//                merge(num, num + 1);
//
//        int ans = 1;
//        for (int num : nums) ans = max(ans, cnt[num]);
//        return ans;
//    }
//    int find(int x)
//    {
//        if (p[x] != x) p[x] = find(p[x]);
//        return p[x];
//    }
//
//    void merge(int x, int y)
//    {
//        x = find(x), y = find(y);
//        if (x != y) p[x] = y, cnt[y] += cnt[x];
//    }
//
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
//        int ret = Solution().longestConsecutive(nums);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}