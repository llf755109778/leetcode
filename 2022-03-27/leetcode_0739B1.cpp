// //
// // Created by 75510 on 2022/3/27.
// //
// #include "bits/stdc++.h"
// using namespace std;

// /**********
// * 给定一个整数数组temperatures，表示每天的温度，返回一个数组answer，
// * 其中answer[i]是指在第 i 天之后，才会有更高的温度。如果气温在这之后都不会升高，请在该位置用0 来代替。
// */
// class Solution {
// public:
//    vector<int> dailyTemperatures(vector<int>& temperatures) {
//        stack<int> s;
//        vector<int> v(temperatures.size());
//        for(int i = 0; i < temperatures.size(); i++){
//            int cnt = 1;
//            while (!s.empty()&&temperatures[s.top()]<temperatures[i]){
//                v[s.top()] = i - s.top();
//                s.pop();
//            }
//            s.push(i);
//        }
//        while (!s.empty()){
//            v[s.top()] = 0;
//            s.pop();
//        }
//        return v;
//    }
// };

// void trimLeftTrailingSpaces(string &input) {
//    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
//        return !isspace(ch);
//    }));
// }

// void trimRightTrailingSpaces(string &input) {
//    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//        return !isspace(ch);
//    }).base(), input.end());
// }

// vector<int> stringToIntegerVector(string input) {
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
// }

// string integerVectorToString(vector<int> list, int length = -1) {
//    if (length == -1) {
//        length = list.size();
//    }

//    if (length == 0) {
//        return "[]";
//    }

//    string result;
//    for(int index = 0; index < length; index++) {
//        int number = list[index];
//        result += to_string(number) + ", ";
//    }
//    return "[" + result.substr(0, result.length() - 2) + "]";
// }

// int main() {
//    string line;
//    while (getline(cin, line)) {
//        vector<int> temperatures = stringToIntegerVector(line);

//        vector<int> ret = Solution().dailyTemperatures(temperatures);

//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
// }