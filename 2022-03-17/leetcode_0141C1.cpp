////
//// Created by 75510 on 2022/3/17.
////
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
//    bool hasCycle(ListNode* head) {
//        if (head == nullptr || head->next == nullptr) {
//            return false;
//        }
//        ListNode* slow = head;
//        ListNode* fast = head->next;
//        while (slow != fast) {
//            if (fast == nullptr || fast->next == nullptr) {
//                return false;
//            }
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return true;
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
//int stringToInteger(string input) {
//    return stoi(input);
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
//        getline(cin, line);
//        int pos = stringToInteger(line);
//
//        bool ret = Solution().hasCycle(head, pos);
//
//        string out = boolToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}