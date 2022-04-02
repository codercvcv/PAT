#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  long long num1, num2, num3;
  for (int i = 1; i <= N; ++i) {
    cin >> num1 >> num2 >> num3;
    (num1 + num2 > num3) ? printf("Case #%d: true\n", i)
                         : printf("Case #%d: false\n", i);
  }

  return 0;
}