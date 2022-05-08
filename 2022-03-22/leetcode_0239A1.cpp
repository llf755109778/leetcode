////
//// Created by 75510 on 2022/3/22.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        return help2(nums, k);
//    }
//
//    /*****
//     * 最大堆 优先队列
//     * 对于本题而言，初始时，我们将数组 nums 的前 k 个元素放入优先队列中。
//     * 每当我们向右移动窗口时，我们就可以把一个新的元素放入优先队列中，
//     * 此时堆顶的元素就是堆中所有元素的最大值。
//     * 然而这个最大值可能并不在滑动窗口中，在这种情况下，这个值在数组 nums 中的位置出现在滑动窗口左边界的左侧。
//     * 因此，当我们后续继续向右移动窗口时，这个值就永远不可能出现在滑动窗口中了，我们可以将其永久地从优先队列中移除。
//     * 我们不断地移除堆顶的元素，直到其确实出现在滑动窗口中。
//     * 此时，堆顶元素就是滑动窗口中的最大值。为了方便判断堆顶元素与滑动窗口的位置关系，
//     * 我们可以在优先队列中存储二元组 (num,index)，表示元素 num 在数组中的下标为 index。
//     * @param nums
//     * @param k
//     * @return
//     */
//    vector<int> help1(vector<int>& nums, int k){
//        vector<int> ans;
//        priority_queue<pair<int, int>> p;
//        for(int i = 0; i < k; ++i){
//            p.emplace(nums[i],i);
//        }
//        ans.push_back(p.top().first);
//        for(int i = k; i < nums.size(); ++i){
//            while (!p.empty() && i - p.top().second >= k){
//                p.pop();
//            }
//            p.emplace(nums[i],i);
//            ans.push_back(p.top().first);
//        }
//        return ans;
//    }
//
//
//    /***
//     * 单调队列 deque;
//     * @param nums
//     * @param k
//     * @return
//     */
//    vector<int> help2(vector<int>& nums, int k){
//        vector<int> ans;
//        deque<int> p;
//        for(int i = 0; i < k; ++i){
//            while (!p.empty() && nums[p.back()] < nums[i]){
//                p.pop_back();
//            }
//            p.emplace_back(i);
//        }
//        ans.push_back(nums[p.front()]);
//        for(int i = k; i < nums.size(); ++i){
//            while (!p.empty() && nums[p.back()] < nums[i]){
//                p.pop_back();
//            }
//            p.emplace_back(i);
//            while (!p.empty() && i - p.front() >= k){
//                p.pop_front();
//            }
//            ans.push_back(nums[p.front()]);
//        }
//        return ans;
//    }
//
//    /****
//     * 分块 预处理 前后缀
//     * 除了基于「随着窗口的移动实时维护最大值」的方法一以及方法二之外，我们还可以考虑其他有趣的做法。
//     * 我们可以将数组 nums 从左到右按照 k 个一组进行分组，最后一组中元素的数量可能会不足 k 个。
//     * 如果我们希望求出 nums[i] 到nums[i+k−1] 的最大值，就会有两种情况：
//     * 如果 i 是 k 的倍数，那么nums[i] 到 nums[i+k−1] 恰好是一个分组。我们只要预处理出每个分组中的最大值，即可得到答案；
//     * 如果 i 不是 k 的倍数，那么 nums[i] 到 nums[i+k−1] 会跨越两个分组，占有第一个分组的后缀以及第二个分组的前缀。
//     * 假设 j 是 k 的倍数，并且满足 i<j≤i+k−1，那么 nums[i] 到 nums[j−1] 就是第一个分组的后缀，nums[j] 到nums[i+k−1] 就是第二个分组的前缀。
//     * 如果我们能够预处理出每个分组中的前缀最大值以及后缀最大值，同样可以在 O(1) 的时间得到答案。
//     * @param nums
//     * @param k
//     * @return
//     */
//    vector<int> help3(vector<int>& nums, int k){
//        int n = nums.size();
//        vector<int> prefixMax(n), suffixMax(n);
//        for (int i = 0; i < n; ++i) {
//            if (i % k == 0) {
//                prefixMax[i] = nums[i];
//            }
//            else {
//                prefixMax[i] = max(prefixMax[i - 1], nums[i]);
//            }
//        }
//        for (int i = n - 1; i >= 0; --i) {
//            if (i == n - 1 || (i + 1) % k == 0) {
//                suffixMax[i] = nums[i];
//            }
//            else {
//                suffixMax[i] = max(suffixMax[i + 1], nums[i]);
//            }
//        }
//
//        vector<int> ans;
//        for (int i = 0; i <= n - k; ++i) {
//            ans.push_back(max(suffixMax[i], prefixMax[i + k - 1]));
//        }
//        return ans;
//
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
//        int k = stringToInteger(line);
//
//        vector<int> ret = Solution().maxSlidingWindow(nums, k);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}