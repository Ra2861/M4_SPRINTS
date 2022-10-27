
#include <stdio.h>
int main()
{
  int lista[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Digite o numero da posicao %d: ", i + 1);
        scanf("%d", &lista[i]);
    }

    printf("\nOs numeros digitados sao:");
    for (int i = 0; i < 5; i++)
        printf(" %d", lista[i]);
    return 0;
}

