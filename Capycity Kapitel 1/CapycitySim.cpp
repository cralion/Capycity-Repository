#include "CapycitySim.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "Blueprint.h"

//Capycity Kapitel 4

void CapycitySim::run() {
    //Menue
    int menu;
    bool running = true;
    int bLength;
    int bWidth;
    cout << "Gebe Laenge fuer ersten Bauplan ein:" << endl;
    cin >> bLength;
    cout << "Gebe Breite fuer ersten Bauplan ein:" << endl;
    cin >> bWidth;
    Blueprint* blueprint = new Blueprint(bLength, bWidth);
    std::vector<Blueprint*> blueprintList;




    while (running) {

        cout << "1. Gebaeudeliste ausgeben" << endl;
        cout << "2. Gebaeude setzen" << endl;
        cout << "3. Bereich loeschen" << endl;
        cout << "4. Bauplan ausgeben" << endl;
        cout << "5. Aktuellen Bauplan speichern" << endl;
        cout << "6. Nach Kennzahl sortierte Liste aller Bauplaene ausgeben" << endl;
        cout << "7. Programm beenden" << endl;
        cin >> menu;


        switch (menu) {
            //1. Gebaeudeliste ausgeben
        case 1: {
            int slot = 0;
            for (int i = 0; i < blueprint->buildingsSize; i++) {
                cout << "Building Slot " << slot << ": " << endl;
                if (blueprint->buildings[i] != nullptr) {
                    cout << "   Gebaeudetyp: " << blueprint->buildings[i]->getLabel() << endl;
                    cout << "   Flaeche: " << blueprint->getBuildingArea(blueprint->buildings[i]) << endl;
                    cout << "   Kosten: " << blueprint->getBuildingArea(blueprint->buildings[i]) * (blueprint->buildings[i]->getBasePrice() + blueprint->buildings[i]->getMaterialPrice()) << endl;
                    cout << "   Materialien: " << endl;
                    cout << "       [" << blueprint->getBuildingArea(blueprint->buildings[i]) * blueprint->buildings[i]->getWood() << "] Holz" << endl;
                    cout << "       [" << blueprint->getBuildingArea(blueprint->buildings[i]) * blueprint->buildings[i]->getMetal() << "] Metall" << endl;
                    cout << "       [" << blueprint->getBuildingArea(blueprint->buildings[i]) * blueprint->buildings[i]->getPlastic() << "] Kunststoff" << endl;
                }
                else {
                    cout << " - - - " << endl;
                }
                cout << "---------------------------------" << endl;
                slot++;
            }
            cout << endl << "Gesamtpreis:   " << blueprint->getTotalPrice() << endl;
        } break;
            //2. Gebaede setzen
        case 2: {
            //Delete Area: X, Y, len, wid, build
            int coordX;
            int coordY;
            int length;
            int width;
            char type;
            cout << "X - Koordinate (obere linke Ecke des Gebaeudes) angeben:" << endl;
            cin >> coordX;
            cout << "Y - Koordinate (obere linke Ecke des Gebaeudes) angeben:" << endl;
            cin >> coordY;
            cout << "Laenge des Gebaeudes angeben" << endl;
            cin >> length;
            cout << "Breite des Gebaeudes angeben" << endl;
            cin >> width;
            cout << "Gebaeudetyp angeben (S -> Solar, W -> Wind, A -> Wasser)" << endl;
            cin >> type;
            blueprint->placeBuilding(coordX, coordX, length, width, type);

        } break;
            //3. Bereich loeschen
        case 3: {
            int coordX;
            int coordY;
            int length;
            int width;
            cout << "X - Koordinate (obere linke Ecke des Bereichs) angeben:" << endl;
            cin >> coordX;
            cout << "Y - Koordinate (obere linke Ecke des Bereichs) angeben:" << endl;
            cin >> coordY;
            cout << "Laenge des Bereichs angeben" << endl;
            cin >> length;
            cout << "Breite des Bereichs angeben" << endl;
            cin >> width;
            blueprint->deleteArea(coordX, coordY, length, width);
        } break;
            //4. Gebaeude loeschen
        //case 4: {
            //int coordX;
            //int coordY;
            //cout << "X - Koordinate als Teil des zu zerstoerenden Gebaeudes angeben angeben:" << endl;
            //cin >> coordX;
            //cout << "Y - Koordinate als Teil des zu zerstoerenden Gebaeudes angeben angeben:" << endl;
            //cin >> coordY;
            //Building* buildingToDelete = blueprint->getBuildingPointer(coordX, coordY);
            //blueprint->deleteBuilding(buildingToDelete);

        //} break;
            //4. Bauplan ausgeben
        case 4: {
            blueprint->outputBlueprint();
            cout << endl << "Legende:" << endl << "--------" << endl << "[S] Solarkraftwerk" << endl << "[W] Windkraftwerk" << endl << "[A] Wasserkraftwerk" << endl << endl;
        } break;
            //5. Aktuellen Bauplan speichern und neuen anlegen
        case 5: {
            bool blueprintIdentical = false;
            for (auto b : blueprintList) {
                if ((*blueprint)(b)) {
                    cout << "Identischer Bauplan bereits vorhanden" << endl;
                    blueprintIdentical = true;
                }
            }
            if (!blueprintIdentical) {
                blueprintList.push_back(blueprint);
                //Erfrage Laenge und Breite
                cout << "Laenge des neuen Bauplans angeben: " << endl;
                cin >> bLength;
                cout << "Breite des neuen Bauplans angeben: " << endl;
                cin >> bWidth;
                blueprint = new Blueprint(bLength, bWidth);
            }
        } break;
            //6. Sortierte Bauplanliste ausgeben
        case 6: {
            //Lambda fuer Sortierung
            auto sortByCoefficient = [](Blueprint* b1, Blueprint* b2) -> bool {
                return b1->getCoefficient() > b2->getCoefficient();
            };
            //Sortiere Bauplanliste nach Kennzahl
            sort(blueprintList.begin(), blueprintList.end(), sortByCoefficient);
            //Gebe Vektor aus
            for (auto b : blueprintList) {
                b->outputBlueprint();
            }
        } break;
            //7. Programm beenden
        case 7: {
            running = false;
        }break;
        default: {
            cout << "Falsche Eingabe! Gebe eine Zahl aus dem Menue ein" << endl << endl;
        } break;
        }
    }
}


int main()
{
    CapycitySim* sim = new CapycitySim();
    sim->run();

    return 0;

}
