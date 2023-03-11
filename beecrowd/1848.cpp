#include <iostream>

using namespace std;

int main()
{
  string input;
  uint total = 0;
  while (getline(cin, input))
  {
    if (input.find('*') != input.npos || input.find('-') != input.npos)
    {
      for (int i = 0; i < 3; i++)
      {
        switch (input[i])
        {
        case '*':
          total += 1 * (1 << (2-i));
          break;
        default:
          break;
        }
      }
    }
    else
    {
      cout << total << endl;
      total = 0;
    }
  }

  return 0;
}