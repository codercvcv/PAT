#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
int dist[MAXN] = {0};
int sum[MAXN] = {0};

int main() {
  int n, temp, m;
  cin >> n;
  int sum_dist = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> dist[i];
    sum_dist += dist[i];
    dist[i] = sum_dist;
  }

  cin >> m;
  int start, end;
  for (int i = 0; i < m; ++i) {
    cin >> start >> end;
    if (end < start) swap(start, end);
    temp = dist[end - 1] - dist[start - 1];
    printf("%d", min(temp, sum_dist - temp));
    if (i < m - 1) printf("\n");
  }

  return 0;
}