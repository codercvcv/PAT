#include <bits/stdc++.h>

using namespace std;

int main() {
  string str1, str2, ans;
  string mp("0123456789JQK");
  cin >> str1 >> str2;
  int len = str1.size() > str2.size() ? str1.size() : str2.size();
  reverse(str1.begin(), str1.end());
  reverse(str2.begin(), str2.end());

  for (int i = 0; i < len; ++i) {
    int num1 = i < str1.size() ? str1[i] - '0' : 0;
    int num2 = i < str2.size() ? str2[i] - '0' : 0;
    if (i % 2 == 1) {
      int temp = num2 - num1;
      if (temp < 0) temp += 10;
      ans.push_back(temp + '0');
    } else {
      ans.push_back(mp[(num1 + num2) % 13]);
    }
  }

  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}