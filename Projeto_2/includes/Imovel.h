#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>
#include <fstream>
using namespace std;

class Endereco{
    protected:
        string logradouro, bairro, cidade, cep;
        int numero;
    public:
        Endereco();
        Endereco(string logradouro, 
                 string bairro, 
                 string cidade, 
                 string cep, 
                 int numero);
        virtual ~Endereco(){}

        string getLogradouro();
        string getBairro();
        string getCidade();
        string getCep();
        int getNumero();

        void setLogradouro(string logradouro);
        void setBairro(string bairro);
        void setCidade(string cidade);
        void setCep(string cep);
        void setNumero(int numero);
};


class Imovel{
    protected:
        static const int imovel_para_vender = 1;
        static const int imovel_para_alugar = 0;
        int tipoOferta, tipoDeImovel;
        double valor;
        Endereco endereco;

    public:    

        Imovel();
        Imovel(int tipoDeImovel,
               int tipoOferta, 
               double valor, 
               const Endereco &endereco);
        virtual ~Imovel(){}

        void setValor(double valor);
        void setTipoOferta(int tipoOferta);
    
        double getValor();
        int getTipoOferta();
        Endereco getEndereco();
        int getTipoDeImovel();
        virtual string getDescricao(){return 0;}

        virtual void escreveNoArquivo(ofstream &arquivo){}
        virtual void cadastrarImoveis(){}
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
            int tipoDeImovel, 
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

        void escreveNoArquivo(ofstream &arquivo);
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
                    int tipoDeImovel, 
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
        
        void escreveNoArquivo(ofstream &arquivo);
};

class Terreno: public Imovel{
    private:
        double area;
    public:
        Terreno();
        Terreno(double area,
                int tipoOferta,
                int tipoDeImovel, 
                double valor, 
                const Endereco &endereco);
        virtual ~Terreno(){}

        void setArea(double area);

        string getDescricao();
        double getArea();

        void escreveNoArquivo(ofstream &arquivo);
};

#endif
