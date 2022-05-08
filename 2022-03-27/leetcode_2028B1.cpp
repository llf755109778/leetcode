// //
// // Created by 75510 on 2022/3/27.
// //
// #include "bits/stdc++.h"
// using namespace std;


// /***********
// * 现有一份 n + m次投掷单个 六面 骰子的观测数据，骰子的每个面从 1 到 6 编号。观测数据中缺失了 n 份，你手上只拿到剩余m 次投掷的数据。
// * 幸好你有之前计算过的这 n + m 次投掷数据的 平均值 。给你一个长度为 m 的整数数组 rolls ，其中rolls[i] 是第 i 次观测的值。
// * 同时给你两个整数 mean 和 n 。返回一个长度为 n 的数组，包含所有缺失的观测数据，且满足这 n + m 次投掷的 平均值 是 mean
// * 。如果存在多组符合要求的答案，只需要返回其中任意一组即可。如果不存在答案，返回一个空数组。k个数字的 平均值 为这些数字求和后再除以k 。
// * 注意 mean 是一个整数，所以 n + m 次投掷的总和需要被 n + m 整除。
// */
// class Solution {
// public:
//    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//        int ans=0;
//        for(int i = 0; i < rolls.size(); ++i){
//            ans+=rolls[i];
//        }
//        int sum = mean * (rolls.size()+n);
//        if((sum - ans)>6*n || (sum - ans)<n){
//            return {};
//        }
//        int mn = (sum - ans)/n;
//        vector<int> res(n,mn);
//        for(int i = 0; i < (sum - ans)%n; ++i){
//            res[i]+=1;
//        }
//        return res;
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

// int stringToInteger(string input) {
//    return stoi(input);
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
//        vector<int> rolls = stringToIntegerVector(line);
//        getline(cin, line);
//        int mean = stringToInteger(line);
//        getline(cin, line);
//        int n = stringToInteger(line);

//        vector<int> ret = Solution().missingRolls(rolls, mean, n);

//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
// }
