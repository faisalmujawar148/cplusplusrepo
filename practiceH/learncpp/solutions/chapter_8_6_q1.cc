#include <iostream>

void calculate(int x, int y, char o) {
  switch (o) {
  case '+':
    std::cout << (x + y) << '\n';
    return;
  case '-':
    std::cout << (x - y) << '\n';
    return;
  case '*':
    std::cout << (x * y) << '\n';
    return;
  case '/':
    std::cout << (x / y) << '\n';
    return;
  case '%':
    std::cout << (x % y) << '\n';
    return;
  default:
    std::cout << "Please enter a valid operator" << '\n';
    return;
  }
}

int main() {
  int num1{};
  int num2{};
  char op = {};

  std::cout << "Enter the first number: ";
  std::cin >> num1;

  std::cout << "Enter the second number: ";
  std::cin >> num2;

  std::cout << "Enter a mathematical operator(+, -, *, /, or % ): ";
  std::cin >> op;
  calculate(num1, num2, op);
}
