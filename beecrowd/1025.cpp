/*
Entrada
A entrada contém vários casos de teste, mas o total de casos é menor do que 65.
Cada caso de teste inicia com dois inteiros: N que é o número de mármores e Q que é o número de consultas que Meena deseja fazer.
As próximas N linhas conterão os números escritos em cada um dos N mármores. Os números destes mármores não tem qualquer ordem em particular.
As seguintes Q linhas irão conter Q consultas.
Tenha certeza, nenhum dos números da entrada é maior do que 10000 e nenhum deles é negativo.
A entrada é terminada por um caso de teste onde N = 0 e Q = 0.

Saída
Para cada caso de teste de saída deve haver um número serial do caso de teste.
Para cada consulta, escreva uma linha de saída.
O formato desta linha dependerá se o número consultado estiver ou não escrito em um dos mármores.
Os dois diferentes formatos são descritos abaixo:
'x found at y', se o primeiro marble x foi encontrado na posição y. Posições são numeradas de 1, 2,...  a N.
'x not found', se o marble com o número x não estiver presente.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n, q;
  int counter = 1;

  while (cin >> n >> q) {
    if (!n && !q) break;
    printf("CASE# %d:\n", counter);
    counter++;

    vector<int> numbers;
    for(auto i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      numbers.push_back(tmp);
    }

    sort(numbers.begin(), numbers.end());

    for(auto i = 0; i < q; i++) {
      int tmp;
      cin >> tmp;

      auto it = find(numbers.begin(), numbers.end(), tmp);

      if (it != numbers.end()) {
        printf("%d found at %ld\n", tmp, (it - numbers.begin() + 1));
      } else {
        printf("%d not found\n", tmp);
      }
    }
  }

  return 0;
}