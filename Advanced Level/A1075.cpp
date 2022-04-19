#include <bits/stdc++.h>
using namespace std;

struct Student {
  vector<int> grade_;
  int id_;
  int total_{0};
  int solved_{0};
  int rank_;
};

void UpdateInfo(Student& stu, int num, int score, const vector<int>& grade) {
  stu.total_ += score;
  stu.grade_[num] = score;
  if (score == grade[num]) stu.solved_++;
}

bool cmp(const Student& stu1, const Student& stu2) {
  if (stu1.total_ != stu2.total_) return stu1.total_ > stu2.total_;
  else if (stu1.solved_ != stu2.solved_) return stu1.solved_ > stu2.solved_;
  return stu1.id_ < stu2.id_;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> grade(6);
  vector<Student> student(n + 1);
  for (int i = 0; i <= n; ++i) student[i].grade_.resize(m, -1);
  for (int i = 1; i <= m; ++i) {
    cin >> grade[i];
  }
  for (int i = 0; i < k; ++i) {
    int id, num, score;
    cin >> id >> num >> score;
    student[];
    UpdateInfo(student[id], num, score, grade);
  }

  sort(student.begin(), student.end(), cmp);
  student[0].rank_ = 1;
  for (int i = 1; i <= n; ++i) {
    if (student[i].grade_ == student[i - 1].grade_) student[i].rank_ = student[i - 1].rank_;
    else student[i].rank_ = i + 1;
  }
  for (int i = 0; i < n; ++i) {

  }

  return 0;
}