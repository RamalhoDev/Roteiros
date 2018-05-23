#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>
#include <fstream>

using namespace std;

//Objeto Endereço possui informacoes comuns a todos os imoveis
class Endereco{
    protected:
        string logradouro, bairro, cidade, cep;
        int numero;
    public:
        //Informações
        Endereco();
        Endereco(string logradouro, 
                 string bairro, 
                 string cidade, 
                 string cep, 
                 int numero);
    
        //Destroi o objeto
        virtual ~Endereco(){}
        
        //Ler essas informações
        string getLogradouro();
        string getBairro();
        string getCidade();
        string getCep();
        int getNumero();
    
        //Seta as variaves do endereço com a string inserida
        void setLogradouro(string logradouro);
        void setBairro(string bairro);
        void setCidade(string cidade);
        void setCep(string cep);
        void setNumero(int numero);
};

//Classe que especifica o que o usuario deseja fazer no programa
class Imovel{
    //Classe Pai
    protected:
    //Variaveis de ação
        static const int imovel_para_vender = 1;
        static const int imovel_para_alugar = 0;
        int tipoOferta, tipoDeImovel;
        double valor;
        Endereco endereco;
        string descricao;
    public:    
    //Torna público o tipo de imovel, o tipo de oferta, o valor e a const do endereço
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
    
        //Destroi o objeto
        virtual ~Imovel(){}
    
        //Seta as variaves do endereço com os caracteres inseridos
        void setValor(double valor);
        void setTipoOferta(int tipoOferta);
        void setDescricao(string descricao);
    
        //Cadastra o valor, oferta, o endereco e o tipo de imovel
        double getValor();
        int getTipoOferta();
        Endereco getEndereco();
        int getTipoDeImovel();
        
        virtual string getDescricao(){return descricao;}
};


class Casa: public Imovel{
    //Classe filho do imovel
    
    //Variaveis de uma casa 
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
    
        //Destrutor
        virtual ~Casa(){}

         //Seta as variaves do endereço com os valores inseridos
        void setNumPavimentos(int numPavimentos);
        void setNumQuartos(int numQuartos);
        void setAreaTerreno(double areaTerreno);
        void setAreaConstruida(double areaConstruida);

        //Recebe o valores inseridos como um GET
        string getDescricao();
        int getNumPavimentos();
        int getNumQuartos();
        double getAreaTerreno();
        double getAreaConstruida();
};

class Apartamento: public Imovel{
    //Classe filho do imovel
    
    //Variaveis da classe
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
    
        //Seta as informações
        void setPosicao(string posicao);
        void setNumQuartos(int numQuartos);
        void setVagasGaragem(int vagasGaragem);
        void setValorCondominio(double valorCondominio);
        void setArea(double area);
        
        //Ler as entradas
        string getDescricao();
        string getPosicao();
        int getNumQuartos();
        int getVagasGaragem();
        double getValorCondominio();
        double getArea();

};

class Terreno: public Imovel{
     //Classe filho do imovel
    
    //Variaveis da classe
    private:
        double area;
    public:
        Terreno();
        Terreno(double area,
                int tipoOferta,
                int tipoDeImovel, 
                double valor, 
                const Endereco &endereco);
    
        //Destrutor
        virtual ~Terreno(){}
        
       //Insere o valor da area
        void setArea(double area);
        
        //Ler as entradas
        string getDescricao();
        double getArea();
};

class Flat: public Apartamento{ 
    //Classe Flat Herdeiro de Apartamento
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
    
        //Destutor
        virtual ~Flat(){}
    
        //Ler as entradas
        string getAr();
        string getInternet();
        string getTv();
        string getLavanderia();
        string getLimpeza();
        string getRecepcao();

        //Seta as informações
        void setAr(string ar);
        void setInternet(string internet);
        void setTv(string tv);
        void setLavanderia(string lavanderia);
        void setLimpeza(string limpeza);
        void setRecepcao(string recepcao);

        string getDescricao();
};

class Studio: public Flat{ 
    //Classe Studio Herdeiro de Flat
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
    
        //Destroi
        virtual ~Studio(){}
    
        //Ler as entradas
        string getPiscina();
        string getSauna();
        string getGinastica();

        //Seta as informações
        void setPiscina(string piscina);
        void setSauna(string sauna);
        void setGinastica(string ginastica);

        string getDescricao();
};

#endif
