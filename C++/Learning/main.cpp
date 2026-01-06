#include <iostream>
#include <vector>
#include <memory>


class Shape {
    private:
    int p_iZahl = 1;

    protected: 
    int p_iZahl2 = 2;

    public:

    Shape() {
        std::cout << "Shape Konstruktor wurde aufgerufen" << std::endl;
    }

    virtual void getp_iZahl() {
        std::cout << p_iZahl << std::endl;
    }
};

class Box : public Shape {
    private: int p_iZahlShape;

    public:
    void getp_iZahl() override {
        std::cout << p_iZahlShape << std::endl;
    }

    Box() {
        std::cout << "Box Konstruktor wurde aufgerufen" << std::endl;
    }
};

int main() {

    Shape Form{};
    Box Kasten{};

    std::cerr << "Testfehler" << std::endl;
    std::cout << "Test Output" << std::endl;

    return 0;
}