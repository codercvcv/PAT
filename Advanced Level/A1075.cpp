#include <bits/stdc++.h>
using namespace std;

struct Student {
  vector<int> grade_;
  int id_;
  int total_;
  int solved_;
  int rank_;
  bool flag;
};

bool cmp(const Student& stu1, const Student& stu2) {
  if (stu1.total_ != stu2.total_)
    return stu1.total_ > stu2.total_;
  else if (stu1.solved_ != stu2.solved_)
    return stu1.solved_ > stu2.solved_;
  return stu1.id_ < stu2.id_;
}

void Init(vector<Student>& student) {
  for (int i = 0; i < student.size(); ++i) {
    student[i].flag = false;
    student[i].total_ = 0;
    student[i].solved_ = 0;
    student[i].grade_.resize(6, -1);
  }
}

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> grade(6);
  vector<Student> student(n + 1);
  Init(student);
  for (int i = 1; i <= k; ++i) cin >> grade[i];
  for (int i = 0; i < m; ++i) {
    int id, num, score;
    cin >> id >> num >> score;
    student[id].id_ = id;
    if (score == -1 && student[id].grade_[num] == -1) {
      student[id].grade_[num] = 0;
    }
    if (score != -1) {
      student[id].flag = true;
    }
    if (student[id].grade_[num] < score) {
      student[id].grade_[num] = score;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (student[i].grade_[j] != -1) {
        student[i].total_ += student[i].grade_[j];
      }
      if (student[i].grade_[j] == grade[j]) student[i].solved_++;
    }
  }

  sort(student.begin() + 1, student.end(), cmp);
  student[1].rank_ = 1;
  for (int i = 2; i <= n; ++i) {
    if (student[i].total_ == student[i - 1].total_)
      student[i].rank_ = student[i - 1].rank_;
    else
      student[i].rank_ = i;
  }

  for (int i = 1; i <= n; ++i) {
    if (student[i].flag == false) continue;
    printf("%d %05d %d", student[i].rank_, student[i].id_, student[i].total_);
    for (int j = 1; j <= k; ++j) {
      if (student[i].grade_[j] != -1)
        printf(" %d", student[i].grade_[j]);
      else
        printf(" -");
    }
    printf("\n");
  }

  return 0;
}