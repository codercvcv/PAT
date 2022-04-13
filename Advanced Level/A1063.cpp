#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, temp;
  cin >> n;
  vector<set<int>> number(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> m;
    for (int j = 0; j < m; ++j) {
      cin >> temp;
      number[i].insert(temp);
    }
  }

  cin >> m;
  for (int i = 0; i < m; ++i) {
    int set1, set2;
    int nc = 0, nt = 0;
    cin >> set1 >> set2;
    for (auto iter = number[set1].begin(); iter != number[set1].end(); ++iter) {
      if (number[set2].find(*iter) != number[set2].end()) nc++;
    }
    nt = number[set1].size() + number[set2].size() - nc;
    printf("%.1f%c\n", static_cast<float>(nc) / nt * 100, '%');
  }

  return 0;
}