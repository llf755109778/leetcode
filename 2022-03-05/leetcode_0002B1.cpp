////
//// Created by 75510 on 2022/3/5.
////
//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        queue<int> str1,str2;
//        ListNode *next = nullptr;
//        if(l1 != nullptr){
//            next = l1->next;
//            str1.push(l1->val);
//        }
//        while (next != nullptr){
//            str1.push(next->val);
//            next = next->next;
//        }
//        next = nullptr;
//        if(l2 != nullptr){
//            next = l2->next;
//            str2.push(l2->val);
//        }
//        while (next != nullptr){
//            str2.push(next->val);
//            next = next->next;
//        }
//        ListNode* res= nullptr;
//        next = nullptr;
//        int add = 0;
//        while (!str1.empty()&&!str2.empty()){
//            int sum = str1.front() + str2.front() + add;
//            str2.pop(),str1.pop();
//            ListNode* tmp = new ListNode(sum % 10, nullptr);
//            add = sum / 10;
//            if(res != nullptr){
//                next->next = tmp;
//                next = tmp;
//            } else{
//                res = next = tmp;
//            }
//        }
//        while (!str1.empty()){
//            int sum = str1.front() + add;
//            str1.pop();
//            ListNode* tmp = new ListNode(sum % 10, nullptr);
//            add = sum / 10;
//            if(res != nullptr){
//                next->next = tmp;
//                next = tmp;
//            } else{
//                res = next = tmp;
//            }
//        }
//        while(!str2.empty()){
//            int sum = str2.front() + add;
//            str2.pop();
//            ListNode* tmp = new ListNode(sum % 10, nullptr);
//            add = sum / 10;
//            if(res != nullptr){
//                next->next = tmp;
//                next = tmp;
//            } else{
//                res = next = tmp;
//            }
//        }
//        if(add){
//            next->next = new ListNode(1);
//        }
//        return res;
//    }
//};
//
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
//        ListNode* l1 = stringToListNode(line);
//        getline(cin, line);
//        ListNode* l2 = stringToListNode(line);
//
//        ListNode* ret = Solution().addTwoNumbers(l1, l2);
//
//        string out = listNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}




//原解法 二级指针指向新生成的结果链表，对两个链表相同节点进行计算
//（若原链表后续不在使用，可将数据存储到原链表减少部分内存）
//
//分别获取两个链表的相同位置指针，将两指针内数据相加并加上进位后算出当前位置值
//        将当前位置除10的余数作为新链表当前位置的值，当前位置除10的商作为进位保留到下一次运算
//
//        代码
/************************************
*class Solution {
*public:
*    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
*        int Carry = 0;// 计算当前节点计算结果并在计算完成后保留进位
*        ListNode* head = nullptr;// 返回数据头
*        ListNode** tempNode = &head;// 当前处理节点二级指针
*
*        while( l1 || l2 ){
*            // 获取当前值并移动指针（把计算和移动放到一起，减少一次判断次数）
*            if(l1){
*                Carry += l1->val;
*                l1 = l1->next;
*            }
*            if(l2){
*                Carry += l2->val;
*                l2 = l2->next;
*            }
*            // 计算当前位结果
*            *tempNode = new ListNode(Carry%10);// 初始化返回串的同位置节点
*            tempNode = &((*tempNode)->next);// 二级指针指向下一个需要处理的节点
*            Carry /= 10;// 移除本节点数值保留进位
*        }
*
*        // 当计算完成后还有一位进位（处理最后的进位）
*        if(Carry==1){
*            *tempNode = new ListNode(Carry);
*        }
*        return head;
*    }
*};
*****************************/

//二次优化，将求余和求商优化为减法和直接赋值；
//因为进位的数字最大不会超过19所以将求商和求余一起计算出来，加法运算比除法运算更快
//
//        代码
/***************
*class Solution {
*public:
*    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
*        int Carry = 0;// 计算当前节点计算结果并在计算完成后保留进位
*        ListNode* head = nullptr;// 记录需要返回的数据头
*        ListNode** tempNode = &head;// 当前处理节点二级指针
*
*        while( l1 || l2 ){
*            // 获取当前值并移动指针（把计算和移动放到一起，减少一次判断次数）
*            if(l1){
*                Carry += l1->val;
*                l1 = l1->next;
*            }
*            if(l2){
*                Carry += l2->val;
*                l2 = l2->next;
*            }
*            // 计算当前位结果及进位（进位加上两数之和最大为19）
*            if(Carry>=10){
*                *tempNode = new ListNode(Carry-10);// 当前节点值
*                Carry = 1;// 当大于等于10时进位为1（两数相加及进位最大为19，所以进位最大为1）
*            }else{
*                *tempNode = new ListNode(Carry);// 当前节点值
*                Carry = 0;// 小于10时进位为0
*            }
*            tempNode = &((*tempNode)->next);// 二级指针指向下一个需要处理的节点
*        }
*
*        // 当计算完成后还有一位进位（处理最后的进位）
*        if(Carry==1){
*            *tempNode = new ListNode(Carry);
*        }
*        return head;
*    }
*};
********************/