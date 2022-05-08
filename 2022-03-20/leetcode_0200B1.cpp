////
//// Created by 75510 on 2022/3/20.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    int ans=0;
//    int numIslands(vector<vector<char>>& grid) {
//        for(int i = 0; i < grid.size(); ++i){
//            for(int j = 0; j < grid[0].size(); ++j){
//                if(grid[i][j]=='1'){
//                    grid[i][j]='0';
//                    bfs(i,j,grid);
//                    ans++;
//                }
//            }
//        }
//        return ans;
//    }
//
//    int help2(vector<vector<char>>& grid) {
//        int nr = grid.size();
//        if (!nr) return 0;
//        int nc = grid[0].size();
//
//        int num_islands = 0;
//        for (int r = 0; r < nr; ++r) {
//            for (int c = 0; c < nc; ++c) {
//                if (grid[r][c] == '1') {
//                    ++num_islands;
//                    grid[r][c] = '0';
//                    queue<pair<int, int>> neighbors;
//                    neighbors.push({r, c});
//                    while (!neighbors.empty()) {
//                        auto rc = neighbors.front();
//                        neighbors.pop();
//                        int row = rc.first, col = rc.second;
//                        if (row - 1 >= 0 && grid[row-1][col] == '1') {
//                            neighbors.push({row-1, col});
//                            grid[row-1][col] = '0';
//                        }
//                        if (row + 1 < nr && grid[row+1][col] == '1') {
//                            neighbors.push({row+1, col});
//                            grid[row+1][col] = '0';
//                        }
//                        if (col - 1 >= 0 && grid[row][col-1] == '1') {
//                            neighbors.push({row, col-1});
//                            grid[row][col-1] = '0';
//                        }
//                        if (col + 1 < nc && grid[row][col+1] == '1') {
//                            neighbors.push({row, col+1});
//                            grid[row][col+1] = '0';
//                        }
//                    }
//                }
//            }
//        }
//
//        return num_islands;
//    }
//    void bfs(int x,int y,vector<vector<char>>& grid){
//        int length=grid[0].size(),wide=grid.size();
//        vector<vector<int>> dirt{{0,1},{0,-1},{1,0},{-1,0}};
//        queue<pair<int,int>> q;
//        q.push({x,y});
//        while (!q.empty()){
//            pair<int,int> tmp = q.front();
//            int i = tmp.first;
//            int j = tmp.second;
//            q.pop();
//            for(auto item:dirt){
//                if(i + item[0] >= 0 && i + item[0] < wide && j + item[1] >= 0 && j + item[1] < length && grid[i + item[0]][j + item[1]]=='1'){
//                    q.push({i + item[0],j + item[1]});
//                    grid[i + item[0]][j + item[1]]='0';
//                }
//            }
//
//        }
//    }
//
//};
//
//
//int main(){
//    vector<vector<char>> grid = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'},{'0','0','0','0','0'}};
//    cout << Solution().numIslands(grid) << endl;
//    return 0;
//}