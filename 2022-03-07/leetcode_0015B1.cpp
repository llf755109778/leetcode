//
// Created by 75510 on 2022/3/7.
//

//#include <bits/stdc++.h>
//using namespace std;


///******
// *
// * 暴力哈希
// *
// */
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> res;
//        vector<int> numss;
//        int flag = 1;
//        unordered_map<int ,int> s;
//        for(auto i:nums ){
//            s[i]++;
//            if(s[i]==0||s[i]<=2){
//                numss.push_back(i);
//            }
//        }
//        sort(numss.begin(),numss.end());
//        for(auto &i:numss ){
//            cout << i << " ";
//        }
//        cout << endl;
//        int pre=-1111111;
//        for(int i = 0; i < numss.size(); ++i){
//            if(numss[i]>0){
//                break;
//            }
//            if(pre==numss[i]){
//                continue;
//            }
//            pre = numss[i];
//            int pp = -1111111;
//            for(int j = i + 1; j < numss.size(); ++j){
//                if(pp==numss[j]){
//                    continue;
//                }
//                if((numss[i]+2*numss[j])>0){
//                    break;
//                } else if(s.find(-numss[i]-numss[j])!=s.end()){
//                    if(numss[i]==0){
//                        if(flag&&s.find(0)->second>=3){
//                            res.push_back(vector<int>(3,0));
//                            flag = 0;
//                        }
//                    } else if((numss[i]+2*numss[j])==0){
//                        if(s.find(numss[j])->second>=2){
//                            pp = numss[j];
//                            vector<int> v;
//                            v.push_back(numss[i]);
//                            v.push_back(numss[j]);
//                            v.push_back(numss[j]);
//                            res.push_back(v);
//                            cout << endl << "X " << i << " " << j;
//                        }
//                    } else{
//                        vector<int> v;
//                        pp = numss[j];
//                        v.push_back(numss[i]);
//                        v.push_back(numss[j]);
//                        v.push_back(-numss[i]-numss[j]);
//                        res.push_back(v);
//                        cout << endl << "Y " << i << " " << j << "     " << numss[i] << " " << 2*numss[j] << endl;
//                    }
//                }
//            }
//        }
//        return res;
//    }
//};


///***
// *
// *
// *   排序 + 双指针
////1.先对数组排序，第三个数从 n - 1 位置开始，即 tail = n - 1，先固定 tail ,比较 第一个数 i = 0, 第二个数 j = tail - 1，
////    若 nums[i] + nums[j] == 0 - nums[tail], 收集 三元组{nums[i],nums[j],nums[k]},
////并将 i 后移，注意要跳过连续相等的数；
////    若 nums[i] + nums[j] > 0 - nums[tail] , --j
////    若 nums[i] + nums[j] <  0 - nums[tail] , ++i
//
// 代码不一定是  排序 + 双指针 （没看）
// */
//
//
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        std::sort(nums.begin(),nums.end());
//        const int n = nums.size();
//        vector<vector<int>> ans;
//        for(int tail = n - 1; tail > 1; tail--){
//            if(tail + 1 < n && nums[tail] == nums[tail+1]){//去重 1
//                continue;
//            }
//            int i = 0, j = tail - 1;
//            int sum = 0 - nums[tail];
//            while(i < j){
//                if(nums[i] + nums[j] == sum){
//                    ans.push_back({nums[i],nums[j],nums[tail]});
//                    while(i < j && nums[i] == nums[i+1]) i++; // 去重 2
//                    i++;
//                }
//                else if(nums[i] + nums[j] < sum){
//                    i++;
//                }
//                else{
//                    j--;
//                }
//            }
//        }
//        return ans;
//    }
//};