#include <iostream>
#include <string>
#include <vector>

#include "sum_integers.hpp"

int main(int argc, char *argv[])
{
  std::vector<int> integers;
  for (auto i = 0; i < argc; i++)
  {
    integers.push_back(std::stoi(argv[i]));
  }

  auto sum = sum_integers(integers);

  std::cout << sum << std::endl;
  return 0;
}