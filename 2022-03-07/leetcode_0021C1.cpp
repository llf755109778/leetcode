//
// Created by 75510 on 2022/3/7.
//

#include "bits/stdc++.h"
using namespace std;

//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

/***********
 *
 * 不破坏原有数据
 *
 * @param input
 */
//
//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* res= nullptr;
//        ListNode* next = nullptr;
//        while (list1&&list2){
//            ListNode* tmp;
//            if(list1->val>list2->val){
//                tmp = new ListNode(list2->val);
//                list2=list2->next;
//            } else{
//                tmp = new ListNode(list1->val);
//                list1=list1->next;
//            }
//            if(!res){
//                res = next = tmp;
//            } else{
//                next->next=tmp;
//                next=tmp;
//            }
//        }
//        while (list1){
//            ListNode* tmp;
//            tmp = new ListNode(list1->val);
//            list1=list1->next;
//            if(!res){
//                res = next = tmp;
//            } else{
//                next->next=tmp;
//                next=tmp;
//            }
//        }
//        while (list2){
//            ListNode* tmp = nullptr;
//            tmp = new ListNode(list2->val);
//            list2=list2->next;
//
//            if(!res){
//                res = next = tmp;
//            } else{
//                next->next=tmp;
//                next=tmp;
//            }
//        }
//        return res;
//    }
//};


/***********
 *
 * 破坏原有数据
 *      递归
 * @param input
 */

//class Solution {
//public:
//    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        if(!list1){
//            return list2;
//        }
//        if(!list2){
//            return list1;
//        }
//        if(list1->val<list2->val){
//            list1->next = mergeTwoLists(list1->next,list2);
//            return list1;
//        } else{
//            list2->next = mergeTwoLists(list1,list2->next);
//            return list2;
//        }
//    }
//};





//void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
//}
//
//void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {
//    vector<int> output;
//    trimLeftTrailingSpaces(input);
//    trimRightTrailingSpaces(input);
//    input = input.substr(1, input.length() - 2);
//    stringstream ss;
//    ss.str(input);
//    string item;
//    char delim = ',';
//    while (getline(ss, item, delim)) {
//        output.push_back(stoi(item));
//    }
//    return output;
//}
//
//ListNode* stringToListNode(string input) {
//    // Generate list from the input
//    vector<int> list = stringToIntegerVector(input);
//
//    // Now convert that list into linked list
//    ListNode* dummyRoot = new ListNode(0);
//    ListNode* ptr = dummyRoot;
//    for(int item : list) {
//        ptr->next = new ListNode(item);
//        ptr = ptr->next;
//    }
//    ptr = dummyRoot->next;
//    delete dummyRoot;
//    return ptr;
//}
//
//string listNodeToString(ListNode* node) {
//    if (node == nullptr) {
//        return "[]";
//    }
//
//    string result;
//    while (node) {
//        result += to_string(node->val) + ", ";
//        node = node->next;
//    }
//    return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        ListNode* list1 = stringToListNode(line);
//        getline(cin, line);
//        ListNode* list2 = stringToListNode(line);
//
//        ListNode* ret = Solution().mergeTwoLists(list1, list2);
//
//        string out = listNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}