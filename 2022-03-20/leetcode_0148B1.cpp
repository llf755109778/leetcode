////
//// Created by 75510 on 2022/3/20.
////
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
//
//
//class Solution {
//public:
//    ListNode* sortList(ListNode* head) {
//        if (head == nullptr) {
//            return head;
//        }
//        int length = 0;
//        ListNode* node = head;
//        while (node != nullptr) {
//            length++;
//            node = node->next;
//        }
//        ListNode* dummyHead = new ListNode(0, head);
//        for (int subLength = 1; subLength < length; subLength <<= 1) {
//            ListNode* prev = dummyHead, *curr = dummyHead->next;
//            while (curr != nullptr) {
//                ListNode* head1 = curr;
//                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
//                    curr = curr->next;
//                }
//                ListNode* head2 = curr->next;
//                curr->next = nullptr;
//                curr = head2;
//                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
//                    curr = curr->next;
//                }
//                ListNode* next = nullptr;
//                if (curr != nullptr) {
//                    next = curr->next;
//                    curr->next = nullptr;
//                }
//                ListNode* merged = merge(head1, head2);
//                prev->next = merged;
//                while (prev->next != nullptr) {
//                    prev = prev->next;
//                }
//                curr = next;
//            }
//        }
//        return dummyHead->next;
//    }
//
//    ListNode* merge(ListNode* head1, ListNode* head2) {
//        ListNode* dummyHead = new ListNode(0);
//        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
//        while (temp1 != nullptr && temp2 != nullptr) {
//            if (temp1->val <= temp2->val) {
//                temp->next = temp1;
//                temp1 = temp1->next;
//            } else {
//                temp->next = temp2;
//                temp2 = temp2->next;
//            }
//            temp = temp->next;
//        }
//        if (temp1 != nullptr) {
//            temp->next = temp1;
//        } else if (temp2 != nullptr) {
//            temp->next = temp2;
//        }
//        return dummyHead->next;
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
//        ListNode* head = stringToListNode(line);
//
//        ListNode* ret = Solution().sortList(head);
//
//        string out = listNodeToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}