////
//// Created by 75510 on 2022/3/14.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int minPathSum(vector<vector<int>>& grid) {
//        for(int i = 1; i < grid[0].size(); ++i){
//            grid[0][i] += grid[0][i-1];
//        }
//        for(int i = 1; i < grid.size(); ++i){
//            grid[i][0] += grid[i-1][0];
//        }
//        for(int i = 1; i < grid.size(); ++i){
//            for(int j = 1; j < grid[0].size(); ++j){
//                grid[i][j] = grid[i][j]+min(grid[i-1][j],grid[i][j-1]);
//            }
//        }
//        return grid[grid.size()-1][grid[0].size()-1];
//    }
//};
//
//
//int main(){
//    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
//    cout << Solution().minPathSum(intervals);
//    return 0;
//}