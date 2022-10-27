//Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int numero;
  int maximo;
  int minimo;
  cout << "diga o valor para conhecer seu intervalo: "; 
  cin >> numero;
  maximo = numero + (numero*0.2);
  minimo = numero - (numero*0.2);
  cout << "O valor maximo é: "<< maximo <<endl;
  cout << "O valor minimo é: "<< minimo;
}
