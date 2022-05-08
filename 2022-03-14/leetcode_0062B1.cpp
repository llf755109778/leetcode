////
//// Created by 75510 on 2022/3/14.
////
//#include "bits/stdc++.h"
//
//using namespace std;
//
////class Solution {
////public:
////    int uniquePaths(int m, int n) {
////        int ans[m+1][n+1];
////        for(int i = 0; i <= n; ++i){
////            ans[0][i] = 1;
////        }
////        for(int i = 0; i < m; ++i){
////            ans[i][0] = 1;
////        }
////        for(int i = 1; i < m; ++i){
////            for(int j = 1; j < n; ++j){
////                ans[i][j] = ans[i-1][j]+ans[i][j-1];
////            }
////        }
////        return ans[m-1][n-1];
////    }
////};
//
///********************
// *
// * 空间优化 O(2n)
// */
////class Solution {
////public:
////    int uniquePaths(int m, int n) {
////        int pre[n];
////        int cur[n];
////        for(int i = 0; i <= n; ++i){
////            pre[i] = 1;
////            cur[i] = 1;
////        }
////        for (int i = 1; i < m;i++){
////            for (int j = 1; j < n; j++){
////                cur[j] = cur[j-1] + pre[j];
////            }
////            for(int i = 0; i <= n; ++i){
////                pre[i] = cur[i];
////            }
////        }
////        return pre[n-1];
////    }
////};
//
//
///********************
// *
// * 空间优化 O(n)
// */
//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        int cur[n];
//        for(int i = 0; i <= n; ++i){
//            cur[i] = 1;
//        }
//        for (int i = 1; i < m;i++){
//            for (int j = 1; j < n; j++){
//                cur[j] += cur[j-1] ;
//            }
//        }
//        return cur[n-1];
//    }
//}
//
//
//
//
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        int m = stringToInteger(line);
//        getline(cin, line);
//        int n = stringToInteger(line);
//
//        int ret = Solution().uniquePaths(m, n);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}