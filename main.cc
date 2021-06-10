#include <ctime>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

#include "leetcode.h"
using namespace leet;

void baseTest() {
  cout << "=================string test==================" << endl;

  //  输入
  //  string ss;
  //  getline(cin, ss);
  //  cout << "ss:" << ss << endl;
  //  int i, j;
  //  cin >> i >> j;
  //  cout << i << " " << j << endl;
  cout << "=================STL test==================" << endl;
  vector<string> s = {"roc", "wp", "wxy"};
  unordered_map<string, int> m;
  for (auto a : s) {
    m[a] = 0;
  }
  pair<unordered_map<string, int>::iterator, bool> Insert_Pair;
  Insert_Pair = m.insert(pair<string, int>("student_one", 1));
  m["roc"]++;
  map<string, int>::reverse_iterator iter;
  cout << ++m["his"] << endl;
  for (auto mp : m) {
    cout << mp.first << " " << mp.second << endl;
  }
  if (m.count("roc") != 0) {
    cout << "Find, the value  " << endl;
  } else {
    cout << "Do not Find" << endl;
  }
}
void leetTest(unique_ptr<LeetCode> lc) {
  cout << "=================字节第一轮题目==================" << endl;
  vector<vector<int>> g = {
      {0, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}};
  clock_t start = clock();
  cout << lc->numIsland(g) << endl;
  clock_t end = clock();
  cout << (double)(end - start) * 1000 / CLOCKS_PER_SEC << endl;
  cout << "=================单向链表翻转==================" << endl;
  ListNode* origin = makeLN(10);
  showLN(origin);
  ListNode* reversed = lc->reverseLN(origin);
  showLN(reversed);
  ListNode* reversed1 = lc->reverseLN_(reversed);
  showLN(reversed1);
  cout << "=================二叉树三种遍历==================" << endl;
  BTNode* root = makeBTNode(2);
  lc->preBTNode(root);
  cout << endl;
  lc->midBTNode(root);
  cout << endl;
  lc->posBTNode(root);
  cout << endl;
  cout << "=================各种排序==================" << endl;
  int n = 300;
  vector<int> vs = makeVec(n);
  start = clock();
  lc->bubleSort(vs);
  end = clock();
  double endtime = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "BubleSort use time:" << endtime * 1000 << " ms" << endl;  // ms为单位
  vector<int> vs1 = makeVec(n);
  start = clock();
  lc->selectSort(vs1);
  end = clock();
  endtime = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "SelectSort use time:" << endtime * 1000 << " ms"
       << endl;  // ms为单位
  vector<int> vs2 = makeVec(n);
  start = clock();
  lc->insertSort(vs2);
  end = clock();
  endtime = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "InsertSort use time:" << endtime * 1000 << " ms"
       << endl;  // ms为单位
  vector<int> vs3 = makeVec(n);
  start = clock();
  lc->quickSort(vs3, 0, vs3.size() - 1);
  end = clock();
  endtime = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "QuickSort use time:" << endtime * 1000 << " ms" << endl;  // ms为单位
  vector<int> vs4 = makeVec(n);
  start = clock();
  lc->mergeSort(vs4, 0, vs.size() - 1);
  end = clock();
  endtime = (double)(end - start) / CLOCKS_PER_SEC;
  cout << "MergeSort use time:" << endtime * 1000 << " ms" << endl;  // ms为单位

  cout << "=================图像旋转90度==================" << endl;
  vector<vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << "------------------------------" << endl;
  lc->rotate(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << "=================字符串相乘==================" << endl;
  string s1 = "846342332";
  string s2 = "58457430234";
  cout << s1 << " * " << s2 << " = " << lc->multiply(s1, s2) << endl;
  cout << "=================接雨水==================" << endl;
  vector<int> v1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << lc->trap(v1) << endl;
}

int main() {
  baseTest();
  unique_ptr<LeetCode> lc;
  leetTest(move(lc));

  return 0;
}
