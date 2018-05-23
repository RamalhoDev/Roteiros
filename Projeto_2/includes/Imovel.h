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
        string descricao;
    public:    

        Imovel();
        Imovel(
               int tipoDeImovel,
               int tipoOferta, 
               double valor, 
               const Endereco &endereco);
        Imovel(
               int tipoDeImovel,
               int tipoOferta, 
               double valor, 
               const Endereco &endereco,
               string descricao);
        virtual ~Imovel(){}

        void setValor(double valor);
        void setTipoOferta(int tipoOferta);
        void setDescricao(string descricao);
    
        double getValor();
        int getTipoOferta();
        Endereco getEndereco();
        int getTipoDeImovel();
        virtual string getDescricao(){return descricao;}
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
};

class Apartamento: public Imovel{
    protected:
        string posicao;
        int numQuartos, vagasGaragem;
        double valorCondominio, area;
    public:
        Apartamento();
        Apartamento(string posicao,
                    int numQuartos,
                    int vagasGaragem, 
                    double valorConominio, 
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
};

class Flat: public Apartamento{
    protected:
        string ar, internet, tv, lavanderia, limpeza, recepcao;
    public:
        Flat();
        Flat(string ar,
             string internet,
             string tv,
             string lavanderia,
             string limpeza,
             string recepcao,
             string posicao,
             int numQuartos,
             int vagasGaragem, 
             double valorCondominio, 
             double area,
             int tipoOferta,
             int tipoDeImovel, 
             double valor, 
             const Endereco &endereco);
        virtual ~Flat(){}
        string getAr();
        string getInternet();
        string getTv();
        string getLavanderia();
        string getLimpeza();
        string getRecepcao();

        void setAr(string ar);
        void setInternet(string internet);
        void setTv(string tv);
        void setLavanderia(string lavanderia);
        void setLimpeza(string limpeza);
        void setRecepcao(string recepcao);

        string getDescricao();
};

class Studio: public Flat{
    private:
        string piscina, sauna, ginastica;
    public:
        Studio();
        Studio( string piscina,
                string sauna,
                string ginastica,
                string ar,
                string internet,
                string tv,
                string lavanderia,
                string limpeza,
                string recepcao,
                string posicao,
                int numQuartos,
                int vagasGaragem, 
                double valorConominio, 
                double area,
                int tipoOferta,
                int tipoDeImovel, 
                double valor, 
                const Endereco &endereco);
        virtual ~Studio(){}
        string getPiscina();
        string getSauna();
        string getGinastica();

        void setPiscina(string piscina);
        void setSauna(string sauna);
        void setGinastica(string ginastica);

        string getDescricao();
};

#endif
