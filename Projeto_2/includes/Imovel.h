#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>
using namespace std;

class Endereco{
    private:
        string logradouro, bairro, cidade, cep;
        int numero;
    public:
        Endereco();
        Endereco(string logradouro, 
                 string bairro, 
                 string cidade, 
                 string cep, 
                 int numero);

        string getLogradouro();
        string getBairro();
        string getCidade();
        string getCep();
        int getNumero();

        virtual ~Endereco(){}
};


class Imovel{
    protected:
        static const int imovel_para_vender = 1;
        static const int imovel_para_alugar = 0;
        int tipoOferta;
        double valor;
        Endereco endereco;

    public:    
        void setValor(double valor);
        void setTipoOferta(int tipoOferta);
        
        double getValor();
        int getTipoOferta();
        Endereco getEndereco();
        virtual string getDescricao(){return 0;}
        
        Imovel();
        Imovel(
               int tipoOferta, 
               double valor, 
               const Endereco &endereco);
        virtual ~Imovel(){}
};


class Casa: public Imovel{
    private:
        int numPavimentos, numQuartos;
        double areaTerreno, areaConstruida;
    public:
        Casa();
        Casa(int numPavimentos, 
            int numQuartos, 
            double areaTerreno, 
            double areaConstruida, 
            int tipoOferta, 
            double valor, 
            const Endereco &endereco);
        virtual ~Casa(){}
        void setNumPavimentos(int numPavimentos);
        void setNumQuartos(int numQuartos);
        void setAreaTerreno(double areaTerreno);
        void setAreaConstruida(double areaConstruida);
        string getDescricao();
        int getNumPavimentos();
        int getNumQuartos();
        double getAreaTerreno();
        double getAreaConstruida();
};

class Apartamento: public Imovel{
    private:
        string posicao;
        int numQuartos, vagasGaragem;
        double valorCondominio, area;
    public:
        Apartamento();
        Apartamento(string posicao, 
                    int numQuartos, 
                    int vagasGaragem, 
                    double valorCondominio, 
                    double area,
                    int tipoOferta, 
                    double valor, 
                    const Endereco &endereco);
        virtual ~Apartamento(){}
        void setPosicao(string posicao);
        void setNumQuartos(int numQuartos);
        void setVagasGaragem(int vagasGaragem);
        void setValorCondominio(double valorCondominio);
        void setArea(double area);
        string getDescricao();
        string getPosicao();
        int getNumQuartos();
        int getVagasGaragem();
        double getValorCondominio();
        double getArea();
};

class Terreno: public Imovel{
    private:
        double area;
    public:
        Terreno();
        Terreno(double area,
                int tipoOferta, 
                double valor, 
                const Endereco &endereco);
        void setArea(double area);
        string getDescricao();
        double getArea();
        virtual ~Terreno(){}
};

#endif
