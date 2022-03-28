#include <bits/stdc++.h>

using namespace std;

int main()
{
  int failA = 0, failB = 0;
  int a1, a2, b1, b2;
  int N;
  cin >> N;
  while (N--)
  {
    cin >> a1 >> a2 >> b1 >> b2;
    int result = a1 + b1;
    if (result == a2 && result != b2) {
      failB++;
    } else if (result != a2 && result == b2) {
      failA++;
    }
  }
  
  cout << failA << " " << failB;
  return 0;
}