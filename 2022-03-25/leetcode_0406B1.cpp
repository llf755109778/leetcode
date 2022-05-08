////
//// Created by 75510 on 2022/3/25.
////
//
//#include "bits/stdc++.h"
//using namespace std;
///*********
// * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。
// * 每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
// * 请你重新构造并返回输入数组people 所表示的队列。
// * 返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
// */
//
//class Solution {
//public:
//    static bool cmp(vector<int>& a,vector<int>& b){
//        return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
//    }
//
//    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//        return help2(people);
//    }
//
//    /******
//     * 朴素解法
//     * @param people
//     * @return
//     */
//    vector<vector<int>> help1(vector<vector<int>>& people) {
//        vector<vector<int>> ans;
//        std::sort(people.begin(), people.end(),cmp);
//        for(int i = 0; i < people.size(); ++i){
//            ans.insert(ans.begin() + people[i][1],people[i]);
//        }
//        return ans;
//    }
//
//
//    /********
//     * 插入优化
//     * @param people
//     * @return
//     */
//    vector<vector<int>> help2(vector<vector<int>>& people) {
//        int n=people.size();
//        vector<vector<int>> ans(n);
//        sort(people.begin(),people.end(),[](vector<int>& a,vector<int>& b){
//            if(a[0]!=b[0])return a[0]<b[0];
//            return a[1]>b[1];
//        });
//        vector<int> index(n);
//        for(int i=0;i<n;++i)index[i]=i;
//        for(int i=0;i<n;++i){
//            int t=people[i][1];
//            ans[index[t]]=people[i];
//            index.erase(index.begin()+t);
//        }
//        return ans;
//    }
//    /***********
//     * 线段树
//     * @param people
//     * @return
//     */
//    vector<vector<int>> help3(vector<vector<int>>& people) {
//
//        int i, n=people.size(), pos;
//        vector<vector<int>> ret(n);
//        sort(people.begin(), people.end(), comp);
//
//
//        SegmentTree obj(n);
//        for (i=0; i<n; i++) {
//            pos = obj.getCorrectSlot(people[i][1]+1);
//            obj.removeSlot(pos);
//            ret[pos] = people[i];
//        }
//        return ret;
//    }
//
//
//    class SegmentTree{
//    private:
//        int n, N;
//        vector<int> segTree;
//        int getMid(int l, int h) { return l+(h-l)/2; }
//        int getLeftChild(int i)  { return 2*i+1; }
//        int getRightChild(int i) { return 2*i+2; }
//
//        int buildSegTree(int root, int low, int high) {
//            if (low>high) return 0;
//            if (low==high) return segTree[root] = 1;
//            int mid=getMid(low, high);
//            return segTree[root] = buildSegTree(getLeftChild(root), low, mid) +
//                                   buildSegTree(getRightChild(root), mid+1, high);
//        }
//        int getIdx(int root, int low, int high, int x) {
//            if (low==high) return low;
//            int left=getLeftChild(root), right=getRightChild(root), mid=getMid(low, high);
//            if (x<=segTree[left]) return getIdx(left, low, mid, x);
//            return getIdx(right, mid+1, high, x-segTree[left]);
//        }
//        void update(int root, int low, int high, int i) {
//            if (low==high) {
//                segTree[root] = 0;
//                return;
//            }
//            int left=getLeftChild(root), right=getRightChild(root), mid=getMid(low, high);
//            if (i<=mid) update(left, low, mid, i);
//            else        update(right, mid+1, high, i);
//            segTree[root] = segTree[left] + segTree[right];
//            return;
//        }
//    public:
//        SegmentTree (int n) {
//            this->n = n;
//            N = 4*n+1;
//            segTree = vector<int>(N, 0);
//            buildSegTree(0, 0, n-1);
//        }
//        int getCorrectSlot(int x) {
//            return getIdx(0, 0, n-1, x);
//        }
//        void removeSlot(int i) {
//            update(0, 0, n-1, i);
//            return;
//        }
//    };
//
//    static bool comp(const vector<int>&v1, const vector<int>&v2)  {
//        if (v1[0]==v2[0]) return (v1[1]>v2[1]);
//        return (v1[0]<v2[0]);
//    }
//
//
//
//};
//
//int main(){
//
//    vector<vector<int>> people{{9,0},{7,0},{1,9},{3,0},{2,7},{5,3},{6,0},{3,4},{6,2},{5,2}};
//    Solution().reconstructQueue(people);
//    return 1;
//}