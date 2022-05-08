////
//// Created by 75510 on 2022/3/16.
////
//#include "bits/stdc++.h"
//using namespace std;
//
/**********
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/bao-li-jie-fa-zhan-by-liweiwei1419/
 */
//class Solution {
//public:
//    int largestRectangleArea(vector<int>& heights) {
//        stack<int> s;
//        vector<int> h;
//        h.push_back(0);
//        int m=0;
//        for (int i = 0; i < heights.size(); ++i) {
//            h.push_back(heights[i]);
//        }
//        h.push_back(0);
//        s.push(0);
//        for(int i = 1; i <= heights.size()+1; ++i){
//            while (!s.empty()&&h[s.top()]>h[i]){
//                int tmp = s.top();
//                s.pop();
//                m = max(m, (i - s.top() - 1)*h[tmp]);
//            }
//            s.push(i);
//        }
//        return m;
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
//        vector<int> heights = stringToIntegerVector(line);
//
//        int ret = Solution().largestRectangleArea(heights);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}



/**********************
*


我们需要在柱状图中找出最大的矩形，因此我们可以考虑枚举矩形的宽和高，其中「宽」表示矩形贴着柱状图底边的宽度，「高」表示矩形在柱状图上的高度。

如果我们枚举「宽」，我们可以使用两重循环枚举矩形的左右边界以固定宽度 w，此时矩形的高度 h，就是所有包含在内的柱子的「最小高度」，对应的面积为
 w×h。下面给出了这种方法的 C++ 代码。

C++

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        // 枚举左边界
        for (int left = 0; left < n; ++left) {
            int minHeight = INT_MAX;
            // 枚举右边界
            for (int right = left; right < n; ++right) {
                // 确定高度
                minHeight = min(minHeight, heights[right]);
                // 计算面积
                ans = max(ans, (right - left + 1) * minHeight);
            }
        }
        return ans;
    }
};
如果我们枚举「高」，我们可以使用一重循环枚举某一根柱子，将其固定为矩形的高度 hh。随后我们从这跟柱子开始向两侧延伸，直到遇到高度小于 hh 的柱子，
就确定了矩形的左右边界。如果左右边界之间的宽度为 ww，那么对应的面积为 w×h。下面给出了这种方法的 C++ 代码。

C++

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for (int mid = 0; mid < n; ++mid) {
            // 枚举高
            int height = heights[mid];
            int left = mid, right = mid;
            // 确定左右边界
            while (left - 1 >= 0 && heights[left - 1] >= height) {
                --left;
            }
            while (right + 1 < n && heights[right + 1] >= height) {
                ++right;
            }
            // 计算面积
            ans = max(ans, (right - left + 1) * height);
        }
        return ans;
    }
};
可以发现，这两种暴力方法的时间复杂度均为 O(N^2)，会超出时间限制，我们必须要进行优化。
考虑到枚举「宽」的方法使用了两重循环，本身就已经需要 O(N^2)的时间复杂度，
不容易优化，因此我们可以考虑优化只使用了一重循环的枚举「高」的方法。


*/