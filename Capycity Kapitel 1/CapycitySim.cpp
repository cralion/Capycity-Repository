#include "CapycitySim.h"
#include <iostream>
using namespace std;

void CapycitySim::bauplanAusgeben() {
    for (int i = 0; i < bauplanLaenge; i++) {
        for (int j = 0; j < bauplanBreite; j++) {
            cout << bauplan[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void CapycitySim::gebaeudeSetzen(int koordinateX, int koordinateY, Building* building) {

    bool buildingAreaBlocked = false;



    //Check if building area blocked
    if (((building->getLaenge() + koordinateY) > bauplanLaenge) or (building->getBreite() + koordinateX) > bauplanBreite) {
        buildingAreaBlocked = true;
    }
    else {
        for (int i = koordinateY; i < (building->getLaenge() + koordinateY); i++) {
            for (int j = koordinateX; j < (building->getBreite() + koordinateX); j++) {
                if (bauplan[i][j] != '0') {
                    buildingAreaBlocked = true;
                }
            }
        }
    }

    //Wenn Baubereich nicht blockiert setze Gebaeude
    if (!buildingAreaBlocked) {
        //Setze label fuer das Gebaude im Bauplan
        for (int i = koordinateY; i < (building->getLaenge() + koordinateY); i++) {
            for (int j = koordinateX; j < (building->getBreite() + koordinateX); j++) {
                bauplan[i][j] = building->getLabel();
            }
        }
        //pruefe welche Stelle im building-Array frei ist und Einfuegen des pointers zu dem Gebaeude an der Stelle
        for (int i = 0; i < sizeof(buildings) / sizeof(buildings[0]); i++) {
            if (buildings[i] == nullptr) {
                buildings[i] = building;
                i = buildingsSize; //Schleife abbrechen
            }
            //TODO: Meldung, wenn Array voll
        }
    }
    else {
        cout << "Baubereich blockiert" << endl;
    }

}

void CapycitySim::gebaeudeLoeschen(Building* building) {

    //Loesche Gebaeude auf Bauplan
    //Setze label fuer das Gebaude im Bauplan zurueck
    for (int i = building->getKoordinateY(); i < (building->getLaenge() + building->getKoordinateY()); i++) {
        for (int j = building->getKoordinateX(); j < (building->getBreite() + building->getKoordinateX()); j++) {
            bauplan[i][j] = '0';
        }
    }

    //Loesche Gebaeude(zeiger) in Array
    for (int i = 0; i < buildingsSize; i++) {
        if (building == buildings[i]) {
            buildings[i] = nullptr;
            i = buildingsSize;
        }
    }
    //delete[] building;

}

void CapycitySim::run() {


    bool running = true;
    int menuSelection;
    while (running) {

        //Gebe Menue aus
        cout << "Waehle was du tun moechtest" << endl;
        cout << "1. Gebaeudeliste ausgeben" << endl;
        cout << "2. Gebaeude setzen" << endl;
        cout << "3. Gebaude loeschen" << endl;
        cout << "4. Bauplan ausgeben" << endl;
        cout << "5. Legende ausgeben" << endl;
        cout << "6. Programm beenden" << endl;
        cout << endl;
        cin >> menuSelection;


        switch (menuSelection) {
        case 1: {
            //TODO: implement Gebaeudeliste ausgeben Methode
            for (int i = 0; i < buildingsSize; i++) {
                if (buildings[i] != nullptr) {
                    cout << buildings[i]->getLabel() << "   X: " << buildings[i]->getKoordinateX() << "   Y: "
                        << buildings[i]->getKoordinateY() << "   Einzelpreis: " << (buildings[i]->getGrundpreis() + buildings[i]->getMaterialpreis()) << endl;
                }
            }
            //Gesamtpreis berechnen
            int gesamtpreis = 0;
            for (int i = 0; i < buildingsSize; i++) {
                if (buildings[i] != nullptr) {
                    gesamtpreis += (buildings[i]->getGrundpreis() + buildings[i]->getMaterialpreis());
                }
            }
            cout << "Gesamtpreis: " << gesamtpreis << endl;


        } break;
        case 2: {
            int koordX;
            cout << "Koordinate X eingeben: " << endl;
            cin >> koordX;
            int koordY;
            cout << "Koordinate Y eingeben:" << endl;
            cin >> koordY;
            char gebaeudeTyp;
            cout << "Label des Gebaeudetyps eingeben:" << endl;
            cin >> gebaeudeTyp;
            switch (gebaeudeTyp) {
                //Solar
            case 'S': {
                Building* gebaeude = new Solarkraftwerk(koordX, koordY);
                gebaeudeSetzen(koordX, koordY, gebaeude);
            } break;
                //Windkraft
            case 'W': {
                Building* gebaeude = new Windkraftwerk(koordX, koordY);
                gebaeudeSetzen(koordX, koordY, gebaeude);
            } break;
                //Wasserkraft
            case 'A': {
                Building* gebaeude = new Wasserkraftwerk(koordX, koordY);
                gebaeudeSetzen(koordX, koordY, gebaeude);
            } break;
            default: {
                cout << "Label nicht vorhanden!" << endl;
            } break;
            }
        } break;
        case 3: {
            //Koordinaten eingeben
            int koordX;
            cout << "Koordinate X eingeben: " << endl;
            cin >> koordX;
            int koordY;
            cout << "Koordinate Y eingeben:" << endl;
            cin >> koordY;

            //TODO: implement Gebaeude mit richtigen Koordinaten finden
            Building* buildingToDelete = nullptr;
            bool buildingToDeleteFound = false;
            for (int i = 0; i < buildingsSize; i++) {
                if (buildings[i] != nullptr) {
                    if ((koordX == buildings[i]->getKoordinateX()) & (koordY == buildings[i]->getKoordinateY())) {
                        buildingToDelete = buildings[i];
                        i = buildingsSize;
                        buildingToDeleteFound = true;
                    }
                }
            }
            //TODO: implement Gebauede mit Koordinaten loeschen
            if (buildingToDeleteFound) {
                gebaeudeLoeschen(buildingToDelete);
            }
            else {
                cout << "Kein Gebaeude mit diesen Koordinaten gefunden" << endl;
            }
        } break;
        case 4: {
            bauplanAusgeben();
        } break;
        case 5: {
            cout << "Labels: " << endl << "S -> Solarkraftwerk" << endl << "W -> Windkraftwerk" << endl << "A -> Wasserkraftwerk (A wie Aqua)" << endl << endl;
        } break;
        case 6: {
            cout << "Programm beenden" << endl;
            running = false;
        } break;
        default: {
            cout << "Menuepunkt nicht vorhanden" << endl;
        } break;
        }
    }
}


int main() {
    CapycitySim* sim = new CapycitySim(9, 9);
    sim->run();


    return 0;
}