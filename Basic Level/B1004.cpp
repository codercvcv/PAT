#include <bits/stdc++.h>

using namespace std;

struct Student {
  string name_;
  string curriculum_;
  int score_;
} top, low, temp;

void Init() {
  top.score_ = -1;
  low.score_ = 101;
}

int main() {
  int n;
  cin >> n;
  Init();
  for (int i = 0; i < n; ++i) {
    cin >> temp.name_ >> temp.curriculum_ >> temp.score_;
    if (temp.score_ < low.score_) low = temp;
    if (temp.score_ > top.score_) top = temp;
  }

  cout << top.name_ << " " << top.curriculum_ << endl;
  cout << low.name_ << " " << low.curriculum_;

  return 0;
}