#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> key(10000, false);
  vector<int> number(n);
  for (int i = 0; i < n; ++i) {
    cin >> number[i];
    int temp = number[i];
    while (temp != 1) {
      if (temp % 2 != 0) temp = 3 * temp + 1;
      temp /= 2;
      if (key[temp] == true) break;
      key[temp] = true;
    }
  }

  sort(number.begin(), number.end(),
       [](const int a, const int b) { return a > b; });

  bool flag = false;
  for (int i = 0; i < number.size(); ++i) {
    if (key[number[i]] == false) {
      if (flag == true) cout << " ";
      cout << number[i];
      flag = true;
    }
  }

  return 0;
}