#include <iostream>
#include <string>
#include "Trabalhador.h"

using namespace std;

int main(){
    TrabalhadorAssalariado *funcionario1;
    TrabalhadorPorHora *funcionario2;
    funcionario1 = new TrabalhadorAssalariado("Rodrigo", 750);
    funcionario2 = new TrabalhadorPorHora("Bruno", 45);

    cout << "Salario funcionario1 = "<< funcionario1->getSalario()<<endl;
    cout << "Salario funcionario2 = "<< funcionario2->getSalario()<<endl;
    cout<< "Pagamento por semana: R " << funcionario1->calcularPagamento()<<endl;
    cout<< "Pagamento por semana: R " << funcionario2->calcularPagamento(35)<<endl;

    return 0;
}
