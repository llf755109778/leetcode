////
//// Created by 75510 on 2022/3/15.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//class Solution {
//public:
//    int a[10][10];
//    bool exist(vector<vector<char>>& board, string word) {
//        for(int i = 0; i < board.size(); ++i){
//            for(int j = 0; j < board[0].size(); ++j){
//                if(board[i][j] == word[0]){
//                    if(dfs(board,word,1,i,j)){
//                        return 1;
//                    }
//                    a[i][j] = 0;
//                }
//            }
//        }
//        return 0;
//    }
//
//    bool dfs(vector<vector<char>>& board, string word, int deep,int i,int j){
//        a[i][j]=1;
//        if(deep == word.size()){
//            return true;
//        }
//        if(i){
//            if(!a[i-1][j]&&board[i-1][j]==word[deep]){
//                if(dfs(board,word,deep+1,i-1,j)){
//                    return 1;
//                }
//                a[i-1][j] = 0;
//            }
//        }
//        if(j){
//            if(!a[i][j-1]&&board[i][j-1]==word[deep]){
//                if(dfs(board,word,deep+1,i,j-1)){
//                    return 1;
//                }
//                a[i][j-1] = 0;
//            }
//        }
//        if(i<board.size()-1){
//            if(!a[i+1][j]&&board[i+1][j]==word[deep]){
//                if(dfs(board,word,deep+1,i+1,j)){
//                    return 1;
//                }
//                a[i+1][j] = 0;
//            }
//        }
//        if(j<board[0].size()-1){
//            if(!a[i][j+1]&&board[i][j+1]==word[deep]){
//                if(dfs(board,word,deep+1,i,j+1)){
//                    return 1;
//                }
//                a[i][j+1] = 0;
//            }
//        }
//        return false;
//    }
//};
//
//
//
//int main(){
////    vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//    vector<vector<char>> board {{'A'}};
//
////    string word = "SEE";
//    string word = "b";
//    cout << Solution().exist(board,word);
//}