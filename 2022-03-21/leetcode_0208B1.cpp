//////
////// Created by 75510 on 2022/3/21.
//////
////#include "bits/stdc++.h"
////using namespace std;
////
////class Trie {
////public:
////    bool isEnd; //该结点是否是一个串的结束
////    Trie* next[26]; //字母映射表
////    Trie():isEnd(false),next{}{};
////    void insert(string word) {
////        Trie* tmp = this;
////        for(int i = 0; i < word.size(); ++i){
////            if(tmp->next[word[i] - 'a'] == nullptr){
////                tmp->next[word[i] - 'a'] = new Trie();
////            }
////            tmp = tmp->next[word[i] - 'a'];
////        }
////        tmp->isEnd = true;
////    }
////
////    bool search(string word) {
////        Trie* tmp = this;
////        for(int i = 0; i < word.size(); ++i){
////            if(tmp->next[word[i] - 'a'] == nullptr){
////                return false;
////            }
////            tmp = tmp->next[word[i] - 'a'];
////        }
////        return tmp->isEnd;
////    }
////
////    bool startsWith(string prefix) {
////        Trie* tmp = this;
////        for(int i = 0; i < prefix.size(); ++i){
////            if(tmp->next[prefix[i] - 'a'] == nullptr){
////                return false;
////            }
////            tmp = tmp->next[prefix[i] - 'a'];
////        }
////        return true;
////    }
////};
////
/////**
//// * Your Trie object will be instantiated and called as such:
//// * Trie* obj = new Trie();
//// * obj->insert(word);
//// * bool param_2 = obj->search(word);
//// * bool param_3 = obj->startsWith(prefix);
//// */
//#include "bits/stdc++.h"
//using namespace std;
//const int maxn = 1e5 + 50;
//bool vis[maxn];
//int son[maxn][26],idx;
//class Trie {
//public:
//    Trie() {
//        memset(vis,false,sizeof vis);
//        memset(son,0,sizeof son);
//        idx = 0;
//    }
//
//    void insert(string word) {
//        int p = 0;
//        for(auto x : word){
//            int u = x - 'a';
//            if(!son[p][u]) son[p][u] = ++idx;
//            p = son[p][u];
//        }
//        vis[p] = true;
//    }
//
//    bool search(string word) {
//        int p = 0;
//        for(auto x : word){
//            int u = x - 'a';
//            if(!son[p][u]) return false;
//            p = son[p][u];
//        }
//        return vis[p];
//    }
//
//    bool startsWith(string prefix) {
//        int p = 0;
//        for(auto x : prefix){
//            int u = x - 'a';
//            if(!son[p][u]) return false;
//            p = son[p][u];
//        }
//        return true;
//    }
//};
//
//int main(){
//    string str;
//    auto p = new Trie();
//    while (cin >> str)
//        p->insert(str);
//}