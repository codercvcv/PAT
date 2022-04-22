#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int id, number, score;
  int max_score = 0;
  cin >> n;
  vector<int> total(1000, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d-%d %d", &id, &number, &score);
    total[id] += score;
    max_score = max(max_score, total[id]);
  }

  for (int i = 0; i < total.size(); ++i) {
    if (total[i] == max_score) printf("%d %d", i, total[i]);
  }

  return 0;
}