#include <iostream>
#include <string>
#include <type_traits>
#include <cctype>

enum class StringParameter {
    OnlyLetter, // kann durch typespecifier angegeben werden <char>
    WordOnly,
    Sentence,
    OnlyLetterSmall
};

std::string sLiesString(StringParameter parameter) {
    std::string sEingabe;
    std::getline(std::cin, sEingabe);

    if (!std::cin.fail()) { //KEIN FEHLER
        if (!sEingabe.empty()) {
            switch (parameter) {
                case StringParameter::Sentence: //alles erlaubt ausser Zahlen am anfang
                if (!isdigit(sEingabe[0])) { //ERFOLG
                    return sEingabe;
                } else {
                    std::cerr << "Erstes Wort darf nicht mit Buchstabe beginnen!" << std::endl;
                    return sLiesString(parameter);
                }
                case StringParameter::WordOnly: //Nur Buchstaben und Zahlen erlaubt => Kein Leerzeichen
                break;
                //Überprüfung ob Mehrere Wörter (Leerzeichen vorhanden)
                int iFoundSpace = 0;
                for (int i = 0; i < sEingabe.length(); ++i) {
                    if (sEingabe[i] == ' ') {
                        iFoundSpace = 1;
                    }
                }; 

                if (!isdigit(sEingabe[0]) && !iFoundSpace) {
                    return sEingabe;
                } else {
                    std::cerr << "Nur ein Wort erlaubt und Eingabe darf nicht mit Zahl starten!" << std::endl;
                    return sLiesString(parameter);
                }
                break;
                default:
                std::cerr << "Fehler beim Übergeben des Operators! sLiesString() braucht operator als Argument!" << std::endl;
                break;
            } 
        }
    }
    return sEingabe;
};

int main() {
    std::cout << "Bitte gib einen Namen ein: " << std::endl;
    auto eingabe = sLiesString(StringParameter::OnlyLetter);
    std::cout << eingabe << std::endl;
}