////
//// Created by 75510 on 2022/3/27.
////
//#include "bits/stdc++.h"
//using namespace std;
///**************
// * 给你一个用字符数组tasks 表示的 CPU 需要执行的任务列表。
// * 其中每个字母表示一种不同种类的任务。任务可以以任意顺序执行，
// * 并且每个任务都可以在 1 个单位时间内执行完。在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。
// * 然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
// * 你需要计算完成所有任务所需要的 最短时间 。
// */
//class Solution {
//public:
//
//    static bool cmp(pair<int, char>& p1, pair<int, char>& p2){
//        return p1.first < p2.first;
//    }
//    int leastInterval(vector<char>& tasks, int n) {
//        if(!n){
//            return tasks.size();
//        }
//        ++n;
//        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(*cmp)> p(cmp);
//        int a[26]{};
//        for(auto &item:tasks){
//            a[item-'A']++;
//        }
//        for(int i = 0; i < 26; ++i){
//            if(a[i])
//                p.emplace(a[i], i + 'A');
//        }
//        int ans = 0;
//        while (!p.empty()){
//                int size = p.size();
//                size = min(size, n);
//
//                vector<pair<int, char>> tmp;
//                for(int i = 0; i < size; ++i){
//                    tmp.push_back(p.top());
//                    p.pop();
//                }
//                for(int i = 0; i < size; ++i){
//                    tmp[i].first--;
//                    if(tmp[i].first)
//                        p.push(tmp[i]);
//                }
//                ans += n;
//                if(p.empty()){
//                    ans -= n - size;
//                }
//        }
//        return ans;
//    }
//};
//
//int main(){
//    vector<char> tasks {'A','A','A','A','A','A','B','C','D','E','F','G'};
//    int n = 2;
//    cout << Solution().leastInterval(tasks, n);
//}