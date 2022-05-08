////
//// Created by 75510 on 2022/3/18.
////
//
//#include "bits/stdc++.h"
//using namespace std;
//
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        return help3(s,wordDict);
//    }
//
//
//    /*********
//     * dp
//     *
//     * 我们定义 dp[i] 表示字符串 s 前 i 个字符组成的字符串 s[0..i-1]s[0..i−1] 是否能被空格拆分成若干个字典中出现的单词。
//     * 从前往后计算考虑转移方程，每次转移的时候我们需要枚举包含位置 i-1 的最后一个单词，
//     * 看它是否出现在字典中以及除去这部分的字符串是否合法即可。公式化来说，我们需要枚举 s[0..i-1] 中的分割点 j ，
//     * 看 s[0..j-1]组成的字符串 s_1 （默认 j = 0时 s_1为空串）和 s[j..i-1]组成的字符串 s_2是否都合法，
//     * 如果两个字符串均合法，那么按照定义 s_1和 s_2拼接成的字符串也同样合法。
//     * 由于计算到 dp[i] 时我们已经计算出了dp[0..i−1] 的值，因此字符串 s_1是否合法可以直接由 dp[j]得知，
//     * 剩下的我们只需要看 s_2是否合法即可，因此我们可以得出如下转移方程：
//            {dp}[i]={dp}[j]&&{check}(s[j..i-1])
//       其中 check(s[j..i−1]) 表示子串 s[j..i-1]是否出现在字典中。
//       对于检查一个字符串是否出现在给定的字符串列表里一般可以考虑哈希表来快速判断，同时也可以做一些简单的剪枝，
//       枚举分割点的时候倒着枚举，如果分割点 j 到 i 的长度已经大于字典列表里最长的单词的长度，
//       那么就结束枚举，但是需要注意的是下面的代码给出的是不带剪枝的写法。
//       对于边界条件，我们定义dp[0]=true 表示空串且合法。
//
//     * @param s
//     * @param wordDict
//     * @return
//     */
//    bool help1(string s, vector<string>& wordDict){
//        auto wordDictSet = unordered_set <string> ();
//        for (auto word: wordDict) {
//            wordDictSet.insert(word);
//        }
//
//        auto dp = vector <bool> (s.size() + 1);
//        dp[0] = true;
//        for (int i = 1; i <= s.size(); ++i) {
//            for (int j = 0; j < i; ++j) {
//                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
//                    dp[i] = true;
//                    break;
//                }
//            }
//        }
//        return dp[s.size()];
//    }
//
//
//    /*********
//     * dfs
//     * @param s
//     * @param wordDict
//     * @return
//     */
//    int flag[350]{};
//    unordered_set<string> set;
//    bool help2(string s, vector<string>& wordDict){
//        for(auto &item:wordDict){
//            set.insert(item);
//        }
//        return dfs(s,0);
//    }
//
//    bool dfs(string s, int start){
//        if(s.size()==start){
//            return true;
//        }
//        if(flag[start]){
//            return false;
//        }
//        for(int i = 1 ; i <= s.size() - start; ++i) {
//            if(!flag[start+i]&&set.find(s.substr(start,i))!=set.end()){
//                if(dfs(s, i + start)){
//                    return true;
//                }
//            }
//        }
//        flag[start]=1;
//        return false;
//    }
//
//
//
//    /*****
//     * 字典树Trie
//     * 最合适
//     */
//    struct TrieNode {
//        TrieNode* next[26];
//        bool isEnd;
//        TrieNode()
//        {
//            for (int i = 0; i < 26; i++)
//                next[i] = nullptr;
//            isEnd = false;
//        }
//    };
//    TrieNode* root;
//    int failMemo[301]; // 记录dfs中失败时对应的s中的index
//    bool help3(string s, vector<string>& wordDict) {
//        root = new TrieNode();
//        // 建树
//        for (auto& word : wordDict)
//        {
//            TrieNode* p = root;
//            for (auto& ch : word)
//            {
//                if (p->next[ch - 'a'] == nullptr)
//                    p->next[ch - 'a'] = new TrieNode();
//                p = p->next[ch - 'a'];
//            }
//            p->isEnd = true;
//        }
//        return dfs2(s, 0);
//    }
//    bool dfs2(string& s, int startPos)
//    {
//        if (failMemo[startPos] == 1) return false;
//        if (startPos == s.size()) return true;
//        TrieNode* p = root;
//        for (int i = startPos; i < s.size(); i++)
//        {
//            if (p->next[s[i] - 'a'] != nullptr)
//            {
//                p = p->next[s[i] - 'a'];
//                if (p->isEnd == true && dfs(s, i+1))
//                    return true;
//            }
//            else break;
//        }
//        failMemo[startPos] = 1;
//        return false;
//    }
//
//
//    /*****
//     *
//     * 优化dp
//     * 先铺一个单词，在第二个。。。。 使用可以优化
//     for (int i = 0; i < len; i++)
//        {
//            for (int j = i + 1; j <= len; j++)
//            {
//                string subs = s.substr(i, j - i);
//                if (find(wordDict.begin(), wordDict.end(), subs) != wordDict.end() && dp[i])
//                    dp[j] = true;
//            }
//        }
//
//
//        我们对代码中的二重循环稍作优化, 时间效率会提高。
//        主要区别是: 内层循环改为遍历wordDict数组, 而不是继续遍历字符串s了, 另外使用了一种剪枝技巧。
//        时间复杂度:O(N⋅M), N是字符串s的长度, M是数组wordDict的长度。
//
//        所以  if (!dp[i - 1]) continue;
//
//     * https://leetcode-cn.com/problems/word-break/solution/geekplayes-leetcode-ac-qing-xi-yi-dong-d-vwbu/
//     */
//
//    // 更快的dp, 时间复杂度: O(N * M), N是字符串s的长度, M是数组wordDict的长度
//    bool help4(string s, vector<string>& wordDict) {
//        const int len = s.size();
//        bool dp[len + 1];
//        dp[0] = true;
//        fill(dp + 1, dp + len + 1, false);
//        for (int i = 1; i <= len; i++)
//        {
//            if (!dp[i - 1]) continue;     /* dp[i - 1]是false时, 是无法完成拆分的, 指针i跳到下一个index */
//            for (auto& word : wordDict) /* 能执行到这, 说明子串s[0:i-1]都是能拆分的。遍历数组wordDict, 尝试从s中取出新的子串(这个子串的长度和当前循环的word相等, 即s[i-1:j]), 如果这个子串恰好与当前word相同, 那么子串s[0:j]也都是能拆分的。重复以上过程~ */
//            {
//                int j = i - 1 + word.size();
//                if (j <= len && s.substr(i - 1, word.size()) == word)  /* 指针j也不能越界, 即j <= len */
//                    dp[j] = true;
//            }
//        }
//        return dp[len];
//    }
//
//};
//
//int main(){
//    string str,str1;
//    cin >> str;
//    str = str.substr(1,str.size()-2);
//    cin >> str1;
//    vector<string> str2;
//    str1 = str1.substr(1,str1.size()-2);
//    int start = 0;
//    for(int i = 0; i < str1.size(); ++i){
//        if(str1[i] == ','){
//            str2.push_back(str1.substr(start + 1,i - start - 2));
//            start = i + 1;
//        }
//    }
//    str2.push_back(str1.substr(start + 1,str1.size() - start - 2));
//    cout << Solution().wordBreak(str,str2) << endl;
//}