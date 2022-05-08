////
//// Created by 75510 on 2022/3/25.
////
//#include "bits/stdc++.h"
//using namespace std;
//
/*********
 * 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序
 */
//class Solution {
//public:
//    vector<int> findAnagrams(string s, string p) {
//        if(s.size() < p.size()){
//            return {};
//        }
//        int a[26]{};
//        int b[26]{};
//        vector<int> ans;
//        int pSize = p.size();
//        for(int i = 0; i < p.size(); ++i){
//            a[p[i] - 'a']++;
//            b[p[i] - 'a']++;
//        }
//        int r=0,l=0;
//        int cnt=0;
//        while (r<s.size()){
//            if(b[s[r] - 'a']){
//                a[s[r] - 'a']--;
//                cnt++;
//            } else{
//                l = r + 1;
//                for(int i = 0; i < p.size(); ++i){
//                    a[p[i] - 'a'] = b[p[i] - 'a'];
//                }
//                cnt=0;
//            }
//            while (a[s[r] - 'a'] < 0){
//                if(b[s[l] - 'a'])
//                    a[s[l] - 'a']++,cnt--;
//                l++;
//            }
//            ++r;
//            if(cnt==pSize){
//                ans.push_back(l);
//                a[s[l] - 'a']++,cnt--;
//                l++;
//            }
//        }
//        return ans;
//    }
//
//    /****
//     *  一种经典思路是初始化p的字符数组然后维护数组每个元素不小于0。
//     *  开始向右滑动窗口，减去并相应字符，如果频率小于0就收缩左侧边界直到频率不再小于0
//     * @param s
//     * @param p
//     * @return
//     */
//    vector<int> help1(string s, string p) {
//        int m = s.size(), n = p.size();
//        if(m < n) return {};
//        vector<int> hashTable(26);
//        for(auto ch : p) ++hashTable[ch - 'a'];
//        vector<int> ret;
//        for(int l = 0, r = 0; r < m; ++r) {
//            --hashTable[s[r] - 'a'];
//            while(hashTable[s[r] - 'a'] < 0) {
//                ++hashTable[s[l] - 'a'];
//                ++l;
//            }
//            if(r - l + 1 == n) ret.push_back(l);
//        }
//        return ret;
//    }
//
//    /*******
//     * 在方法一的基础上，我们不再分别统计滑动窗口和字符串 p 中每种字母的数量，而是统计滑动窗口和字符串 p 中每种字母数量的差；
//     * 并引入变量differ 来记录当前窗口与字符串 p 中数量不同的字母的个数，并在滑动窗口的过程中维护它。
//     * 在判断滑动窗口中每种字母的数量与字符串 p 中每种字母的数量是否相同时，只需要判断differ 是否为零即可。
//     * @param s
//     * @param p
//     * @return
//     */
//    vector<int> help3(string s, string p) {
//        int sLen = s.size(), pLen = p.size();
//
//        if (sLen < pLen) {
//            return vector<int>();
//        }
//
//        vector<int> ans;
//        vector<int> count(26);
//        for (int i = 0; i < pLen; ++i) {
//            ++count[s[i] - 'a'];
//            --count[p[i] - 'a'];
//        }
//
//        int differ = 0;
//        for (int j = 0; j < 26; ++j) {
//            if (count[j] != 0) {
//                ++differ;
//            }
//        }
//
//        if (differ == 0) {
//            ans.emplace_back(0);
//        }
//
//        for (int i = 0; i < sLen - pLen; ++i) {
//            if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
//                --differ;
//            } else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
//                ++differ;
//            }
//            --count[s[i] - 'a'];
//
//            if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
//                --differ;
//            } else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
//                ++differ;
//            }
//            ++count[s[i + pLen] - 'a'];
//
//            if (differ == 0) {
//                ans.emplace_back(i + 1);
//            }
//        }
//
//        return ans;
//    }
//
//};
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
//string integerVectorToString(vector<int> list, int length = -1) {
//    if (length == -1) {
//        length = list.size();
//    }
//
//    if (length == 0) {
//        return "[]";
//    }
//
//    string result;
//    for(int index = 0; index < length; index++) {
//        int number = list[index];
//        result += to_string(number) + ", ";
//    }
//    return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
//int main() {
//    string line;
//    while (getline(cin, line)) {
//        string s = stringToString(line);
//        getline(cin, line);
//        string p = stringToString(line);
//
//        vector<int> ret = Solution().findAnagrams(s, p);
//
//        string out = integerVectorToString(ret);
//        cout << out << endl;
//    }
//    return 0;
//}