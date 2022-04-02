#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main() {
  int ans[50];
  int A, B, D;
  cin >> A >> B >> D;
  int C = A + B;
  int i = 0;
  while (C) {
    ans[i++] = C % D;
    C /= D;
  }

  i == 0 ? printf("0"): printf("");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", ans[j]);
  }

  return 0;
}