#include <bits/stdc++.h>

using namespace std;

int n;

string deal(string str, int& e) {
  int i = 0;
  while (str[0] == '0') {
    str.erase(str.begin());
  }

  if (str[0] == '.') {
    str.erase(str.begin());
    while (str.length() > 0 && str[0] == '0') {
      str.erase(str.begin());
      e--;
    }
  } else {
    while (i < str.length() && str[i] != '.') {
      i++;
      e++;
    }
    if (i < str.length()) str.erase(str.begin() + i);
  }

  if (str.length() == 0) e = 0;
  int num = 0;
  i = 0;
  string res;
  while (num < n) {
    if (i < str.length())
      res.push_back(str[i++]);
    else
      res.push_back('0');
    num++;
  }

  return res;
}

int main() {
  string s1, s2, s3, s4;
  int e1 = 0, e2 = 0;
  cin >> n >> s1 >> s2;
  s3 = deal(s1, e1);
  s4 = deal(s2, e2);
  if (s3 == s4 && e1 == e2) {
    cout << "YES 0." << s3 << "*10^" << e1 << endl;
  } else {
    cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl;
  }

  return 0;
}