#include <algorithm>
#include <iostream>

using namespace std;

enum { MAXN = 100010 };
int school[MAXN] = {0};

int main() {
  int N, school_id, score;
  int max_id = -1, max_score = -1;
  cin >> N;
  while (N--) {
    cin >> school_id >> score;
    school[school_id] += score;
    if (school[school_id] > max_score) {
      max_id = school_id;
      max_score = school[school_id];
    }
  }

  cout << max_id << ' ' << max_score;
  return 0;
}