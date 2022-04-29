#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, p, ans = 1;
  cin >> n >> p;
  vector<int> num(n);
  for (int i = 0; i < n; ++i) cin >> num[i];
  sort(num.begin(), num.end());

  for (int i = 0; i < num.size(); ++i) {
    long long interval =
        upper_bound(num.begin() + i + 1, num.end(), num[i] * p) - num.begin();
    ans = max(ans, interval - i);
  }

  cout << ans;
  return 0;
}