#include <bits/stdc++.h>
int main()
{
  std::vector<int> vec{5, 10, 15, 20};

  std::vector<int>::iterator iterator;

  std::cout << "Original vector ";
  for (int i = 0; i < vec.size(); i++)
    std::cout << " " << vec[i];
  std::cout << " \n";

  int x = 15;

  iterator = std::find(vec.begin(), vec.end(), x);
  if (iterator != vec.end())
  {
    std::cout << "Element x is: " << x;
    std::cout << " \n";
  }
  else
    std::cout << "Element not found \n";
}