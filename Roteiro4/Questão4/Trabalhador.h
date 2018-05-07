#ifndef TRABALHADOR_H
#define TRABALHADOR_H

#include <string>

class Trabalhador{
    protected:
        std::string nome;
        double salario;
    public:
        Trabalhador();
        Trabalhador(const std::string &nome , double salario);
        void setNome(const std::string &nome);
        void setSalario(double salario);
        std::string getNome();
        double getSalario();
};

class TrabalhadorAssalariado : public Trabalhador {
    public:
        double calcularPagamento();
        TrabalhadorAssalariado();
        TrabalhadorAssalariado(const std::string &nome, double salario);
};

class TrabalhadorPorHora : public Trabalhador{
    public:
        double calcularPagamento(int Horas);
        TrabalhadorPorHora();
        TrabalhadorPorHora(const std::string &nome, double salario);
};

#endif
