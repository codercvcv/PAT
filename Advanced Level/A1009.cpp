#include <bits/stdc++.h>

using namespace std;

int main() {
  double ans[2010] = {0};
  double poly1[1010] = {0};
  int n;
  cin >> n;
  int exponent;
  double coefficient;
  while (n--) {
    cin >> exponent >> coefficient;
    poly1[exponent] = coefficient;
  }

  cin >> n;
  while (n--) {
    cin >> exponent >> coefficient;
    for (int i = 1000; i >= 0; --i) {
      if (poly1[i]) {
        ans[exponent + i] += (coefficient * poly1[i]);
      }
    }
  }

  int count = 0;
  for (int i = 0; i < 2010; ++i) {
    if (ans[i]) count++;
  }

  printf("%d", count);
  for (int i = 2000; i >= 0; --i) {
    if (ans[i]) {
      printf(" %d %.1f", i, ans[i]);
    }
  }

  return 0;
}