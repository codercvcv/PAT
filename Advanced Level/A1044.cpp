#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int>& diamond, const int value,
                  const int start) {
  int left = start;
  int right = diamond.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (diamond[mid] < value)
      left = mid + 1;
    else if (diamond[mid] > value)
      right = mid - 1;
    else
      return mid;
  }

  return -1;
}

int main() {
  int n, m, temp, near = INT_MAX;
  cin >> n >> m;
  vector<int> diamond(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> temp;
    diamond[i] = diamond[i - 1] + temp;
  }

  for (int i = 1; i <= n; ++i) {
    int j =
        upper_bound(diamond.begin() + i, diamond.end(), diamond[i - 1] + m) -
        diamond.begin();
    if (diamond[j - 1] - diamond[i - 1] == m) {
      near = m;
      break;
    } else if (j <= n && diamond[j] - diamond[i - 1] < near)
      near = diamond[j] - diamond[i - 1];
  }

  for (int i = 0; i < diamond.size(); ++i) {
    int pos = binary_search(diamond, near + diamond[i], i + 1);
    if (pos != -1) cout << i + 1 << "-" << pos << endl;
  }

  return 0;
}