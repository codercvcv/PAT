#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  unordered_map<int, int> coins;
  cin >> n >> m;
  int smallest = m;
  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    if (coins.find(m - temp) != coins.end()) {
      smallest = min({smallest, temp, m - temp});
    }
    if (coins.find(temp) != coins.end())
      coins[temp]++;
    else
      coins.insert({temp, 1});
  }

  smallest == m ? cout << "No Solution"
                : cout << smallest << " " << m - smallest;

  return 0;
}