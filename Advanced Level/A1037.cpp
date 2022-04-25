#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  int ans = 0;
  cin >> n;
  vector<int> coupons(n);
  for (int i = 0; i < n; ++i) {
    cin >> coupons[i];
  }
  cin >> m;
  vector<int> product(m);
  for (int i = 0; i < m; ++i) {
    cin >> product[i];
  }
  sort(coupons.begin(), coupons.end());
  sort(product.begin(), product.end());
  int i = 0, j = 0;
  while (i < n && j < m && coupons[i] < 0 && product[j] < 0) {
    ans += coupons[i++] * product[j++];
  }

  i = n - 1;
  j = m - 1;
  while (i >= 0 && j >= 0 && coupons[i] > 0 && product[j] > 0) {
    ans += coupons[i--] * product[j--];
  }
  
  cout << ans;

  return 0;
}