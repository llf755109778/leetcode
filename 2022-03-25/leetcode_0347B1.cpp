////
//// Created by 75510 on 2022/3/25.
////
//#include "bits/stdc++.h"
//using namespace std;
//
/************
 * 前 K 个高频元素
 */
//class Solution {
//public:
//    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
//        return m.second > n.second;
//    }
//
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//        return help1(nums, k);
//    }
//
//    /*******
//     * 首先遍历整个数组，并使用哈希表记录每个数字出现的次数，并形成一个「出现次数数组」。
//     * 在使用最小堆
//     * @param k
//     * @return
//     */
//    vector<int> help1(vector<int>& nums, int k){
//        unordered_map<int, int> occurrences;
//        for (auto& v : nums) {
//            occurrences[v]++;
//        }
//
//        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
//        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (*cmp) > q(cmp);
////        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
//        for (auto& [num, count] : occurrences) {
//            if (q.size() == k) {
//                if (q.top().second < count) {
//                    q.pop();
//                    q.emplace(num, count);
//                }
//            } else {
//                q.emplace(num, count);
//            }
//        }
//        vector<int> ret;
//        while (!q.empty()) {
//            ret.emplace_back(q.top().first);
//            q.pop();
//        }
//        return ret;
//    }
//
//    /*****
//     * 首先遍历整个数组，并使用哈希表记录每个数字出现的次数，并形成一个「出现次数数组」。
//     * 在快排找出K个元素
//     * @param nums
//     * @param k
//     * @return
//     */
//    vector<int> help2(vector<int>& nums, int k) {
//        unordered_map<int, int> occurrences;
//        for (auto& v: nums) {
//            occurrences[v]++;
//        }
//
//        vector<pair<int, int>> values;
//        for (auto& kv: occurrences) {
//            values.push_back(kv);
//        }
//        vector<int> ret;
//        qsort(values, 0, values.size() - 1, ret, k);
//        return ret;
//    }
//
//
//    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k) {
//        int picked = rand() % (end - start + 1) + start;
//        swap(v[picked], v[start]);
//
//        int pivot = v[start].second;
//        int index = start;
//        for (int i = start + 1; i <= end; i++) {
//            if (v[i].second >= pivot) {
//                swap(v[index + 1], v[i]);
//                index++;
//            }
//        }
//        swap(v[start], v[index]);
//
//        if (k <= index - start) {
//            qsort(v, start, index - 1, ret, k);
//        } else {
//            for (int i = start; i <= index; i++) {
//                ret.push_back(v[i].first);
//            }
//            if (k > index - start + 1) {
//                qsort(v, index + 1, end, ret, k - (index - start + 1));
//            }
//        }
//    }
//
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
//        vector<int> ret = Solution().topKFrequent(nums, k);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}