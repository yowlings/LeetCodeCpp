#ifndef LEETCODE_H
#define LEETCODE_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef map<int, string> MAP_INT_STR;
typedef pair<int, string> PAIR_INT_STR;
namespace leet {
struct Point2 {
  double x;
  double y;
  Point2(double _x, double _y) : x(_x), y(_y){};
  Point2() : x(0.0), y(0.0){};
};

struct BTNode {
  int val;
  BTNode* btl;
  BTNode* btr;
  BTNode(int _val) : val(_val), btl(nullptr), btr(nullptr) {}
};
struct TreeNode {
  int val;
  vector<TreeNode*> sons;
  TreeNode(int _val) : val(_val), sons({}) {}
};

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
static inline void swap(vector<int>& nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
void bubleSort_(vector<int>& nums);
vector<int> makeVec(int n);
void showVec(vector<int> v);
ListNode* makeLN(int n);
void showLN(leet::ListNode* head);
BTNode* makeBTNode(int n);
class LeetCode {
 public:
  LeetCode();
  ~LeetCode();

  ListNode* reverseLN(leet::ListNode* head);
  ListNode* reverseLN_(leet::ListNode* head);
  void stlMapTest();
  void quickSort(vector<int>& nums, int left, int right);
  void bubleSort(vector<int>& nums);
  void selectSort(vector<int>& nums);
  void insertSort(vector<int>& nums);
  void mergeSort(vector<int>& nums, int start, int end);

  void preBTNode(BTNode* root);
  void midBTNode(BTNode* root);
  void posBTNode(BTNode* root);
  //  字节跳动第一轮面试
  void view(vector<vector<int>> grid, vector<vector<int>>& viewed, int i,
            int j);
  int numIsland(vector<vector<int>> grid);
  //  滴滴第一轮面试
  double sqrt_(double d);

  bool isCross(Point2 p1, Point2 p2, Point2 p3, Point2 p4);

  //  第一题：https://leetcode-cn.com/problems/two-sum/
  vector<int> twoSum(vector<int>& nums, int target);
  //  第二题：https://leetcode-cn.com/problems/add-two-numbers/
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
  //  第三题：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
  int lengthOfLongestSubstring(string s);
  //第4题：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
  //第5题：https://leetcode-cn.com/problems/longest-palindromic-substring/
  string longestPalindrome(string s);
  //第6题：https://leetcode-cn.com/problems/zigzag-conversion/
  string convert(string s, int numRows);
  //第7题: https://leetcode-cn.com/problems/reverse-integer/
  int reverse(int x);
  //  第8题：https://leetcode-cn.com/problems/string-to-integer-atoi/
  int myAtoi(string s);
  //  第9题：https://leetcode-cn.com/problems/palindrome-number/
  bool isPalindrome(int x);
  //  第10题：https://leetcode-cn.com/problems/regular-expression-matching/
  bool isMatch(string s, string p);
  //  第11题：https://leetcode-cn.com/problems/container-with-most-water/
  int maxArea(vector<int>& height);
  //  第12题：https://leetcode-cn.com/problems/integer-to-roman/
  string intToRoman(int num);
  //  第13题：https://leetcode-cn.com/problems/roman-to-integer/
  int romanToInt(string s);
  //  第14题：https://leetcode-cn.com/problems/longest-common-prefix/
  string longestCommonPrefix(vector<string>& strs);
  //  第15题：https://leetcode-cn.com/problems/3sum/
  vector<vector<int>> threeSum(vector<int>& nums);
  //  第19题：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
  ListNode* removeNthFromEnd(ListNode* head, int n);
  //  第21题：https://leetcode-cn.com/problems/merge-two-sorted-lists/
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
  //  第23题：https://leetcode-cn.com/problems/merge-k-sorted-lists/
  ListNode* mergeKLists(vector<ListNode*>& lists);
  //  第24题：https://leetcode-cn.com/problems/swap-nodes-in-pairs/
  ListNode* swapPairs(ListNode* head);
  //  第42题：https://leetcode-cn.com/problems/trapping-rain-water/
  int trap(vector<int>& height);
  //  第43题：https://leetcode-cn.com/problems/multiply-strings/
  string multiply(string num1, string num2);
  //  第48题：https://leetcode-cn.com/problems/rotate-image/
  void rotate(vector<vector<int>>& matrix);
};
}  // namespace leet

#endif  // LEETCODE_H
