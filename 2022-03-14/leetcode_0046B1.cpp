////
//// Created by 75510 on 2022/3/14.
////
//#include <bits/stdc++.h>
//using namespace std;
//class Solution {
//public:
//    vector<vector<int>> res;
//    int a[10];
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<int> ans;
//        dfs(nums,ans);
//        return res;
//    }
//
//    void dfs(vector<int>& nums,vector<int>& ans){
//        if(ans.size()==nums.size()){
//            res.push_back(ans);
//            return;
//        }
//        for(int i = 0; i < nums.size(); ++i){
//            if(!a[i]){
//                a[i]=1;
//                ans.push_back(nums[i]);
//                dfs(nums,ans);
//                ans.pop_back();
//                a[i]=0;
//            }
//        }
//    }
//};
//
//
//int main() {
//    vector<int> v {1,2,3};
//    (new Solution())->permute(v);
//    return 0;
//}