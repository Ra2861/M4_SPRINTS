// 2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor

#include <iostream>
using namespace std;
int main() {
  int tecla;
  cout << "Digite um numero!\n";
  cin >> tecla;
  cout << "A o numero digitado foi " << tecla <<endl;
  return tecla;
}