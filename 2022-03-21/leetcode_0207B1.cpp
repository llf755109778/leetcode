////
//// Created by 75510 on 2022/3/21.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    vector<vector<int>> g;
//    vector<int> visited;
//    bool valid = true;
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        g.resize(numCourses);
//        visited.resize(numCourses);
//        for(auto item:prerequisites){
//            for(int i = 1; i < item.size(); ++i){
//                g[item[0]].push_back(item[i]);
//            }
//        }
//
//        stack<int> s,ans;
//        for(int i = 0; i < numCourses; ++i){
//            if(!visited[i])
//                dfs(i);
//        }
//    }
//
//
//    void dfs(int u) {
//        visited[u] = 1;
//        for(auto i:g[u]){
//            if(visited[i]==0){
//                dfs(i);
//                if(!valid){
//                    return;
//                }
//            } else if(visited[i] == 1){
//                valid = false;
//                return;
//            }
//        }
//        visited[u] = 2;
//    }
//};