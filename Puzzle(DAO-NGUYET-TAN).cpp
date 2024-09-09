#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Kh?i t?o Stack
  stack<int> stack;

  // Nh?p s? th?p phân c?n chuy?n d?i
  int soThapPhan;
  cout << "Nh?p s? th?p phân: ";
  cin >> soThapPhan;

  // Chia s? th?p phân cho 2 và luu ph?n du vào Stack
  int soDu = soThapPhan;
  while (soDu > 0) {
    stack.push(soDu % 2);
    soDu /= 2;
  }

  // In k?t qu? (s? nh? phân)
  cout << "S? nh? phân: ";
  while (!stack.empty()) {
    cout << stack.top();
    stack.pop();
  }

  return 0;
}

