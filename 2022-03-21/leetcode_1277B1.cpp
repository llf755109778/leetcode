////
//// Created by 75510 on 2022/3/21.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int countSquares(vector<vector<int>>& matrix) {
//        vector<vector<int>> v(310,vector<int>(310,0));
//        int ans=0;
//        for(int i = 1; i <= matrix.size(); ++i){
//            for(int j = 1; j <= matrix[0].size(); ++j){
//                if(matrix[i - 1][j - 1]){
//                    v[i][j] = max(1,1+min(min(v[i-1][j-1],v[i][j-1]),v[i-1][j]));
//                }
//            }
//        }
//        for(int i = 1; i <= matrix.size(); ++i){
//            for(int j = 1; j <= matrix[0].size(); ++j){
//                ans+=v[i][j];
//            }
//        }
//        return ans;
//    }
//};