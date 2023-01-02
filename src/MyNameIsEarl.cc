#include <CLI/CLI.hpp>
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

using json = nlohmann::json;

/*
Vorab zu diesem Programm. Dieses ist in Zussammenarbeit in der Vorlesung entstanden (BZW ich habe einiges von https://github.com/CedricNett/CLI11/blob/main/src/lagerhalterungsystem.cc abgeschrieben) und damit nicht meine eigene Kreation!
Ich habe versucht mit Kommentaren manche aufrufe zu erklären, diese enthalten sicherlich Fehler!
Zum Ablauf, wenn ihr diese clonen solltet:
Als Beispiel folgende aufrufe 1 zu 1 im Terminal "hinschreiben":
    ./build/MyNameIsEarl.cc -r src/MyNameIsEarl.json -a _in_Regal_2 -n 2
    Fernseher
    "Ändere Fernseher zu Test 1"
    a                                   ( einfach um diesen direkt zu überspringen das ist ein Bug bzw. ein feature :D )
    SAT-Anlage
    "Ändere SAT-Anlage zu Test 2"
  
    TEST
Damit solltet ihr eine verändete .json erhalten. Viel Spaß!
*/
int AddToMyList()
{
    return 0;
}

int DelleteFormMyList()
{
    return 0;
}

int ShowMyList()
{
    return 0;
}

int ChangeMyList()
{
    return 0;
}

int main(int argc, char** argv)
{
    std::cout << "Hey "
}

