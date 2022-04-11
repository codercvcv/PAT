#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<string> data;
  char temp[80];
  while (scanf("%s", temp) != EOF) {
    data.push_back(temp);
  }

  for (int i = data.size() - 1; i >= 0; --i) {
    cout << data[i];
    if (i != 0) cout << " ";
  }

  return 0;
}