
#include <string>
using namespace std;

class FigurasGeometricas{
    protected:
        string nome;
    public:
        FigurasGeometricas();
        FigurasGeometricas(string nome, int Area);
        virtual ~FigurasGeometricas();
        void setNome(string nome);
        string getNome();
};

class Retangulo : public: FigurasGeometricas{}
        private:
            double base;
            double altura;
            double area;

        public:
            Triangulo();
            Triangulo( double base, double altura, double area);
            virtual ~Triangulo();
            void setBase(double base);
            void setAltura(double altura);
            void setArea(double area);
            double getAltura();
            double getBase();
            double getArea();
};

class Triangulo: public: FigurasGeometricas{
        private:
            double base;
            double altura;
            double area;

        public:
            Triangulo();
            Triangulo( double base, double altura, double area);
            virtual ~Triangulo();
            void setBase(double base);
            void setAltura(double altura);
            void setArea(double area);
            double getAltura();
            double getBase();
            double getArea();
};

class Quadrado: public: FigurasGeometricas{
        private:
            double base;
            double area;

        public:
            Triangulo();
            Triangulo( double base, double altura, double area);
            virtual ~Triangulo();
            void setBase(double base);
            void setArea(double area);
            double getBase();
            double getArea();
};

class Circulo: public: FigurasGeometricas{
        private:
            double raio;
            double area;

        public:
            Triangulo();
            Triangulo( double base, double altura, double area);
            virtual ~Triangulo();
            void setRaio(double raio);
            void setArea(double area);
            double getRaio();
            double getArea();
};

#endif
