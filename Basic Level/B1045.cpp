#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> data(n);
  vector<int> left_max(n, 0);
  vector<int> right_min(n, INT_MAX);
  vector<int> ans;
  for (int i = 0; i < n; ++i) cin >> data[i];
  for (int i = 1; i < n; ++i) {
    left_max[i] = max(left_max[i - 1], data[i - 1]);
  }
  for (int i = n - 2; i >= 0; --i) {
    right_min[i] = min(right_min[i + 1], data[i + 1]);
  }

  for (int i = 0; i < n; ++i) {
    if (left_max[i] < data[i] && right_min[i] > data[i]) ans.push_back(data[i]);
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i];
    if (i < ans.size() - 1) cout << " ";
  }
  cout << endl;

  return 0;
}