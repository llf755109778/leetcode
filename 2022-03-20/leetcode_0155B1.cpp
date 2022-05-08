////
//// Created by 75510 on 2022/3/20.
////
//#include "bits/stdc++.h"
//using namespace std;
//
//class MinStack {
//public:
//    stack<long long> s;
//    long long mn;
//    MinStack() {
//        mn = INT_MAX;
//    }
//
//    void push(int val) {
//        s.push(val-mn);
//        if(val<mn){
//            mn = val;
//        }
//    }
//
//    void pop() {
//        if(s.top()<0){
//            mn = mn - s.top();
//        }
//        s.pop();
//    }
//
//    int top() {
//        return s.top()<0?mn:mn+s.top();
//    }
//
//    int getMin() {
//        return mn;
//    }
//};