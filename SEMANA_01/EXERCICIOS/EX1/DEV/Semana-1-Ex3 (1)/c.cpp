//Faça uma função que armazena uma medida inteira em um vetor especificado. Note que não vetores nativos, lembre-se de que você precisa passar ou valor máximo de proteção também que, por acidente, um valor seja escrito em uma área de memória da máxima proteção

#include <iostream>
using namespace std;

int main(){
  int lista[5];
  for (int i = 0; i< 5; i++)
    {
      printf("Digite o número da posição %d");
      scanf("%d", &lista[i]);
    }
  printf("os numeros digitados são: ");
  for (int i= 0; i<5; i++)
    printf("%d", lista[i]);
  return 0;
}
