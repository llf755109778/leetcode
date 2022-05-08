////
//// Created by 75510 on 2022/3/21.
////
//
//#include "bits/stdc++.h"
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
//    bool isPalindrome(ListNode* head) {
//        return help2(head);
//    }
//
//    /***
//     * 递归
//     * @param head
//     * @return
//     */
//    ListNode* frontPointer;
//    bool help2(ListNode* head) {
//        frontPointer = head;
//        return recursivelyCheck(head);
//    }
//
//    bool recursivelyCheck(ListNode* head){
//        if(head == nullptr){
//            return true;
//        }
//        if(recursivelyCheck(head->next)){
//            if(frontPointer->val==head->val){
//                frontPointer = frontPointer->next;
//                return true;
//            } else{
//                return false;
//            }
//        }
//
//    }
//
//
//
//    /****
//     * 快慢指针+反转链表
//     *
//     */
//    bool help1(ListNode* head) {
//
//        if (head == nullptr) {
//            return true;
//        }
//
//        // 找到前半部分链表的尾节点并反转后半部分链表
//        ListNode *firstHalfEnd = endOfFirstHalf(head);
//        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);
//
//        // 判断是否回文
//        ListNode *p1 = head;
//        ListNode *p2 = secondHalfStart;
//        bool result = true;
//        while (result && p2 != nullptr) {
//            if (p1->val != p2->val) {
//                result = false;
//            }
//            p1 = p1->next;
//            p2 = p2->next;
//        }
//
//        // 还原链表并返回结果
//        firstHalfEnd->next = reverseList(secondHalfStart);
//        return result;
//    }
//
//    ListNode *reverseList(ListNode *head) {
//        ListNode *prev = nullptr;
//        ListNode *curr = head;
//        while (curr != nullptr) {
//            ListNode *nextTemp = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = nextTemp;
//        }
//        return prev;
//    }
//
//    ListNode* endOfFirstHalf(ListNode* head) {
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while (fast->next != nullptr && fast->next->next != nullptr) {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
//};
//
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
//string boolToString(bool input) {
//    return input ? "True" : "False";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        ListNode* head = stringToListNode(line);
//
//        bool ret = Solution().isPalindrome(head);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}