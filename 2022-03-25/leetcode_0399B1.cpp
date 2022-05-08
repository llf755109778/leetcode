////
//// Created by 75510 on 2022/3/25.
////
//#include "bits/stdc++.h"
//using namespace std;
//
/***********
 *给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，
 * 其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。
 * 每个 Ai 或 Bi 是一个表示单个变量的字符串。另有一些以数组 queries 表示的问题，
 * 其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
 */
//class Solution {
//public:
//
//
//    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        return help1(equations, values, queries);
//    }
//
//    /**********
//     * Floyd 算法
//     * @param equations
//     * @param values
//     * @param queries
//     * @return
//     */
//    vector<double> help1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        int nvars = 0;
//        unordered_map<string, int> variables;
//
//        int n = equations.size();
//        for (int i = 0; i < n; i++) {
//            if (variables.find(equations[i][0]) == variables.end()) {
//                variables[equations[i][0]] = nvars++;
//            }
//            if (variables.find(equations[i][1]) == variables.end()) {
//                variables[equations[i][1]] = nvars++;
//            }
//        }
//        vector<vector<double>> graph(nvars, vector<double>(nvars, -1.0));
//        for (int i = 0; i < n; i++) {
//            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
//            graph[va][vb] = values[i];
//            graph[vb][va] = 1.0 / values[i];
//        }
//
//        for (int k = 0; k < nvars; k++) {
//            for (int i = 0; i < nvars; i++) {
//                for (int j = 0; j < nvars; j++) {
//                    if (graph[i][k] > 0 && graph[k][j] > 0) {
//                        graph[i][j] = graph[i][k] * graph[k][j];
//                    }
//                }
//            }
//        }
//
//        vector<double> ret;
//        for (const auto& q: queries) {
//            double result = -1.0;
//            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
//                int ia = variables[q[0]], ib = variables[q[1]];
//                if (graph[ia][ib] > 0) {
//                    result = graph[ia][ib];
//                }
//            }
//            ret.push_back(result);
//        }
//        return ret;
//    }
//
//    /*******
//     * 带权并查集
//     * @param equations
//     * @param values
//     * @param queries
//     * @return
//     */
//    vector<double> help2(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
//        int nvars = 0;
//        unordered_map<string, int> variables;
//
//        int n = equations.size();
//        for (int i = 0; i < n; i++) {
//            if (variables.find(equations[i][0]) == variables.end()) {
//                variables[equations[i][0]] = nvars++;
//            }
//            if (variables.find(equations[i][1]) == variables.end()) {
//                variables[equations[i][1]] = nvars++;
//            }
//        }
//        vector<int> f(nvars);
//        vector<double> w(nvars, 1.0);
//        for (int i = 0; i < nvars; i++) {
//            f[i] = i;
//        }
//
//        for (int i = 0; i < n; i++) {
//            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
//            merge(f, w, va, vb, values[i]);
//        }
//        vector<double> ret;
//        for (const auto& q: queries) {
//            double result = -1.0;
//            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end()) {
//                int ia = variables[q[0]], ib = variables[q[1]];
//                int fa = findf(f, w, ia), fb = findf(f, w, ib);
//                if (fa == fb) {
//                    result = w[ia] / w[ib];
//                }
//            }
//            ret.push_back(result);
//        }
//        return ret;
//    }
//
//    int findf(vector<int>& f, vector<double>& w, int x) {
//        if (f[x] != x) {
//            int father = findf(f, w, f[x]);
//            w[x] = w[x] * w[f[x]];
//            f[x] = father;
//        }
//        return f[x];
//    }
//
//    void merge(vector<int>& f, vector<double>& w, int x, int y, double val) {
//        int fx = findf(f, w, x);
//        int fy = findf(f, w, y);
//        f[fx] = fy;
//        w[fx] = val * w[y] / w[x];
//    }
//};