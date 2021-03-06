#include "Trabalhador.h"
#include <string>

using namespace std;

Trabalhador::Trabalhador(){
    nome = "";
    salario = 0;
}
Trabalhador::Trabalhador(const string &nome , double salario){
    this -> nome = nome;
    this -> salario = salario;
}
void Trabalhador::setNome(const string &nome){
    this -> nome = nome;
}
void Trabalhador::setSalario(double salario){
    this -> salario = salario;
}
string Trabalhador::getNome(){
    return nome;
}
double Trabalhador::getSalario(){
    return salario;
}


double TrabalhadorAssalariado::calcularPagamento(){
    return salario/4;
}
TrabalhadorAssalariado::TrabalhadorAssalariado() : Trabalhador(){}
TrabalhadorAssalariado::TrabalhadorAssalariado(const string &nome, double salario) : Trabalhador(nome, salario){}

double TrabalhadorPorHora::calcularPagamento(int Horas){
    if(Horas <= 40){
        return Horas*salario;
    }else{
        return 40*salario + ((Horas-40) * (salario*1.5));
    }
}

TrabalhadorPorHora::TrabalhadorPorHora(){}
TrabalhadorPorHora::TrabalhadorPorHora(const string &nome, double salario) : Trabalhador(nome,salario){}
