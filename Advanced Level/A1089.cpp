#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i, j;
  cin >> n;
  vector<int> origin(n);
  vector<int> now(n);
  for (int i = 0; i < n; ++i) cin >> origin[i];
  for (int i = 0; i < n; ++i) cin >> now[i];
  for (i = 0; i < n - 1 && now[i] <= now[i + 1]; ++i)
    ;
  for (j = i + 1; j < n && origin[j] == now[j]; ++j)
    ;
  if (j == n) {
    cout << "Insertion Sort" << endl;
    sort(origin.begin(), origin.begin() + i + 2);
  } else {
    cout << "Merge Sort" << endl;
    int k = 1, flag = 1;
    while (flag) {
      flag = 0;
      for (int i = 0; i < n; ++i) {
        if (origin[i] != now[i]) flag = 1;
      }
      k = k * 2;
      for (int i = 0; i < n / k; ++i)
        sort(origin.begin() + i * k, origin.begin() + (i + 1) * k);
      sort(origin.begin() + n / k * k, origin.begin() + n);
    }
  }

  cout << origin[0];
  for (int i = 1; i < n; ++i) cout << " " << origin[i];

  return 0;
}