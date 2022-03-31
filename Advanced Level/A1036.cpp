#include <bits/stdc++.h>

using namespace std;

struct Person {
  string name_;
  string curriculum_;
  char gender_;
  int score_;
} highest, lowest, temp;

int main() {
  int n;
  cin >> n;
  highest.score_ = -1;
  lowest.score_ = 101;
  bool male = false, female = false;
  while (n--) {
    cin >> temp.name_ >> temp.gender_ >> temp.curriculum_ >> temp.score_;
    if (temp.gender_ == 'F' && temp.score_ > highest.score_) {
      highest = temp;
      female = true;
    }
    if (temp.gender_ == 'M' && temp.score_ < lowest.score_) {
      lowest = temp;
      male = true;
    }
  }

  female == true ? cout << highest.name_ << " " << highest.curriculum_ << endl
                 : cout << "Absent" << endl;
  male == true ? cout << lowest.name_ << " " << lowest.curriculum_ << endl
               : cout << "Absent" << endl;
  (female == false || male == false) ? cout << "NA"
                                     : cout << highest.score_ - lowest.score_;

  return 0;
}