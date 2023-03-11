#include <iostream>
using namespace std;
int main() {
  int a,b,c;
  cin>>a>>b>>c;
  printf("%d eh o maior\n", max(c, (a+b+abs(a-b))/2));
  return 0;
}