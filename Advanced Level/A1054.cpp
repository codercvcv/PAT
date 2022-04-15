#include <bits/stdc++.h>

using namespace std;

int main()
{
  unordered_map<int, int> color;
  int n, m, temp;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n * m; ++i) {
    scanf("%d", &temp);
    if (color.find(temp) != color.end()) color[temp]++;
    else color.insert({temp, 1});
  }

  for (auto iter = color.begin(); iter != color.end(); ++iter) {
    if (iter->second > (n * m / 2)) {
      printf("%d", iter->first);
      break;
    }
  }

  return 0;
}