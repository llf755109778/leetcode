////
//// Created by 75510 on 2022/3/22.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        return help2(matrix, target);
//    }
//
//    /***
//     * 一个经典问题：给两个有序数组，要从中各选一个数，使两数之和为指定某个数。
//     * 如果把一个数组视为横轴，另一个数组视为纵轴，形成一张表格，格子里放「和」，那么就是这道题了
//     * @param matrix
//     * @param target
//     * @return
//     */
//    bool help1(vector<vector<int>>& matrix, int target){
//        int y=matrix[0].size() - 1,x=0;
//
//        while(x < matrix.size() && y >= 0){
//            if (target > matrix[x][y]) {
//                x++;
//            } else if (target < matrix[x][y]) {
//                y--;
//            } else {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    /*****
//     * 二维二分
//     * @param matrix
//     * @param target
//     * @return
//     */
//    bool help2(vector<vector<int>>& matrix, int target){
//        if (matrix.size() == 0 || matrix[0].size() == 0) {
//            return false;
//        }
//        return searchMatrixHelper(matrix, 0, 0, matrix[0].size() - 1, matrix.size() - 1, matrix[0].size() - 1, matrix.size() - 1, target);
//    }
//    bool searchMatrixHelper(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int xMax, int yMax, int target) {
//        //只需要判断左上角坐标即可
//        if (x1 > xMax || y1 > yMax) {
//            return false;
//        }
//
//        //x 轴代表的是列，y 轴代表的是行
//        if(x1 == x2 && y1 == y2){
//            return matrix[y1][x1] == target;
//        }
//        int m1 = (x1 + x2) >> 1;
//        int m2 = (y1 + y2) >> 1;
//        if (matrix[m2][m1] == target) {
//            return true;
//        }
//        if (matrix[m2][m1] < target) {
//            // 右上矩阵
//            return searchMatrixHelper(matrix, m1 + 1, y1, x2, m2, x2, y2, target) ||
//                   // 左下矩阵
//                   searchMatrixHelper(matrix, x1, m2 + 1, m1, y2, x2, y2, target) ||
//                   // 右下矩阵
//                   searchMatrixHelper(matrix, m1 + 1, m2 + 1, x2, y2, x2, y2, target);
//        } else {
//            // 右上矩阵
//            return searchMatrixHelper(matrix, m1 + 1, y1, x2, m2, x2, y2, target) ||
//                   // 左下矩阵
//                   searchMatrixHelper(matrix, x1, m2 + 1, m1, y2, x2, y2, target) ||
//                   // 左上矩阵
//                   searchMatrixHelper(matrix, x1, y1, m1, m2, x2, y2, target);
//        }
//    }
//};