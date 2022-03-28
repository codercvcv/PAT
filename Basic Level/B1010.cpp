#include <bits/stdc++.h>

using namespace std;

int main() {
  int exponent, coefficient;
  int ans[1010] = {0};
  int count = 0;
  while (scanf("%d %d", &coefficient, &exponent) != EOF) {
    if (exponent > 0) {
      ans[exponent - 1] = coefficient * exponent;
      if (ans[exponent - 1] != 0) count++;
    }
  }

  if (count == 0) printf("0 0");
  for (int i = 1000; i >= 0; --i) {
    if (ans[i] != 0) {
      printf("%d %d", ans[i], i);
      count--;
      if (count) printf(" ");
    }
  }

  return 0;
}