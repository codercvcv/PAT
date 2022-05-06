#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0, temp = 0;
  string str;
  getline(cin, str);
  vector<int> left_p(str.size(), 0);
  vector<int> right_t(str.size(), 0);
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == 'P') temp++;
    left_p[i] = temp;
  }
  temp = 0;
  for (int i = str.size() - 1; i >= 0; --i) {
    if (str[i] == 'T') temp++;
    right_t[i] = temp;
  }

  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == 'A') {
      ans = (ans + left_p[i] * right_t[i]) % 1000000007;
    }
  }

  cout << ans;

  return 0;
}