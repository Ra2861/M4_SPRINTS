#include <iostream>
using namespace std;
int main() {
  int direita;
  int esquerda;
  int baixo;
  int cima;
  cout <<"Quanto seu robo podera ir para a direita?"<<endl;
  cin >> direita;
  cout <<"Quanto seu robo podera ir para a esquerda?"<<endl;
  cin >> esquerda;
  cout <<"Quanto seu robo podera ir para a cima?"<<endl;
  cin >> cima;
  cout <<"Quanto seu robo podera ir para a baixo?"<<endl;
  cin >> baixo;
  for(int n = 0; n < direita; n++){
        cout << "direita " << endl;
    }
    cout<<"para"<<endl;
  for(int n=0; n < esquerda; n++){
        cout<<"esquerda "<<endl;
    }
    cout<<"para"<<endl;
  for(int n=0; n < cima; n++){
        cout<<"cima"<<endl;
    }
    cout<<"para"<<endl;

  for(int n=0; n < baixo; n++){
        cout<<"baixo"<<endl;
    }
    cout<<"para"<<endl;
    return 0;
}