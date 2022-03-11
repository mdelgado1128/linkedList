// CPP program to illustrate
// Implementation of begin() function
#include <bits/stdc++.h>
using namespace std;

void printList(list<int> l, list<int> p)
{
  list<int>::iterator it;
  list<int>::iterator iter;

  int size = l.size();
  for (it = p.begin(); it != p.end(); ++it)
  {
    int i = 1;
    // cout << *it << " ";
    cout << '\n';

    // cout << i << endl;

    for (iter = l.begin(); iter != l.end(); ++iter, ++i)
    {

      if (*it == i)
      {

        cout << *iter << endl;
      }
    }
  }

  // cout << endl;
  // cout << size;
  // cout << endl;
}
int main()
{
  // declaration of list container
  list<int> p{2, 3, 5};
  list<int> l{6, 7, 8, 9, 10};

  // using begin() to print list
  printList(l, p);
  return 0;
}
