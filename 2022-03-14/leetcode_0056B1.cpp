////
//// Created by 75510 on 2022/3/14.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//
////class Solution {
////public:
////    int a[40010];
////    int b[40010];
////    vector<vector<int>> merge(vector<vector<int>>& intervals) {
////        vector<vector<int>> ans;
////        int start = 0;
////        for(auto i : intervals){
////            a[i[0]] += 1;
////            a[i[1]] -= 1;
////            b[i[0]] = (a[i[0]]==a[i[1]]);
////        }
////        int cnt = 0;
////        int flag = 0;
////        for(int i = 0; i < 40005; ++i){
////            if(a[i]) {
////                start = i;
////                break;
////            }
////        }
////        for(int i = 0; i < 40005; ++i){
////            cnt+=a[i];
////            if(a[i]&&!cnt){
////                ans.push_back(vector<int>{start,i});
////                flag = 1;
////                a[i]=1;
////            }
////            if(cnt){
////                a[i]=1;
////            }
////            if(flag&&cnt){
////                flag = 0;
////                start = i;
////            }
////            // if(cnt){
////            //     ans.push_back(vector<int>{i,i});
////            // }
////        }
////        for(int i = 0; i < 40005; ++i){
////            if(b[i]&&!a[i]){
////                ans.push_back(vector<int>{i,i});
////            }
////        }
////        return ans;
////    }
////};
//
//
//
///**************
//*
//*
//如果我们按照区间的左端点排序，那么在排完序的列表中，可以合并的区间一定是连续的。如下图所示，标记为蓝色、黄色和绿色的区间分别可以合并成一个大区间，它们在排完序的列表中是连续的：
//我们用数组 merged 存储最终的答案。
//
//首先，我们将列表中的区间按照左端点升序排序。然后我们将第一个区间加入 merged 数组中，并按顺序依次考虑之后的每个区间：
//
//如果当前区间的左端点在数组 merged 中最后一个区间的右端点之后，那么它们不会重合，我们可以直接将这个区间加入数组 merged 的末尾；
//
//否则，它们重合，我们需要用当前区间的右端点更新数组 merged 中最后一个区间的右端点，将其置为二者的较大值。
//
//
//作者：LeetCode-Solution
//        链接：https://leetcode-cn.com/problems/merge-intervals/solution/he-bing-qu-jian-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//*/
//
//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        if (intervals.size() == 0) {
//            return {};
//        }
//        sort(intervals.begin(), intervals.end());
//        vector<vector<int>> merged;
//        for (int i = 0; i < intervals.size(); ++i) {
//            int L = intervals[i][0], R = intervals[i][1];
//            if (!merged.size() || merged.back()[1] < L) {
//                merged.push_back({L, R});
//            }
//            else {
//                merged.back()[1] = max(merged.back()[1], R);
//            }
//        }
//        return merged;
//    }
//};
//
//
//int main(){
//    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
//    Solution().merge(intervals);
//    return 0;
//}