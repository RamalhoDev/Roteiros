#include "Funcionario.h"
#include <string>

using namespace std;

Funcionario::Funcionario(){
    nome = "";
    matricula = 0;
    salario = 0;
}
Funcionario::Funcionario(const string &nome, int matricula, double salario){
    this -> nome = nome;
    this -> matricula = matricula;
    this -> salario = salario;
}
void Funcionario::setNome(const string &nome){
    this -> nome = nome;
}
void Funcionario::setMatricula(int matricula){
    this -> matricula = matricula;
}
void Funcionario::setSalario(double salario){
    this -> salario = salario;
}
string Funcionario::getNome(){
    return nome;
}
double Funcionario::getSalario(){
    return salario;
}
int Funcionario::getMatricula(){
    return matricula;
}

Consultor::Consultor() : Funcionario(){}
Consultor::Consultor(const string &nome, int matricula, double salario) : Funcionario(nome, matricula, salario){}

double Consultor::getSalario(){
    return salario+salario*0.1;
}

double Consultor::getSalario(float percentual){
    return salario + salario*percentual;
}
