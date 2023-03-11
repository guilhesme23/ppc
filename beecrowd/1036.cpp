#include <iostream>
#include <tuple>
#include <cmath>

using namespace std;

int main() {
  double a,b,c;

  cin >>a>>b>>c;

  double delta = pow(b,2) - (4*a*c);
  
  if (delta < 0 || a == 0) {
    cout << "Impossivel calcular\n";
    return 0;
  }

  double x1 = (sqrt(delta) + (b*-1)) / (2.0*a);

  double x2 = ((sqrt(delta)*-1) + (b*-1)) / (2.0*a);

  printf("R1 = %.5lf\n", x1);
  printf("R2 = %.5lf\n", x2);
}
