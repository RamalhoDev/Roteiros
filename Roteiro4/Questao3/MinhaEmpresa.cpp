#include <iostream>
#include <string>
#include "Funcionario.h"

using namespace std;

int main(){
    Consultor *consultor1;
    consultor1 = new Consultor("Maritan", 9999999, 10000);
    cout << "Consultor: " << consultor1->getNome()<<endl;
    cout << "Matricula: " << consultor1->getMatricula()<<endl;
    cout << "Salario com percentual de 25%%: " << consultor1->getSalario(0.25)<<endl;
    cout << "Salario com percentual de 10%%: " << consultor1->getSalario()<< endl;

    return 0;
}