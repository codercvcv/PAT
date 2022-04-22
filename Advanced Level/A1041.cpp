#include <bits/stdc++.h>
using namespace std;

int main() {
  bool flag = false;
  int n;
  cin >> n;
  vector<int> number(n);
  vector<int> count(100000, 0);
  for (int i = 0; i < n; ++i) {
    cin >> number[i];
    count[number[i]]++;
  }

  for (int i = 0; i < n; ++i) {
    if (count[number[i]] == 1) {
      cout << number[i];
      flag = true;
      break;
    }
  }

  if (flag == false) cout << "None";

  return 0;
}