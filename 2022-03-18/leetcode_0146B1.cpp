////
//// Created by 75510 on 2022/3/18.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//
//
//class LRUCache {
//public:
//    unordered_map<int ,list<pair<int, int>>::iterator> map;
//    list<pair<int, int>> l;
//    int capacity;
//    int size;
//    LRUCache(int capacity) {
//        this->capacity = capacity;
//        size = 0;
//    }
//
//    int get(int key) {
//        if(map.find(key)!=map.end()){
//            int temp = (*map.find(key)->second).second;
//            l.erase(map[key]);
//            map[key] = l.insert(l.begin(),pair<int, int>(key, temp));
//        } else{
//            return -1;
//        }
//        return map.find(key)->second->second;
//    }
//
//    void put(int key, int value) {
//        if(map.find(key)!=map.end()){
//            l.erase(map[key]);
//            map.erase(key);
//        } else{
//            if(size==capacity){
//                --size;
//                int tmp = l.back().first;
//                l.pop_back();
//                map.erase(tmp);
//            }
//            size++;
//        }
//        auto tmp = l.insert(l.begin(),pair<int, int>(key, value));
//        map[key] = tmp;
//    }
//
//
//};
//
//
//int main(){
//    string str;
//    int i;
//    LRUCache* l;
//    while(true){
//        cin >> str;
//        if(str=="1"){
//            cin >> i;
//            l = new LRUCache(i);
//        } else if(str=="2"){
//            cin >> i;
//            cout << "get " << l->get(i) << endl;
//        } else{
//            cin >> i;
//            int tmp;
//            cin >> tmp;
//            l->put(i,tmp);
////            for(auto i:l->l){
////                cout << i;
////            }
//        }
//    }
//}