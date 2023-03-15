#include <iostream>

int main() {
  int h1,h2,m1,m2;
  std::cin >> h1 >> m1 >> h2 >> m2;

  int diff = (h2*60 + m2) - (h1*60 + m1);

  if (diff <= 0) diff += 24*60;

  int rh = diff/60, rm = diff%60;

  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", rh, rm);
}