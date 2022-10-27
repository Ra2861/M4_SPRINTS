#include <iostream>
#include <algorithm>
using namespace std;

template <typename T, size_t N> const T* mybegin(const T (&a)[N]) { return a; }
template <typename T, size_t N> const T* myend  (const T (&a)[N]) { return a+N; }

/*int main() {
  
  int x[5] = {};
  cout << "Qual a distância para direita?!\n";
  cin >> x[1];
  cout << "Qual a distância para esquerda?!\n";
  cin >> x[2];
  cout << "Qual a distância para cima?!\n";
  cin >> x[3];
  cout << "Qual a distância para baixo?!\n";
  cin >> x[4];
  std::cout << *std::max_element(mybegin(x), myend(x)) << '\n';
	std::cout << *std::min_element(mybegin(x), myend(x)) << '\n';
  }*/

int main(){
  int direita ;
  int esquerda;
  int cima;
  int baixo;
  int x[4] = { };
  cout << "direita: "; 
  cin >> x[0]; 
	cout << "esquerda: "; 
  cin >> x[1]; 
 	cout << "cima: "; 
  cin >> x[2]; 
  cout << "baixo: "; 
  cin >> x[3];
  cout<<"elemeto maximo ";
	std::cout << *std::max_element(mybegin(x), myend(x)) << '\n';
  cout<<"elemento minimo ";
	std::cout << *std::min_element(mybegin(x), myend(x)) << '\n';
  }