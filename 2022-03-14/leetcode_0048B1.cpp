////
//// Created by 75510 on 2022/3/14.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//class Solution {
//public:
//    void rotate() {
//        /***********
//         *  5,  1,  9,  11
//         *  2,  4,  8,  10
//         *  13, 3,  6,  7
//         *  15, 14, 12, 16
//         *
//         *  [15,13,2,5],
//         *  [14,3,4,1],
//         *  [12,6,8,9],
//         *  [16,7,10,11]
//         */
//        vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
//        int len = matrix.size();
//        int r=len-1,l=0,t=0,b=len-1;
//        while(r>l){
//            int tmp;
//            for(int i = 0; i < r - l; ++i){
//                tmp=matrix[t][i+l];
//                matrix[t][i+l] = matrix[b-i][l];
//                matrix[b-i][l] = matrix[b][r-i];
//                matrix[b][r-i] = matrix[t+i][r];
//                matrix[t+i][r] = tmp;
//            }
//            r--,b--;
//            l++,t++;
//        }
//    }
//};
//
//
//int main(){
//    (new Solution)->rotate();
//}