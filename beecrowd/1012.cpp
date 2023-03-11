#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

int main()
{
  double a, b, c;
  cin >> a >> b >> c;
  printf("TRIANGULO: %.3lf\n", (c*a/2.0));
  printf("CIRCULO: %.3lf\n", (PI * pow(c, 2)));
  printf("TRAPEZIO: %.3lf\n", (a+b)*c/2.0);
  printf("QUADRADO: %.3lf\n", pow(b,2));
  printf("RETANGULO: %.3lf\n", a*b);
  return 0;
}

/*
Escreva um programa que leia três valores com ponto flutuante de dupla precisão: A, B e C. Em seguida, calcule e mostre:
a) a área do triângulo retângulo que tem A por base e C por altura.
b) a área do círculo de raio C. (pi = 3.14159)
c) a área do trapézio que tem A e B por bases e C por altura.
d) a área do quadrado que tem lado B.
e) a área do retângulo que tem lados A e B.

3.0 4.0 5.2

TRIANGULO: 7.800
CIRCULO: 84.949
TRAPEZIO: 18.200
QUADRADO: 16.000
RETANGULO: 12.000
*/