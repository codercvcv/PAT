#include <bits/stdc++.h>
using namespace std;

struct Student {
  vector<int> choice_;
  float final_grade_;
  int id_;
  int ge_;
  int gi_;
  int rank_;
};

struct School {
  vector<int> applicant_;
  int quota_;
  int final_rank_;
};

bool cmp(const Student& stu1, const Student& stu2) {
  if (stu1.final_grade_ != stu2.final_grade_)
    return stu1.final_grade_ > stu2.final_grade_;
  return stu1.ge_ > stu2.ge_;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<School> school(m);
  vector<Student> student(n);
  for (int i = 0; i < m; ++i) {
    cin >> school[i].quota_;
  }

  for (int i = 0; i < n; ++i) {
    cin >> student[i].ge_ >> student[i].gi_;
    student[i].final_grade_ = (student[i].ge_ + student[i].gi_) / 2;
    student[i].id_ = i;
    student[i].choice_.resize(k);
    for (int j = 0; j < k; ++j) {
      cin >> student[i].choice_[j];
    }
  }

  sort(student.begin(), student.end(), cmp);
  student[0].rank_ = 1;
  school[student[0].choice_[0]].quota_--;
  school[student[0].choice_[0]].applicant_.push_back(student[0].id_);
  school[student[0].choice_[0]].final_rank_ = 1;
  for (int i = 1; i < n; ++i) {
    if (student[i].final_grade_ == student[i - 1].final_grade_ &&
        student[i].ge_ == student[i - 1].ge_) {
      student[i].rank_ = student[i - 1].rank_;
    } else {
      student[i].rank_ = i + 1;
    }

    for (int j = 0; j < k; ++j) {
      int choice = student[i].choice_[j];
      if (school[choice].quota_) {
        school[choice].quota_--;
        school[choice].final_rank_ = student[i].rank_;
        school[choice].applicant_.push_back(student[i].id_);
        break;
      } else if (school[choice].final_rank_ == student[i].rank_) {
        school[choice].applicant_.push_back(student[i].id_);
        break;
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    if (school[i].applicant_.empty()) {
      cout << endl;
      continue;
    }
    sort(school[i].applicant_.begin(), school[i].applicant_.end());
    for (int j = 0; j < school[i].applicant_.size(); ++j) {
      cout << school[i].applicant_[j];
      if (j < school[i].applicant_.size() - 1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}