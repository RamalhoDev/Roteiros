#include <iostream>
#include <string>
#include "Imovel.h"
using namespace std;

int main(){
    Endereco endereco = Endereco("Said abel", "treze de maio", "joao pessoa", "58025380", 37);
    Casa *casa = new Casa(5, 3, 200.5, 100.5, 1, 12600, endereco);
    Terreno *terreno = new Terreno(200, 1, 300000, endereco);
    Apartamento *apartamento = new Apartamento("nascente sul", 4, 2, 250, 100, 1, 1000, endereco);

    string descricao = casa->getDescricao();
    cout << descricao << endl;
    descricao = terreno->getDescricao();
    cout << descricao << endl;
    descricao = apartamento->getDescricao();
    cout << descricao << endl;
    return 0;
}