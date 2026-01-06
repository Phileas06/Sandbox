#include <iostream>
#include <limits>

enum class OperationParameter {
    PositiveOnly,
    NegativeOnly,
    All,
    PosiviveAndZero,
    NegativeAndZero
};

//Read Numbers
template <typename ReturnValue>
ReturnValue readNumber(OperationParameter operation) { //Parameterliste: OperationParameter (positiv, ..)
    ReturnValue value = 0;
    std::cin >> value;

    //Fehler suche:
    if (!std::cin.fail()) { //IS NUMBER
        switch (operation)
        {
        case OperationParameter::PositiveOnly:
            if (value > 0) { //NUMBER
                return value;
            } else {
                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
                return readNumber<ReturnValue>(operation);
            }
            break;
        case OperationParameter::NegativeOnly:
            if (value < 0) { //NUMBER
                return value;
            } else {
                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
                return readNumber<ReturnValue>(operation);
            };
            break;
        case OperationParameter::All:
            return value;
            break;
        case OperationParameter::NegativeAndZero:
            if (value <= 0) { //NUMBER
                return value;
            } else {
                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
                return readNumber<ReturnValue>(operation);
            }
            break;
        case OperationParameter::PosiviveAndZero:
            if (value >= 0) { //NUMBER
                return value;
            } else {
                std::cerr << "Fehler: Zahl liegt nicht im möglichen Wertebereich!" << std::endl;
                return readNumber<ReturnValue>(operation);
            }
            break;
            default:
            std::cout << "Fehler bei der Eingabe: Ungültiger OperationParameter" << std::endl;
            return 0;
        
        }


    } else { // Fehler
        //Wenn string leer
        std::cin.clear(); //setzt Fehlerflags zurück (auch wenn keine gesetzt wurden)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //max größe des stream bis zum zeichen \n
        std::cerr << "Fehler bei der Eingabe" << std::endl;
        return readNumber<ReturnValue>(operation);
    }




}

int main() {
    std::cout << "Gib eine Zahl ein: " << std::endl;
    auto eingabe = readNumber<int>(OperationParameter::PositiveOnly);
    std::cout << "Ausgabe: " << eingabe << std::endl;
    return 0;
}

