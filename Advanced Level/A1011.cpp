#include <bits/stdc++.h>

using namespace std;

int State(double rate[]) {
  if (rate[0] > rate[1] && rate[0] > rate[2]) return 0;
  if (rate[1] > rate[0] && rate[1] > rate[2]) return 1;
  return 2;
}

int main() {
  char mp[3] = {'W', 'T', 'L'};
  double ans = 1;
  double rate[3];
  for (int i = 0; i < 3; ++i) {
    cin >> rate[0] >> rate[1] >> rate[2];
    ans *= max({rate[0], rate[1], rate[2]});
    printf("%c ", mp[State(rate)]);
  }
  printf("%.2f", (ans * 0.65 - 1) * 2);

  return 0;
}