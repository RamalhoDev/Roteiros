#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>
using namespace std;

class Imovel{
    protected:
        int imovel_para_vender, imovel_para_alugar, tipoOferta;
        double valor;
        Endereco endereco;

    public:
        double getValor();
        int getTipoOferta();
        Endereco getEndereco();
        string getDescricao();
        Imovel();
        virtual ~Imovel();
};

class Endereco{
    private:
        string logradouro, bairro, cidade, cep;
        int numero;
    public:
        Endereco();
        virtual ~Endereco();
};

class Casa: public Imovel{
    private:
        int numPavimentos, numQuartos;
        double areaTerreno, areaConstruida;
    public:
        Casa();
        virtual ~Casa();
};

class Apartamento: public Imovel{
    private:
        string posicao;
        int numQuartos, vagasGaragem;
        double valorCondominio, area;
    public:
        Apartamento();
        virtual ~Apartamento();
};

class Terreno: public Imovel{
    private:
        double area;
    public:
        Terreno();
        virtual ~Terreno();
};

#endif