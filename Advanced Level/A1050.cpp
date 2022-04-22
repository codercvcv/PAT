#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str1, str2;
  getline(cin, str1);
  getline(cin, str2);

  for (int i = 0; i < str1.size(); ++i) {
    int pos = str2.find(str1[i]);
    if (pos == string::npos) cout << str1[i];
  }

  return 0;
}