#include <bits/stdc++.h>

using namespace std;

vector<string> mp = {"ling", "yi",  "er", "san", "si",
                     "wu",   "liu", "qi", "ba",  "jiu"};

vector<string> unit = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main() {
  string str;
  cin >> str;
  int left = 0, right = str.size() - 1;
  if (str[0] == '-') {
    cout << "Fu";
    left++;
  }

  while (left + 4 <= right) right -= 4;

  while (left < str.size()) {
    bool flag = false;
    bool is_print = false;
    while (left <= right) {
      if (left > 0 && str[left] == '0') {
        flag = true;
      } else {
        if (flag == true) {
          cout << " ling";
          flag = false;
        }
        if (left > 0) cout << " ";
        cout << mp[str[left] - '0'];
        is_print = true;
        if (left != right) cout << " " << unit[right - left - 1];
      }
      left++;
    }
    if (is_print == true && right != str.size() - 1) {
      cout << " " << unit[(str.size() - 1 - right) / 4 + 2];
    }
    right += 4;
  }

  return 0;
}