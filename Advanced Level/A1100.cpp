#include <bits/stdc++.h>

using namespace std;

vector<string> mars_low = {"jan", "feb", "mar", "apr", "may", "jun",
                           "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> mars_top = {"tam", "hel", "maa", "huh", "tou", "kes",
                           "hei", "elo", "syy", "lok", "mer", "jou"};

unordered_map<string, int> mars_to_num_low;
unordered_map<string, int> mars_to_num_top;
unordered_map<int, string> num_to_mars_low;
unordered_map<int, string> num_to_mars_top;

void Init() {
  for (int i = 0; i < 12; ++i) {
    mars_to_num_low.insert({mars_low[i], i + 1});
    num_to_mars_low.insert({i + 1, mars_low[i]});
    mars_to_num_top.insert({mars_top[i], i + 1});
    num_to_mars_top.insert({i + 1, mars_top[i]});
  }
}

int main() {
  Init();
  int n;
  cin >> n;
  getchar();
  string input;
  while (n--) {
    getline(cin, input);
    if (input[0] >= '0' && input[0] <= '9') {
      int num = atoi(input.c_str());
      if (num == 0)
        cout << "tret" << endl;
      else if (num >= 13) {
        cout << num_to_mars_top[num / 13];
        if (num % 13)
          cout << " " << num_to_mars_low[num % 13] << endl;
        else
          cout << endl;
      } else {
        cout << num_to_mars_low[num] << endl;
      }

    } else {
      int ans = 0;
      if (input.size() > 3) {
        string top(input.begin(), input.begin() + 3);
        string low(input.begin() + 4, input.end());
        ans = mars_to_num_top[top] * 13 + mars_to_num_low[low];
      } else {
        if (mars_to_num_top.find(input) != mars_to_num_top.end())
          ans = mars_to_num_top[input] * 13;
        else
          ans = mars_to_num_low[input];
      }
      cout << ans << endl;
    }
  }

  return 0;
}