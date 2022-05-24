#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;
  for (int i = 0; i < k; ++i) {
    bool flag = false;
    stack<int> stk;
    vector<int> num(n + 1);
    for (int j = 1; j <= n; ++j) cin >> num[j];

    int current = 1;
    for (int j = 1; j <= n; ++j) {
      stk.push(j);
      if (stk.size() > m) break;
      while (!stk.empty() && stk.top() == num[current]) {
        stk.pop();
        current++;
      }
    }
    if (current == n + 1) flag = true;
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}