////
//// Created by 75510 on 2022/3/16.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//
/////*************
//// * 暴力
////时间复杂度：O(m^2n)其中 m 和 n 分别是矩阵的行数和列数。计算 left 矩阵需要 O(mn) 的时间。
//// 随后对于矩阵的每个点，需要 O(m) 的时间枚举高度。故总的时间复杂度为 O(m^2n)
////
////空间复杂度：O(mn)，其中 m 和 n 分别是矩阵的行数和列数。我们分配了一个与给定矩阵等大的数组，用于存储每个元素的左边连续 1 的数量。
////
////作者：LeetCode-Solution
////链接：https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode-solution-bjlu/
////来源：力扣（LeetCode）
////著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//// */
////class Solution {
////public:
////    int maximalRectangle(vector<vector<char>>& matrix) {
////        int m = matrix.size();
////        if (m == 0) {
////            return 0;
////        }
////        int n = matrix[0].size();
////        vector<vector<int>> left(m, vector<int>(n, 0));
////
////        for (int i = 0; i < m; i++) {
////            for (int j = 0; j < n; j++) {
////                if (matrix[i][j] == '1') {
////                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
////                }
////            }
////        }
////
////        int ret = 0;
////        for (int i = 0; i < m; i++) {
////            for (int j = 0; j < n; j++) {
////                if (matrix[i][j] == '0') {
////                    continue;
////                }
////                int width = left[i][j];
////                int area = width;
////                for (int k = i - 1; k >= 0; k--) {
////                    width = min(width, left[k][j]);
////                    area = max(area, (i - k + 1) * width);
////                }
////                ret = max(ret, area);
////            }
////        }
////        return ret;
////    }
////};
///**********
// *
//我们可以使用「84. 柱状图中最大的矩形的官方题解」中的单调栈的做法，将其应用在我们生成的柱状图中。
// */
//class Solution {
//public:
//    int maximalRectangle(vector<vector<char>>& matrix) {
//        int dp[220][220]{{}};
//        int m = 0;
//        for(int i = 1; i <= matrix.size(); ++i){
//            for(int j = 1; j <= matrix[0].size(); ++j){
//                dp[i][j] = dp[i-1][j]*(matrix[i-1][j-1] - '0') + matrix[i-1][j-1] - '0';
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//            stack<int> s;
//            s.push(0);
//            for(int k = 1; k <= matrix[0].size()+1; ++k){
//                while(dp[i][s.top()]>dp[i][k]){
//                    int tmp = dp[i][s.top()];
//                    s.pop();
//                    m = max(m, tmp * (k - s.top() -1));
//                }
//                s.push(k);
//            }
//        }
//        return m;
//    }
//};
//int main(){
//
//    vector<vector<char>> matrix {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
//    Solution().maximalRectangle(matrix);
//}