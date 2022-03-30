#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

struct Student {
  string card_;
  int exam_id_;
} student[MAXN];

int main() {
  int n;
  string card;
  int test_id, exam_id;
  cin >> n;
  while (n--) {
    cin >> card >> test_id >> exam_id;
    student[test_id].exam_id_ = exam_id;
    student[test_id].card_ = card;
  }

  cin >> n;
  while (n--) {
    cin >> test_id;
    cout << student[test_id].card_ << " " << student[test_id].exam_id_ << endl;
  }

  return 0;
}