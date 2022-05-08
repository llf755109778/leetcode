////
//// Created by 75510 on 2022/3/20.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        return help2(headA, headB);
//    }
//
//    ListNode *help1(ListNode *headA, ListNode *headB){
//        ListNode *A=headA,*B=headB;
//        while (A!=B){
//            A = A == nullptr?headB:A->next;
//            B = B == nullptr?headA:B->next;
//        }
//        return A;
//    }
//
//    ListNode *help2(ListNode *headA, ListNode *headB){
//        ListNode *A=headA,*B=headB;
//        int lenA = 0, lenB = 0;
//        while (A){
//            A=A->next;
//            ++lenA;
//        }
//        while (B){
//            B=B->next;
//            ++lenB;
//        }
//        A=headA,B=headB;
//        if(lenA<lenB){
//            swap(A,B);
//        }
//        for (int i = 0; i < abs(lenA - lenB); ++i){
//            A = A->next;
//        }
//        while (A!=B){
//            A = A->next;
//            B = B->next;
//        }
//        return A;
//    }
//
//};
//
//int stringToInteger(string input) {
//    return stoi(input);
//}
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
//        int intersectVal = stringToInteger(line);
//        getline(cin, line);
//        ListNode* listA = stringToListNode(line);
//        getline(cin, line);
//        ListNode* listB = stringToListNode(line);
//        getline(cin, line);
//        int skipA = stringToInteger(line);
//        getline(cin, line);
//        int skipB = stringToInteger(line);
//
//        ListNode* ret = Solution().getIntersectionNode(listA, listB);
//
//        string out = listNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}