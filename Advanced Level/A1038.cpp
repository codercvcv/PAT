#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> str(n);
  for (int i = 0; i < n; ++i) {
    cin >> str[i];
  }

  sort(str.begin(), str.end(),
       [](const string& a, const string& b) { return a + b < b + a; });

  string ans;
  for (int i = 0; i < str.size(); ++i) ans += str[i];

  while (ans.size() != 0 && ans[0] == '0') {
    ans.erase(ans.begin());
  }

  ans.size() == 0 ? cout << 0 : cout << ans;

  return 0;
}