////
//// Created by 75510 on 2022/3/16.
////
//
//#include "bits/stdc++.h"
//using namespace std;
/////***************
//// * dp 给定一个有序序列 1 2 ... n1⋯n，为了构建出一棵二叉搜索树，我们可以遍历每个数字 i，将该数字作为树根，
//// * 将 1... (i-1) 序列作为左子树，将 (i+1)⋯n 序列作为右子树。接着我们可以按照同样的方式递归构建左子树和右子树。
////
////在上述构建的过程中，由于根的值不同，因此我们能保证每棵二叉搜索树是唯一的。
////
////由此可见，原问题可以分解成规模较小的两个子问题，且子问题的解可以复用。因此，我们可以想到使用动态规划来求解本题。
////
//// */
////class Solution {
////public:
////    int numTrees(int n) {
////        int dp[30]{};
////        dp[1]=dp[0]=1;
////        for(int i = 2; i <= n; ++i){
////            for(int j = 0; j < i; ++j){
////                dp[i] += dp[j]*dp[i-j-1];
////            }
////        }
////        return dp[n];
////    }
////};
//
//
/////*************
//// *  卡特兰数递推公式  c0=c1=1           C = C * 2 * (2 * i + 1) / (i + 2);
//// * @param input
//// * @return
//// */
////
////
////class Solution {
////public:
////    int numTrees(int n) {
////        long long C = 1;
////        for (int i = 0; i < n; ++i) {
////            C = C * 2 * (2 * i + 1) / (i + 2);
////        }
////        return (int)C;
////    }
////};
//
//
//
//
///*************
// * 排列组合  An = C(2n,n)/(n+1) n=1 1 ,n=2 2
// * @param input
// * @return
// */
//class Solution {
//public:
//    int numTrees(int n) {
//        long long C = 1;
//        for (int i = n + 1; i <= 2*n; ++i) {
//            C = C * i / (i - n);
//        }
//        C /= (n+1);
//        return (int)C;
//    }
//};
//
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        int n = stringToInteger(line);
//
//        int ret = Solution().numTrees(n);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}