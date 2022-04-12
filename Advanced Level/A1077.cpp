#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, len = 256;
  cin >> n;
  string suffix;
  vector<string> kuchiguse(n);
  getchar();
  for (int i = 0; i < n; ++i) {
    getline(cin, kuchiguse[i]);
    if (kuchiguse[i].size() < len) len = kuchiguse[i].size();
    reverse(kuchiguse[i].begin(), kuchiguse[i].end());
  }

  for (int i = 0; i < len; ++i) {
    bool flag = true;
    for (int j = 1; j < n; ++j) {
      if (kuchiguse[j][i] != kuchiguse[0][i]) {
        flag = false;
        break;
      }
    }

    if (flag == true)
      suffix.push_back(kuchiguse[0][i]);
    else
      break;
  }

  reverse(suffix.begin(), suffix.end());
  suffix.empty() == true ? cout << "nai" : cout << suffix;

  return 0;
}