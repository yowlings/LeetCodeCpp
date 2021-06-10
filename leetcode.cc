#include "leetcode.h"
namespace leet {
vector<int> makeVec(int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(rand() % 1000);
  }
  return v;
}
void showVec(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

ListNode* makeLN(int n) {
  leet::ListNode* head = new leet::ListNode(rand() % 1000);
  leet::ListNode* p = head;
  for (int i = 1; i < n; i++) {
    p->next = new leet::ListNode(rand() % 1000);
    p = p->next;
  }
  return head;
}

void showLN(leet::ListNode* head) {
  leet::ListNode* temp = head;
  while (temp != nullptr) {
    cout << temp->val << " - ";
    temp = temp->next;
  }
  cout << endl;
}

BTNode* makeBTNode(int n) {
  BTNode* root = new BTNode(rand() % 1000);
  if (n > 0) {
    root->btl = makeBTNode(n - 1);
    root->btr = makeBTNode(n - 1);
  }
  return root;
}
LeetCode::LeetCode() {}
LeetCode::~LeetCode() {}

void LeetCode::preBTNode(BTNode* root) {
  if (root == nullptr) return;
  cout << root->val << " ";
  preBTNode(root->btl);
  preBTNode(root->btr);
}
void LeetCode::midBTNode(BTNode* root) {
  if (root == nullptr) return;
  midBTNode(root->btl);
  cout << root->val << " ";
  midBTNode(root->btr);
}
void LeetCode::posBTNode(BTNode* root) {
  if (root == nullptr) return;
  posBTNode(root->btl);
  posBTNode(root->btr);
  cout << root->val << " ";
}

void bubleSort_(vector<int>& nums) {
  if (nums.size() < 2) return;
  for (int i = nums.size(); i > 0; i--) {
    int j = 0;
    for (; j < i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums, j, j + 1);
      }
    }
  }
}

void LeetCode::bubleSort(vector<int>& nums) {
  if (nums.size() < 2) return;
  for (int i = nums.size(); i > 0; i--) {
    int j = 0;
    while (j < i - 1) {
      if (nums[j + 1] < nums[j]) {
        swap(nums, j, j + 1);
      }
      j++;
    }
  }
}

void LeetCode::selectSort(vector<int>& nums) {
  if (nums.size() < 2) return;
  for (int i = 0; i < nums.size() - 1; i++) {
    int minid = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[minid]) {
        minid = j;
      }
    }
    if (i != minid) {
      swap(nums, i, minid);
    }
  }
}

void LeetCode::insertSort(vector<int>& nums) {
  if (nums.size() < 2) return;
  for (int i = 1; i < nums.size(); i++) {
    int j = i - 1;
    while (j >= 0 && nums[j] > nums[j + 1]) {
      swap(nums, j, j + 1);
      j--;
    }
  }
}
void LeetCode::quickSort(vector<int>& nums, int left, int right) {
  if (left >= right) return;
  int temp = nums[left];
  int i = left;
  int j = right;
  while (i < j) {
    while (i < j) {
      if (nums[j] < temp) {
        nums[i] = nums[j];
        nums[j] = temp;
        break;
      }
      j--;
    }

    while (i < j) {
      if (nums[i] > temp) {
        nums[j] = nums[i];
        nums[i] = temp;
      }
      i++;
    }
  }
  quickSort(nums, left, i - 1);
  quickSort(nums, i + 1, right);
}
void LeetCode::mergeSort(vector<int>& nums, int start, int end) {
  if (start >= end) return;
  int mid = (start + end) / 2;
  int i = start;
  int j = mid + 1;
  mergeSort(nums, i, mid);
  mergeSort(nums, j, end);
  vector<int> temp = {};
  while (i <= mid && j <= end) {
    if (nums[i] < nums[j]) {
      temp.push_back(nums[i++]);
    } else {
      temp.push_back(nums[j++]);
    }
  }
  while (i <= mid) {
    temp.push_back(nums[i++]);
  }
  while (j <= end) {
    temp.push_back(nums[j++]);
  }
  int k = start;
  for (; k <= end; k++) {
    nums[k] = temp[k - start];
  }
}
void LeetCode::view(vector<vector<int>> grid, vector<vector<int>>& viewed,
                    int i, int j) {
  if (i < 1 || i > grid.size()) return;
  if (j < 1 || j > grid[0].size()) return;
  viewed[i][j] = 1;

  if (grid[i - 1][j] && !viewed[i - 1][j]) {
    view(grid, viewed, i - 1, j);
  }
  if (grid[i + 1][j] && !viewed[i + 1][j]) {
    view(grid, viewed, i + 1, j);
  }
  if (grid[i][j - 1] && !viewed[i][j - 1]) {
    view(grid, viewed, i, j - 1);
  }
  if (grid[i][j + 1] && !viewed[i][j + 1]) {
    view(grid, viewed, i, j + 1);
  }
}
int LeetCode::numIsland(vector<vector<int>> grid) {
  if (grid.size() < 3) return 0;
  int ret = 0;
  vector<vector<int>> viewed = grid;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      viewed[i][j] = 0;
    }
  }
  for (int i = 1; i < grid.size() - 1; i++) {
    for (int j = 1; j < grid[0].size() - 1; j++) {
      if (grid[i][j] && !viewed[i][j]) {
        view(grid, viewed, i, j);
        ret++;
      }
    }
  }
  return ret;
}

double LeetCode::sqrt_(double d) {
  double init;
  double delta;
  double t = 0.00000000000001;
  if (d > 1) {
    init = d / 2;
  } else {
    init = 2 * d;
  }

  while (fabs(d - init * init) > t) {
    delta = (d - init * init) / (2 * init);
    cout << init << "->";

    init = init + delta;
  }
  return init;
}
bool LeetCode::isCross(Point2 p1, Point2 p2, Point2 p3, Point2 p4) {
  if (p1.x < p3.x && p2.x < p3.x) {
    return false;
  }
  return false;
}

void LeetCode::stlMapTest() {
  //    字符串操作
  string name = "this@ is@ a test string!";

  cout << "第一个字符之后内容的子串：" << name.substr(1) << endl;
  /*用法一：
   *用str替换指定字符串从起始位置pos开始长度为len的字符
   *string& replace (size_t pos, size_t len, const string& str);
   */
  string line = name.replace(name.find('@'), 1, "");
  cout << "替换@字符之后内容的子串：" << line << endl;
  cout << "删除第3个字符之后内容的子串：" << name.erase(3) << endl;

  // map使用
  MAP_INT_STR mapStudent;
  mapStudent.insert(PAIR_INT_STR(1, "student_one"));
  //  插入不成功，map的key值是唯一的
  mapStudent.insert(PAIR_INT_STR(1, "student_two"));
  //  赋值修改成功
  mapStudent[1] = "rocwang";
  mapStudent.insert(PAIR_INT_STR(3, "student_three"));
  //  可判断是否返回插入成功
  pair<MAP_INT_STR::iterator, bool> Insert_Pair;
  Insert_Pair = mapStudent.insert(PAIR_INT_STR(1, "student_one"));
  if (Insert_Pair.second) {
    cout << "Insert Successfully" << endl;
  } else {
    cout << "Insert Failure" << endl;
  }
  //  map的遍历
  MAP_INT_STR::iterator iter;
  for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++) {
    cout << iter->first << ' ' << iter->second << endl;
  }
}
vector<int> LeetCode::twoSum(vector<int>& nums, int target) {
  vector<int> solution;
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        solution.push_back(i);
        solution.push_back(j);
        return solution;
      }
    }
  }
  return solution;
}
ListNode* LeetCode::addTwoNumbers(ListNode* l1, ListNode* l2) {
  //    assume l1.size>=l2.size
  ListNode *pl1, *pl2, *s;
  ListNode* sum = new ListNode(0);
  ListNode* temp = new ListNode(0);
  temp->next = nullptr;
  pl1 = l1;
  pl2 = l2;
  s = sum;
  int t = 0;
  bool l1_end(0), l2_end(0);
  while (!l1_end || !l2_end) {
    s->val = (pl1->val + pl2->val + t) % 10;
    t = (pl1->val + pl2->val + t) / 10;
    if (pl1->next == nullptr) {
      l1_end = 1;
      pl1 = temp;
    } else {
      pl1 = pl1->next;
    }
    if (pl2->next == nullptr) {
      l2_end = 1;
      pl2 = temp;
    } else {
      pl2 = pl2->next;
    }
    if (!l1_end || !l2_end || t != 0) {
      s->next = new ListNode(0);
    }
    s = s->next;
  }
  if (t > 0) {
    s->val = t;
  }
  return sum;
}

int LeetCode::lengthOfLongestSubstring(string s) {
  int n = s.size();
  if (n <= 1) return n;

  int max = 1;
  for (int i = 0; i < n - max; i++) {
    string s0 = s.substr(i);
    //    cout << s0 << endl;
    int j = i + 1;
    for (; j <= n; j++) {
      string s1 = s0;
      s1.erase(j - i);
      //      cout << s1 << endl;
      max = ((j - i) > max) ? j - i : max;
      if (s1.find(s[j]) < n) {
        //        cout << max << endl;
        break;
      }
    }
  }
  return max;
}

double LeetCode::findMedianSortedArrays(vector<int>& nums1,
                                        vector<int>& nums2) {
  vector<int> nums;
  for (int i = 0; i < nums1.size(); i++) nums.push_back(nums1[i]);
  for (int i = 0; i < nums2.size(); i++) nums.push_back(nums2[i]);
  sort(nums.begin(), nums.end());
  int n = nums.size();
  if (n % 2) {
    return nums[(n - 1) / 2];
  } else {
    return (nums[n / 2 - 1] + nums[n / 2]) / 2;
  }
}
bool isLoopStr(string s) {
  string s1 = s;
  reverse(s1.begin(), s1.end());
  return (s1 == s);
}
string LeetCode::longestPalindrome(string s) {
  int n = s.size();
  if (n == 1) return s;
  int i = 2;
  bool test_odd(0);
  bool looped(0);
  string re = s.substr(n - 1);
  while (i <= n) {
    for (int j = 0; j <= n - i; j++) {
      string s0 = s.substr(j);
      string s1 = s0;
      s1.erase(i);
      if (isLoopStr(s1)) {
        re = s1;
        looped = 1;
        break;
      }
    }
    if (looped) {
      if (i == 2) {
        i = i + 1;
      } else {
        i = i + 2;
        if (i == n + 1) i = n;
      }

      looped = 0;
    } else if (!test_odd) {
      i = i + 1;
      test_odd = 1;
    } else {
      break;
    }
  }
  return re;
}
string LeetCode::convert(string s, int numRows) {
  int n = s.size();
  if (n <= numRows || numRows == 1) return s;
  int step = 2 * numRows - 2;
  int deck = n / step;
  string re;
  for (int i = 0; i <= deck; i++) {
    if (i * step < n) {
      re.push_back(s[i * step]);
    }
  }
  for (int i = 1; i < numRows - 1; i++) {
    for (int j = 0; j <= deck; j++) {
      if (i + j * step < n) {
        re.push_back(s[i + j * step]);
      }
      if (step - i + j * step < n) {
        re.push_back(s[step - i + j * step]);
      }
    }
  }
  for (int i = 0; i <= deck; i++) {
    if (i * step + numRows - 1 < n) {
      re.push_back(s[i * step + numRows - 1]);
    }
  }
  return re;
}
int reversed(unsigned int x) {
  int tx = x;
  int rx = 0;
  while (tx) {
    int t = tx % 10;
    tx = tx / 10;
    if (rx <= INT_MAX / 10) {
      rx = rx * 10 + t;
    } else {
      return 0;
    }
  }
  return rx;
}
int LeetCode::reverse(int x) {
  if (x == -2147483648 || x == 2147483647) return 0;
  if (x > 0) return reversed(x);
  if (x < 0) return -reversed(-x);

  return 0;
}
int LeetCode::myAtoi(string s) {
  int n = s.size();
  int start = 0;
  for (; start < n; start++) {
    if (s[start] != ' ') {
      break;
    }
  }

  bool positive = 1;

  if (s[start] == '-') {
    start++;
    positive = 0;
  } else if (s[start] == '+') {
    start++;
    positive = 1;
  } else if (s[start] < '0' || s[start] > '9') {
    return 0;
  }

  vector<int> num;
  for (; start < s.size(); start++) {
    if (s[start] < '0' || s[start] > '9') {
      break;
    } else {
      num.push_back(s[start] - '0');
    }
  }

  int j = 0;
  for (; j < num.size(); j++) {
    if (num[j] != 0) {
      break;
    }
  }

  int64_t number = 0;
  for (; j < num.size(); j++) {
    number = number * 10 + num[j];
    if (positive && number > INT_MAX) return INT_MAX;
    if (!positive && number - 1 > INT_MAX) return INT_MIN;
  }
  if (positive)
    return number;
  else
    return -number;
}
bool LeetCode::isPalindrome(int x) {
  if (x < 0) return false;
  int tx = x;
  int64_t rx = 0;
  while (tx) {
    rx = rx * 10 + tx % 10;
    tx = tx / 10;
  }
  return x == rx;
}
bool LeetCode::isMatch(string s, string p) {
  if (s.empty()) {
    return p.empty() || (p[1] == '*');
  }
  return false;
}
int area(int i, int j, int a, int b) { return abs(i - j) * min(a, b); }
int LeetCode::maxArea(vector<int>& height) {
  int n = height.size();
  int left = 0, right = n - 1;
  int max_area = area(left, right, height[left], height[right]);

  bool go_right(0), go_left(0);
  bool first(1);
  while (first || go_right || go_left) {
    int tl = left + 1;
    for (; tl != right; tl++) {
      if (height[tl] <= height[left]) continue;
      int current = area(tl, right, height[tl], height[right]);
      if (current > max_area) {
        left = tl;
        max_area = current;
        go_right = 1;
        break;
      }
    }
    if (tl == right - 1) {
      if (go_right) {
        return max_area;
      } else {
        go_right = 0;
      }
    }
    int tr = right - 1;
    for (; tr != left; tr--) {
      if (height[tr] <= height[right]) continue;
      int current = area(left, tr, height[left], height[tr]);
      if (current > max_area) {
        right = tr;
        max_area = current;
        go_left = 1;
        break;
      }
    }
    if (tr == left + 1) {
      if (go_left) {
        return max_area;
      } else {
        go_left = 0;
      }
    }
    first = 0;
  }

  return max_area;
}
void bianma(string& s, int num, char c1, char c2, char c3) {
  if (num == 9) {
    s.push_back(c3);
    s.push_back(c1);
  } else if (num == 4) {
    s.push_back(c3);
    s.push_back(c2);
  } else if (num >= 5) {
    s.push_back(c2);
    for (int i = 0; i < num - 5; i++) {
      s.push_back(c3);
    }
  } else if (num > 0) {
    for (int i = 0; i < num; i++) {
      s.push_back(c3);
    }
  }
}
string LeetCode::intToRoman(int num) {
  int qian = num / 1000;
  int bai = (num % 1000) / 100;
  int shi = ((num % 1000) % 100) / 10;
  int ge = ((num % 1000) % 100) % 10;
  string re;
  for (int i = 0; i < qian; i++) {
    re.push_back('M');
  }

  bianma(re, bai, 'M', 'D', 'C');
  bianma(re, shi, 'C', 'L', 'X');
  bianma(re, ge, 'X', 'V', 'I');
  return re;
}
int LeetCode::romanToInt(string s) {
  int n = s.size();
  int re(0);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'I') {
      if (i == n - 1)
        re += 1;
      else if ((s[i + 1] == 'V' || s[i + 1] == 'X'))
        re -= 1;
      else
        re += 1;
    } else if (s[i] == 'V')
      re += 5;
    else if (s[i] == 'X') {
      if (i == n - 1)
        re += 10;
      else if ((s[i + 1] == 'L' || s[i + 1] == 'C'))
        re -= 10;
      else
        re += 10;
    } else if (s[i] == 'L')
      re += 50;
    else if (s[i] == 'C') {
      if (i == n - 1)
        re += 100;
      else if ((s[i + 1] == 'D' || s[i + 1] == 'M'))
        re -= 100;
      else
        re += 100;
    } else if (s[i] == 'D')
      re += 500;
    else if (s[i] == 'M')
      re += 1000;
  }
  return re;
}
string LeetCode::longestCommonPrefix(vector<string>& strs) {
  int n = strs.size();
  if (strs.empty()) return "";

  int shortest = strs[0].size();
  int short_id = 0;
  for (int i = 0; i < n; i++) {
    if (strs[i].size() < shortest) {
      short_id = i;
      shortest = strs[i].size();
    }
  }
  for (int i = strs[short_id].size(); i > 0; i--) {
    string s0 = strs[short_id];
    s0.erase(i);
    vector<string> ss(strs);
    int match = 0;
    for (int j = 0; j < ss.size(); j++) {
      if (ss[j].erase(i) != s0)
        break;
      else
        match++;
    }
    if (match == n) return s0;
  }
  return "";
}

vector<vector<int>> LeetCode::threeSum(vector<int>& nums) {
  int n = nums.size();
  if (n < 3) return {};
  vector<vector<int>> re;
  LeetCode::quickSort(nums, 0, n - 1);
  if (nums[0] > 0) return {};
  int upzero = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > 0) {
      upzero = i;
      break;
    }
  }

  for (int i = 0; i < upzero; i++) {
    int l = i + 1;
    int r = n - 1;
    while (l < r) {
      if (nums[i] + nums[l] + nums[r] == 0) {
        re.push_back({nums[i], nums[l], nums[r]});
        while (l < r && nums[l] == nums[l + 1]) {
          l++;
        }
        while (l < r && nums[r] == nums[r - 1]) {
          r--;
        }
      } else if (nums[i] + nums[l] + nums[r] > 0) {
        r--;
      } else {
        l++;
      }
    }
  }

  return re;
}
ListNode* LeetCode::removeNthFromEnd(ListNode* head, int n) {
  int sz = 0;
  ListNode* p = head;

  while (p != nullptr) {
    sz++;
    p = p->next;
  }
  if (sz == n) {
    return head->next;
  }
  int i = 1;
  ListNode* pt = head;
  ListNode* pp = head->next;
  while (pp != nullptr) {
    if (i == sz - n) {
      pt->next = pp->next;
      return head;
    }
    i++;
    pt = pp;
    pp = pp->next;
  }
  return head;
}

ListNode* LeetCode::mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (l1 == NULL) return l2;
  if (l2 == NULL) return l1;
  ListNode* ll;
  ListNode* t1 = l1;
  ListNode* t2 = l2;
  if (t1->val < t2->val) {
    ll = t1;
    t1 = t1->next;
  } else {
    ll = t2;
    t2 = t2->next;
  }
  ListNode* ret = ll;
  while (t1 != NULL || t2 != NULL) {
    if (t1 != NULL && t2 != NULL) {
      if (t1->val < t2->val) {
        ll->next = t1;
        t1 = t1->next;
      } else {
        ll->next = t2;
        t2 = t2->next;
      }

    } else if (t1 == NULL && t2 != NULL) {
      ll->next = t2;
      t2 = t2->next;
    } else if (t1 != NULL && t2 == NULL) {
      ll->next = t1;
      t1 = t1->next;
    }
    ll = ll->next;
  }
  return ret;
}
bool cmpPairLN(pair<int, int> p1, pair<int, int> p2) {
  return p1.second > p2.second;
}
ListNode* LeetCode::mergeKLists(vector<ListNode*>& lists) {
  int n = lists.size();
  ListNode *ret, *retp;
  vector<pair<int, int>> vp;
  vector<ListNode*> lp = lists;
  for (int i = 0; i < n; i++) {
    if (lp[i] != NULL) {
      vp.push_back({i, lp[i]->val});
    }
  }
  if (vp.empty()) return NULL;
  std::sort(vp.begin(), vp.end(), cmpPairLN);
  int minID = vp.front().first;
  ret = lp[minID];
  lp[minID] = lp[minID]->next;
  vp.pop_back();
  if (lp[minID] != NULL) vp.push_back({minID, lp[minID]->val});
  retp = ret;
  while (!vp.empty()) {
    std::sort(vp.begin(), vp.end(), cmpPairLN);
    minID = vp.front().first;
    retp->next = lp[minID];
    lp[minID] = lp[minID]->next;
    vp.pop_back();

    retp = retp->next;
    if (lp[minID] != NULL) {
      vp.push_back({minID, lp[minID]->val});
    }
  }

  return ret;
}
ListNode* LeetCode::swapPairs(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;
  ListNode* second = head->next;
  head->next = swapPairs(second->next);
  second->next = head;
  return second;
}

ListNode* LeetCode::reverseLN_(leet::ListNode* head) {
  if (head == nullptr || head->next == nullptr) return head;
  leet::ListNode* ln1 = head;
  leet::ListNode* ln2 = ln1->next;
  ln1->next = nullptr;
  while (ln2->next != nullptr) {
    leet::ListNode* tmp = ln2->next;
    ln2->next = ln1;
    ln1 = ln2;
    ln2 = tmp;
  }
  ln2->next = ln1;
  return ln2;
}
ListNode* LeetCode::reverseLN(leet::ListNode* head) {
  if (head == nullptr || head->next == nullptr) return head;
  leet::ListNode* temp = head;
  leet::ListNode* ret = reverseLN(head->next);
  leet::ListNode* r = ret;
  while (r->next != nullptr) {
    r = r->next;
  }
  r->next = head;
  head->next = nullptr;
  return ret;
}
void reversVector(vector<int>& v) {
  if (v.size() <= 1) return;
  for (int i = 0; i < v.size() / 2; i++) {
    int temp = v[i];
    v[i] = v[v.size() - i];
    v[v.size() - i] = temp;
  }
}
void LeetCode::rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  if (n <= 1) return;
  vector<vector<int>> ret;

  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (int j = n - 1; j >= 0; j--) {
      temp.push_back(matrix[j][i]);
    }
    ret.push_back(temp);
  }
  matrix = ret;
}
string LeetCode::multiply(string num1, string num2) {
  if (num1.empty() || num2.empty()) return "";
  if (num1 == "0" || num2 == "0") return "0";
  vector<int> v1, v2;
  for (int i = 0; i < num1.size(); i++) {
    v1.push_back(num1[num1.size() - 1 - i] - '0');
  }
  for (int i = 0; i < num2.size(); i++) {
    v2.push_back(num2[num2.size() - 1 - i] - '0');
  }

  vector<int> ret;
  int up = 0;
  for (int i = 0; i < v1.size() + v2.size() - 1; i++) {
    int sum = up;
    int t = i;
    if (i > v1.size() - 1) {
      t = v1.size() - 1;
    }
    for (int j = 0; j <= t; j++) {
      if (i - j < v2.size()) sum += v1[j] * v2[i - j];
    }
    ret.push_back(sum % 10);
    up = sum / 10;
  }

  while (up) {
    ret.push_back(up % 10);
    up = up / 10;
  }

  string s = "";
  for (int i = 0; i < ret.size(); i++) {
    char c = char(ret[i] + '0');
    s = c + s;
  }
  return s;
}
int trap__(vector<int>& h, int i, int j, bool left) {
  if (j - i <= 1) return 0;
  int sum = 0;
  if (left) {
    for (int k = i + 1; k < j; k++) {
      sum = sum + h[i] - h[k];
    }
  } else {
    for (int k = j - 1; k > i; k--) {
      sum = sum + h[j] - h[k];
    }
  }
  return sum;
}
int trap_(vector<int>& h, int i, int j, bool left) {
  if (j - i <= 1) return 0;
  if (left) {
    int max_index = i;
    for (int k = i; k < j; k++) {
      if (h[k] > h[max_index]) {
        max_index = k;
      }
    }
    return trap__(h, max_index, j, 1) + trap_(h, i, max_index, 1);
  } else {
    int max_index = i + 1;
    for (int k = i + 1; k <= j; k++) {
      if (h[k] > h[max_index]) {
        max_index = k;
      }
    }
    //    cout << max_index << endl;
    return trap__(h, i, max_index, 0) + trap_(h, max_index, j, 0);
  }
}
int LeetCode::trap(vector<int>& height) {
  if (height.size() < 3) return 0;
  int max_index = 0;
  for (int i = 0; i < height.size(); i++) {
    if (height[i] > height[max_index]) {
      max_index = i;
    }
  }

  return trap_(height, 0, max_index, 1) +
         trap_(height, max_index, height.size() - 1, 0);
}
}  // namespace leet
