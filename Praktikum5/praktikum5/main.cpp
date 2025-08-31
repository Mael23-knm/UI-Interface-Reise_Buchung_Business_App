
#include "travelagencyui.h"
#include "travelagency.h"
#include<iostream>
#include<string>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<TravelAgency> agency = std::make_shared<TravelAgency>();
    TravelAgencyUI t(agency);
    t.show();

    return a.exec();
}



























/*int main() {
    TravelAgency travelAgency;
   // Abfrage von Dateien Json/Binary

    bool laufzeit = true;
    char DateiNummer;
    while(laufzeit){
        try{
            std::cout<<"1- JSON Datei einlesen "<<std::endl;
            std::cout<<"2- Binary Datei einlesen "<<std::endl;
            std::cout<<"0- Programm beenden "<<std::endl; std::cout<<"\n\n";
            std::cout<<"Welche Datei wuerden Sie einlesen? "<<std::endl;
            std::cin>>DateiNummer; std::cout<<"\n";
        if(DateiNummer<'0' || DateiNummer>'2'){
            throw std::invalid_argument ("Falsche Eingabe!!!"); std::cout<<"\n";
        }

        switch (DateiNummer) {
        case '1':
            try{
              travelAgency.readFile(); // Rufe die Methode readFile auf, um Daten aus der JSON-Datei zu lesen
            }catch(std::out_of_range const& err){
              std::cout<<err.what()<<std::endl;
            }catch (std::invalid_argument const& err) {
              char antwort;
              std::cout<< err.what() <<std::endl;
              std::cout<<"Haben Sie schon die Datein korrigiert? (j/n) \n";
              std::cin>>antwort;
              if(antwort == 'n' || antwort== 'N'){
                std::cout<<"Korrigieren Sie erstmal die Datei und versuchen Sie spaeter noch mal!\n" <<std::endl;
                 laufzeit=false;
              }else if(antwort == 'j' || antwort == 'J'){
                 continue;
              }
            }catch (std::exception const& err) {
              std::cout<< err.what() <<std::endl;
            }catch (...) {
            }

               break;
        case '2':
            travelAgency.readBinaryFile();// Rufe die Methode readBinaryFile auf, um Daten aus der BINARY-Datei zu lesen
            break;
        case '0':
            laufzeit = false;
            break;
        default:
            std::cout<<"Ungueltige Eingabe!!! "<<std::endl; std::cout<<"\n";
            break;
        }

        }
         catch (std::invalid_argument const& err) {
        std::cout<< err.what() <<std::endl;
        }

    }




    return 0;
}
*/
