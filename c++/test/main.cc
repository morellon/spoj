#include <iostream>

int main ()
{
  int i;
  std::cin >> i;
  while (i != 42) {
     std::cout << i << "\n";
     std::cin >> i;
  }
}