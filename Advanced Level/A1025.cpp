#include <bits/stdc++.h>

using namespace std;

struct Student {
  Student(string id, int grade, int location)
      : id_(id), grade_(grade), location_(location) {}
  string id_;
  int grade_;
  int location_;
  int local_rank_;
  int final_rank_;
};

bool cmp(const Student& stu1, const Student& stu2) {
  if (stu1.grade_ != stu2.grade_) return stu1.grade_ > stu2.grade_;
  if (stu1.id_ != stu2.id_) return stu1.id_ < stu2.id_;
}

int main() {
  int n, m;
  cin >> n;
  string id;
  int grade;
  vector<Student> student;
  vector<Student> temp;
  for (int i = 1; i <= n; ++i) {
    cin >> m;
    temp.clear();
    for (int j = 0; j < m; ++j) {
      cin >> id >> grade;
      temp.push_back(Student(id, grade, i));
    }
    sort(temp.begin(), temp.end(), cmp);
    temp[0].local_rank_ = 1;
    for (int j = 1; j < temp.size(); ++j) {
      if (temp[j].grade_ == temp[j - 1].grade_) {
        temp[j].local_rank_ = temp[j - 1].local_rank_;
      } else {
        temp[j].local_rank_ = j + 1;
      }
    }
    student.insert(student.end(), temp.begin(), temp.end());
  }

  sort(student.begin(), student.end(), cmp);
  student[0].final_rank_ = 1;
  for (int i = 1; i < student.size(); ++i) {
    if (student[i].grade_ == student[i - 1].grade_) {
      student[i].final_rank_ = student[i - 1].final_rank_;
    } else {
      student[i].final_rank_ = i + 1;
    }
  }
  cout << student.size() << endl;
  for (int i = 0; i < student.size(); ++i) {
    cout << student[i].id_ << " " << student[i].final_rank_ << " "
         << student[i].location_ << " " << student[i].local_rank_ << endl;
  }

  return 0;
}