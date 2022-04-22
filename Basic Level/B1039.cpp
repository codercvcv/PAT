#include <bits/stdc++.h>
using namespace std;

int main() {
  string str1, str2;
  cin >> str1 >> str2;
  int count = 0;
  for (int i = 0; i < str2.size(); ++i) {
    int pos = str1.find(str2[i]);
    if (pos != string::npos) {
      str1.erase(str1.begin() + pos);
    } else {
      count++;
    }
  }

  count == 0 ? cout << "Yes " << str1.size() : cout << "No " << count; 

  return 0;
}