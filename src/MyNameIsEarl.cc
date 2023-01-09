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
    int cathegoryynum, unterpunkt; //Integer für bad und good karma oder good und bad things
    app.add_option("-a, --add", neuBulletPoint, "Füge einen Neuen Bullet Point zur deiner Liste hinzu");
    app.add_option("-A, --activity", activitynum, "Activitynummer mit angeben, damit der neue Inhalt korrekt gespeichert wrid.\n "
                                                    "(1) für things i've done. \n "
                                                    "(2) things happened to me" );
    app.add_option("-C, --cathegory", cathegoryynum, "cathegorynummer mit angeben, damit der neue Inhalt korrekt gespeichert wrid. \n"
                                                    "Bei things i've done: \n"
                                                    " (1) für bad karma \n (2) good karma \n"
                                                    "Bei things happened to me: \n"
                                                    " (1) für good things \n (2) bad things\n");
    app.add_option("-B, --BulletPointsOption", unterpunkt, "BulletPoints unterpunkt\n"
                                                            "(1) füt topic\n"
                                                            "(2) carma Points\n"
                                                            "(3) Involves\n"
                                                            "(4) Date\n");
    app.add_option("-r, --read", filepath, "Path to config file" )
        ->required()
        ->check(CLI::ExistingFile);

    //try & catch Funktion, sollte ein Parse Error auftreten, so wird die "app" geschlossen
    try
    {
        app.parse(argc, argv);

    }
    catch(const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    std::ifstream file{filepath};

    if (!file.is_open()){
        std::cout << "Error file is open! close it! \n" << std::endl;
        exit(0);
    }
    
    nlohmann::json database_object;

    //try & catch Funktion, sollte die file nicht dem "database_object" übergeben werden, so schreibe den Fehler und exit mit Fehler
    try
    {
        database_object = nlohmann::json::parse(file);
    }
    catch (nlohmann::json::parse_error& ex)
    {
        std::cerr << "parse error at byte " << ex.byte << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    //Inhalt der BulletPoints wird ausgegeben
    for (auto& element : database_object["Activity"]){
        int carma_punkte_sum, carma_punkte_pos, carma_punkte_neg, carma_elemetes_pos, carma_elemetes_neg, carma_elemetes_sum;
        //Hier wird durch die Funktion ".size" der Inhalt gezählt und dieser als Integer in carma_elemetes_sum gesetzt 
        carma_elemetes_sum = element["BulletPoints"].size();

        if(activitynum == 1 && element["active"] == true){
           for (auto& Actelement : element["Elements"]){
            if (cathegoryynum == 1 && Actelement["Pluses"] == true){
                for (auto& catelement : Actelement["BulletPoints"]){
                    std::cout << "Du hast insgesammt " << carma_elemetes_sum << "In deiner gutes Karma Liste. Unteranderen folgende dinge: " << catelement["topic"] << std::endl;

                }



            } else {
                for (auto& catelement : Actelement["BulletPoints"]){
                    std::cout << "Du hast insgesammt " << carma_elemetes_sum << "In deiner schlechtes Karma Liste. Unteranderen folgende dinge: " << catelement["topic"] << std::endl;

                }
            }
            

            
            }
           }else{
                for (auto& Actelement : element["Elements"]){
                if (cathegoryynum == 1 && Actelement["Pluses"] == true){
                    for (auto& catelement : Actelement["BulletPoints"]){
                    std::cout << "Du hast insgesammt " << carma_elemetes_sum << "In deiner schlechtes passiert Liste. Unteranderen folgende dinge: " << catelement["topic"] << std::endl;

                    }



                 } else {
                    for (auto& catelement : Actelement["BulletPoints"]){
                    std::cout << "Du hast insgesammt " << carma_elemetes_sum << "In deiner gutes passiert Liste. Unteranderen folgende dinge: " << catelement["topic"] << std::endl;

                }
           
           } 
        }

        //Hier wird "Anzahl Lagerplätze" aufgerufen und auch als Integer gesetzt
       /* if ("BulletPoints" = true){
            for(auto& point : database_object["BulletPoints"]) 
            anzahl_plaetze = element["Anzahl Lagerplätze"];
            }

        //Hier wird er Aktuelle Inhalt, der "Anzahl Lagerplätze" abgezogen. Die zuvor deklarierten Integer werden verrechnet
        leere_plaetze = anzahl_plaetze - belegte_plaetze;
        */

        //Hier wird der Inhalt ausgegeben -Aufgabe 1
        std::cout << "Du hast insgesammt " << carma_elemetes_sum << "In deiner Liste. Unteranderen folgende dinge: " << element["topic"] << std::endl;

        //Hier werden die restlichen Lagerplätze ausgegebnen -Aufgabe 2
        /*std::cout << "Es sind " << leere_plaetze << " von " << anzahl_plaetze << " Plätze frei\n" << std::endl;
         */
    }

    /* Ändern der Inhalte der Eigelesene Datei 
        vieleicht mit in einander verschachtelten for Schleifen
        zu erts wird  die Activity gewählt dann das Elements
        dann wird von BulletPoints zu BulletPoints iteriert*/
    






}

