#include <bits/stdc++.h>
using namespace std;

struct Mouse {
  int weight;
  int rank;
};

int main() {
  int np, ng, order;
  cin >> np >> ng;
  vector<Mouse> mouse(np);
  for (int i = 0; i < np; ++i) {
    cin >> mouse[i].weight;
  }

  queue<int> q;
  for (int i = 0; i < np; ++i) {
    cin >> order;
    q.push(order);
  }

  int temp = np, group;
  while (q.size() != 1) {
    if (temp % ng == 0)
      group = temp / ng;
    else
      group = temp / ng + 1;

    for (int i = 0; i < group; ++i) {
      int k = q.front();
      for (int j = 0; j < ng; ++j) {
        if (i * ng + j >= temp) break;
        int front = q.front();
        if (mouse[front].weight > mouse[k].weight) {
          k = front;
        }
        mouse[front].rank = group + 1;
        q.pop();
      }
      q.push(k);
    }
    temp = group;
  }

  mouse[q.front()].rank = 1;
  for (int i = 0; i < np; ++i) {
    cout << mouse[i].rank;
    if (i < np - 1) cout << " ";
  }

  return 0;
}