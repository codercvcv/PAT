#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  double exp[1010] = {0};
  int exponent, count = 0;
  double coefficient;
  cin >> N;
  while (N--) {
    cin >> exponent >> coefficient;
    exp[exponent] += coefficient;
  }

  cin >> M;
  while (M--) {
    cin >> exponent >> coefficient;
    exp[exponent] += coefficient;
  }

  for (int i = 0; i < 1010; i++) {
    if (exp[i]) count++;
  }

  printf("%d", count);
  for (int i = 1000; i >= 0; i--) {
    if (exp[i]) {
      printf(" %d %.1f", i, exp[i]);
    }
  }

  return 0;
}