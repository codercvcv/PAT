#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, temp = 0;
  cin >> n;
  if (n >= 100) {
    temp = n / 100;
    for (int i = 0; i < temp; ++i) cout << "B";
    n %= 100;
  }

  if (n >= 10) {
    temp = n / 10;
    for (int i = 0; i < temp; ++i) cout << "S";
    n %= 10;
  }

  if (n > 0) {
    temp = n;
    for (int i = 1; i <= temp; ++i) cout << i;
  }

  return 0;
}