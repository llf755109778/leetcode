////
//// Created by 75510 on 2022/3/21.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//
//    /**
//     * 方法二
//     * https://leetcode-cn.com/problems/maximal-square/solution/fen-xiang-yi-ge-bu-yong-dong-tai-gui-hua-cai-yong-/
//     */
//    int maximalSquare(vector<vector<char>>& matrix) {
//        vector<vector<int>> v(310,vector<int>(310,0));
//        int ans=0;
//        for(int i = 1; i <= matrix.size(); ++i){
//            for(int j = 1; j <= matrix[0].size(); ++j){
//                if(matrix[i - 1][j - 1]=='1'){
//                    v[i][j] = max(1,1+min(min(v[i-1][j-1],v[i][j-1]),v[i-1][j]));
//                    ans = max(ans,v[i][j]);
//                }
//            }
//        }
//        for(int i = 1; i <= matrix.size(); ++i){
//            for(int j = 1; j <= matrix[0].size(); ++j){
//                cout << v[i][j] << " ";
//            }
//            cout << endl;
//        }
//        return ans*ans;
//    }
//};
//
//int main(){
//    vector<vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
//    Solution().maximalSquare(matrix);
//}