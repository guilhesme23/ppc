#include <iostream>

using namespace std;

int main() {
  int code, qtd;
  double price;
  double total = 0;
  
  for(int i = 0; i < 2; i++) {
    cin >> code >> qtd >> price;
    total+=(qtd*price);
  }

  printf("VALOR A PAGAR: R$ %.2lf\n", total);
  return 0;
}