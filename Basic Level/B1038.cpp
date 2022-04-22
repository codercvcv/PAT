#include <bits/stdc++.h>
using namespace std;

int main()
{
  unordered_map<int, int> record;
  int n;
  int score;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> score;
    if (record.find(score) != record.end()) {
      record[score]++;
    } else {
      record.insert({score, 1});
    }
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> score;
    if (record.find(score) != record.end()) cout << record[score];
    else cout << '0';
    if (i < n - 1) cout << " ";
  }

  return 0;
}