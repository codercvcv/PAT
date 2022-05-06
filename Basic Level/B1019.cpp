#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  str.insert(0, 4 - str.size(), '0');
  do {
    string s1(str), s2(str);
    sort(s1.begin(), s1.end(),
         [](const char a, const char b) { return a > b; });
    sort(s2.begin(), s2.end());
    int result = stoi(s1) - stoi(s2);
    str = to_string(result);
    str.insert(0, 4 - str.size(), '0');
    cout << s1 << " - " << s2 << " = " << str << endl;
  } while (str != "6174" && str != "0000");

  return 0;
}