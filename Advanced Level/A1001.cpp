#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, sum;
  cin >> a >> b;
  sum = a + b;
  if (sum < 0) {
    printf("-");
    sum = -sum;
  }

  if (sum >= 1000000)
    printf("%d,%03d,%03d", sum / 1000000, (sum % 1000000) / 1000, sum % 1000);
  else if (sum >= 1000)
    printf("%d,%03d", sum / 1000, sum % 1000);
  else
    cout << sum;

  return 0;
}