#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> mp = {"zero", "one", "two",   "three", "four",
                       "five", "six", "seven", "eight", "nine"};
  string str;
  cin >> str;
  int sum = 0;
  for (int i = 0; i < str.size(); ++i) sum += str[i] - '0';
  if (sum >= 100) {
    cout << mp[sum / 100] << " " << mp[sum % 100 / 10] << " " << mp[sum % 10];
  } else if (sum >= 10) {
    cout << mp[sum / 10] << " " << mp[sum % 10];
  } else {
    cout << mp[sum];
  }

  return 0;
}