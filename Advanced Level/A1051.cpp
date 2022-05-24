#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n, k;
  cin >> m >> n >> k;
  while (k--) {
    vector<int> num(n + 1);
    stack<int> stk;
    for (int i = 1; i <= n; ++i) cin >> num[i];

    bool flag = false;
    int current = 1;
    for (int i = 1; i <= n; ++i) {
      stk.push(i);
      if (stk.size() > m) break;
      while (!stk.empty() && stk.top() == num[current]) {
        stk.pop();
        current++;
      }
    }

    if (current == n + 1) flag = true;
    (flag == true) ? cout << "YES" << endl : cout << "NO" << endl;
  }

  return 0;
}