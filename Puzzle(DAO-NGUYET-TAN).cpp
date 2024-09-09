#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Kh?i t?o Stack
  stack<int> stack;

  // Nh?p s? th?p ph�n c?n chuy?n d?i
  int soThapPhan;
  cout << "Nh?p s? th?p ph�n: ";
  cin >> soThapPhan;

  // Chia s? th?p ph�n cho 2 v� luu ph?n du v�o Stack
  int soDu = soThapPhan;
  while (soDu > 0) {
    stack.push(soDu % 2);
    soDu /= 2;
  }

  // In k?t qu? (s? nh? ph�n)
  cout << "S? nh? ph�n: ";
  while (!stack.empty()) {
    cout << stack.top();
    stack.pop();
  }

  return 0;
}

