////
//// Created by 75510 on 2022/3/26.
////
//#include "bits/stdc++.h"
//using namespace std;
//
///**********
// * 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
// * 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
// */
//class Solution {
//public:
//    int hammingDistance(int x, int y) {
//
//    }
//
//
//    /**********
//     * 方法一
//     * @param x
//     * @param y
//     * @return
//     */
//    int help1(int x, int y) {
//        x ^= y;
//        int cnt=0;
//        while(x)
//            x &= (x-1),++cnt;
//        return cnt;
//    }
//
//
//    /************
//     * 分治 利用 1&0 = 0 ；1&1 = 1 可以表示有几个1
//     *         右移 1位计算偶数位 个数， 然后相加， 至此每两位2位1的数量确定
//     *         在和11& ，统计每四位，1111& 8位， 0xff 16位, 0xffff 32位
//     * @param x
//     * @param y
//     * @return
//     */
//    int help2(int x, int y) {
//        int c;
//        c = x ^ y;
//        c = (c & 0x55555555) + ((c >> 1) & 0x55555555);
//        c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
//        c = (c & 0x0f0f0f0f) + ((c >> 4) & 0x0f0f0f0f);
//        c = (c & 0x00ff00ff) + ((c >> 8) & 0x00ff00ff);
//        c = (c & 0x0000ffff) + ((c >> 16) & 0x0000ffff);
//        return c;
//    }
//
//    /*******
//     * help2的优化
//     * @param x
//     * @param y
//     * @return
//     */
//    int help3(int x, int y) {
//        unsigned int i = x ^ y;
//
//        i = i - ((i >> 1) & 0x55555555);
//        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
//        // 0x01 01 01 01 将每8位移动之最后8位
//        return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
//    }
//
//};
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        int x = stringToInteger(line);
//        getline(cin, line);
//        int y = stringToInteger(line);
//
//        int ret = Solution().hammingDistance(x, y);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}