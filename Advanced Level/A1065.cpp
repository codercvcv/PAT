#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  long long a, b, c;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld %lld", &a, &b, &c);
    long long result = a + b;
    if (a > 0 && b > 0 && result < 0) {
      printf("Case #%d: true\n", i);
    } else if (a < 0 && b < 0 && result >= 0) {
      printf("Case #%d: false\n", i);
    } else {
      result > c ? printf("Case #%d: true\n", i)
                 : printf("Case #%d: false\n", i);
    }
  }

  return 0;
}