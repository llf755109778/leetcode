////
//// Created by 75510 on 2022/3/22.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int numSquares(int n) {
//        return help4(n);
//    }
//
//    /***
//     * 动态规划
//     */
//     int help1(int n){
//        vector<int> f(n + 1);
//        for (int i = 1; i <= n; i++) {
//            int minn = INT_MAX;
//            for (int j = 1; j * j <= i; j++) {
//                minn = min(minn, f[i - j * j]);
//            }
//            f[i] = minn + 1;
//        }
//        return f[n];
//     }
//
//
//    /***
//     *  四平方和定理
//     *  4^k*(8m+7)   4
//     *  答案为 1 时，则必有 n 为完全平方数，这很好判断；
//     *  答案为 2 时，则有 n=a^2+b^2  我们只需要枚举所有的 a( 1 ≤ a ≤ sqrt(n) )，判断 n-a^2是否为完全平方数即可；
//     *  其他 3
//     */
//    int help2(int n) {
//        if (isPerfectSquare(n)) {
//            return 1;
//        }
//        if (checkAnswer4(n)) {
//            return 4;
//        }
//        for (int i = 1; i * i <= n; i++) {
//            int j = n - i * i;
//            if (isPerfectSquare(j)) {
//                return 2;
//            }
//        }
//        return 3;
//    }
//
//    // 判断是否为完全平方数
//    bool isPerfectSquare(int x) {
//        int y = sqrt(x);
//        return y * y == x;
//    }
//
//    // 判断是否能表示为 4^k*(8m+7)
//    bool checkAnswer4(int x) {
//        while (x % 4 == 0) {
//            x /= 4;
//        }
//        return x % 8 == 7;
//    }
//
//
//    /*****
//     * bfs
//     */
//     int help3(int n){
//        vector<int> v(10001,0);
//        queue<int> s;
//        s.push(n);
//        while (!s.empty()){
//            int tmp = s.front();
//            s.pop();
//            for(int i = sqrt(tmp); i >= 1; --i){
//                if (tmp - i * i == 0){
//                    return v[tmp]+1;
//                }else {
//                    s.push(tmp-i*i);
//                    if(v[tmp-i*i])
//                        v[tmp-i*i] = min(v[tmp] + 1,v[tmp-i*i]);
//                    else
//                        v[tmp-i*i] = v[tmp] + 1;
//                }
//            }
//        }
//        return -1;
//     }
//
//     /*******
//      * 贪心
//      */
//    vector<int> ps;
//    int ans[10005]{};
//    int help4(int n){
//        for(int i = 1; i <= 100; ++i){
//            ps.push_back(i*i);
//            ans[i*i] = 1;
//        }
//        for(int i = 1; i <= n; ++i){
//            if(dfs(n, i)){
//                return i;
//            }
//        }
//        return 1;
//    }
//
//    bool dfs(int n, int count){
//        if(n < 0){
//            return false;
//        }
//        if(count == 1)
//            return ans[n];
//        for (auto &i:ps)
//            if(n-i>0){
//            if (dfs(n-i, count-1))
//              return true;
//            }
//        return false;
//    }
//};
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
//        int ret = Solution().numSquares(n);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}