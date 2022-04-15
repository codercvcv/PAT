#include <bits/stdc++.h>

using namespace std;

struct Student {
  string id_;
  int average_;
  int c_language_;
  int mathematic_;
  int english_;
  int best_rank_;
  int rank_way_;
  vector<int> rank_;
};

bool cmp_c_language(const Student& stu1, const Student& stu2) {
  return stu1.c_language_ > stu2.c_language_;
}

bool cmp_mathematic(const Student& stu1, const Student& stu2) {
  return stu1.mathematic_ > stu2.mathematic_;
}

bool cmp_english(const Student& stu1, const Student& stu2) {
  return stu1.english_ > stu2.english_;
}

bool cmp_average(const Student& stu1, const Student& stu2) {
  return stu1.average_ > stu2.average_;
}

void UpdateAverageRank(vector<Student>& student) {
  student[0].rank_[0] = 1;
  for (int i = 1; i < student.size(); ++i) {
    if (student[i].average_ == student[i - 1].average_) {
      student[i].rank_[0] = student[i - 1].rank_[0];
    } else {
      student[i].rank_[0] = i + 1;
    }
  }
}

void UpdateCLanguageRank(vector<Student>& student) {
  student[0].rank_[1] = 1;
  for (int i = 1; i < student.size(); ++i) {
    if (student[i].c_language_ == student[i - 1].c_language_) {
      student[i].rank_[1] = student[i - 1].rank_[1];
    } else {
      student[i].rank_[1] = i + 1;
    }
  }
}

void UpdataMathematicRank(vector<Student>& student) {
  student[0].rank_[2] = 1;
  for (int i = 1; i < student.size(); ++i) {
    if (student[i].mathematic_ == student[i - 1].mathematic_) {
      student[i].rank_[2] = student[i - 1].rank_[2];
    } else {
      student[i].rank_[2] = i + 1;
    }
  }
}

void UpdateEnglishRank(vector<Student>& student) {
  student[0].rank_[3] = 1;
  for (int i = 1; i < student.size(); ++i) {
    if (student[i].english_ == student[i - 1].english_) {
      student[i].rank_[3] = student[i - 1].rank_[3];
    } else {
      student[i].rank_[3] = i + 1;
    }
  }
}

bool check(const vector<Student>& student, const string& id, int& index) {
  bool flag = false;
  for (int i = 0; i < student.size(); ++i) {
    if (student[i].id_ == id) {
      flag = true;
      index = i;
      break;
    }
  }
  return flag;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Student> student(n);
  char mp[4] = {'A', 'C', 'M', 'E'};
  string temp;
  for (int i = 0; i < n; ++i) {
    cin >> student[i].id_ >> student[i].c_language_ >> student[i].mathematic_ >>
        student[i].english_;
    student[i].average_ = (student[i].c_language_ + student[i].mathematic_ +
                           student[i].english_) /
                          3;
    student[i].rank_.reserve(4);
  }

  sort(student.begin(), student.end(), cmp_average);
  UpdateAverageRank(student);
  sort(student.begin(), student.end(), cmp_c_language);
  UpdateCLanguageRank(student);
  sort(student.begin(), student.end(), cmp_mathematic);
  UpdataMathematicRank(student);
  sort(student.begin(), student.end(), cmp_english);
  UpdateEnglishRank(student);
  for (int i = 0; i < student.size(); ++i) {
    student[i].best_rank_ = student[i].rank_[0];
    for (int j = 1; j < 4; ++j) {
      if (student[i].rank_[j] < student[i].best_rank_) {
        student[i].best_rank_ = student[i].rank_[j];
      }
    }
    for (int j = 0; j < 4; ++j) {
      if (student[i].rank_[j] == student[i].best_rank_) {
        student[i].rank_way_ = j;
        break;
      }
    }
  }

  while (m--) {
    cin >> temp;
    int index = -1;
    if (check(student, temp, index)) {
      cout << student[index].best_rank_ << " " << mp[student[index].rank_way_]
           << endl;
    } else {
      cout << "N/A" << endl;
    }
  }

  return 0;
}