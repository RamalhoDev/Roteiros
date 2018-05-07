#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>

using namespace std;

class Funcionario{
    protected:
        int matricula;
        double salario;
        string nome;
    public:
        Funcionario();
        Funcionario(const string &nome, int matricula, double salario);
        void setNome(const string &nome);
        void setMatricula(int matricula);
        void setSalario(double salario);
        string getNome();
        virtual double getSalario();
        int getMatricula();
};

class Consultor : public Funcionario{
    public:
        Consultor();
        Consultor(const string &nome, int matricula, double salario);
        double getSalario();
        double getSalario(float percentual);
};

#endif