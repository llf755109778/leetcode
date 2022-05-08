////
//// Created by 75510 on 2022/3/6.
////
//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//
//
///**************************
// *  代码一  map优化
// */
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        unordered_map<char,int> map;
//        int start,len;
//        start = len = 0;
//        for(int i = 0; i < s.size(); i++){
//            if(map.find(s[i])!=map.end()){
//                start = max(map.find(s[i])->second + 1,start);
//            }
//            map[s[i]] = i;
//            len = max(len, i - start + 1);
//        }
//        return len;
//    }
//};





/**************
*

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        vector<int> vec(128, -1);
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (vec[int(tmpChar)] >= start)
            {
                start = vec[int(tmpChar)] + 1;
                length = end - start;
            }
            vec[int(tmpChar)] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
*/








/***********
 *
 * class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a[300]={0};

        int start=0,res = 0;
        for(int i = 0; i < s.size(); i++){

            while (a[s[i]] != 0){
                a[s[start]] = 0;
                start++;
            }
            a[s[i]] = 1;
            res = res > (i-start+1)?res:i-start+1;

        }
        return res;
    }
};

 */




//
//string stringToString(string input) {
//    assert(input.length() >= 2);
//    string result;
//    for (int i = 1; i < input.length() -1; i++) {
//        char currentChar = input[i];
//        if (input[i] == '\\') {
//            char nextChar = input[i+1];
//            switch (nextChar) {
//                case '\"': result.push_back('\"'); break;
//                case '/' : result.push_back('/'); break;
//                case '\\': result.push_back('\\'); break;
//                case 'b' : result.push_back('\b'); break;
//                case 'f' : result.push_back('\f'); break;
//                case 'r' : result.push_back('\r'); break;
//                case 'n' : result.push_back('\n'); break;
//                case 't' : result.push_back('\t'); break;
//                default: break;
//            }
//            i++;
//        } else {
//            result.push_back(currentChar);
//        }
//    }
//    return result;
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        string s = stringToString(line);
//
//        int ret = Solution().lengthOfLongestSubstring(s);
//
//        string out = to_string(ret);
//        cout << out << endl;
//    }
//    return 0;
//}
//
