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

/*int AddToMyList()
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
*/

int main(int argc, char** argv){
    std::cout << "Hey du tragischer Titelheld dieser US-amerikanischen Comedyserie!" << "\n" << std::endl;
    std::cout << "Lass uns doch mal sehen, was du alles auf dem Kerbholz hast." << "\n" << std::endl;
    CLI::App app{"Füge deine Carma-Punkte hinzu mit: -r in src/TheList.json \n "};
    std :: string filepath, inhalt, charmbalance, aendern, neuBulletPoint; //Strings für die  Optionen 
    int activitynum; //Integer für things i've done and happened
    int cathegoryynum; //Integer für bad und good karma oder good und bad things
    app.add_option("-a, --add", neuBulletPoint, "Füge einen Neuen Bullet Point zur deiner Liste hinzu");
    app.add_option("-A --activity", activitynum, "Activitynummer mit angeben, damit der neue Inhalt korrekt gespeichert wrid.\n "
                                                    "(1) für things i've done. \n "
                                                    "(2) things happened to me" );
    app.add_option("-C --cathegory", cathegoryynum, "cathegorynummer mit angeben, damit der neue Inhalt korrekt gespeichert wrid. \n"
                                                    "Bei things i've done: \n"
                                                    " (1) für bad karma \n (2) good karma \n"
                                                    "Bei things happened to me: \n"
                                                    " (1) für good things \n (2) bad things\n");
    app.add_option("-r, --read", filepath, "Path to config file" )
        ->required()
        ->check(CLI::ExistingFile);


}

