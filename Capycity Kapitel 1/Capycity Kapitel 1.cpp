// Capycity Kapitel 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Capycity Kapitel 1

#include <iostream>
using namespace std;

void bauplanAusgeben(int length, int width, int** bauplan) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            cout << bauplan[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void gebaeudeSetzen(int areaLength, int areaWidth, int** bauplan) {
    bool buildingAreaBlocked = false;
    int buildingLength;
    int buildingWidth;
    int koordinateX;
    int koordinateY;

    
    cout << "Koordinate X der oberen linken Ecke des Gebaeudes angeben" << endl;
    cin >> koordinateX;
    cout << "Koordinate Y der oberen linken Ecke des Gebaeudes angeben" << endl;
    cin >> koordinateY;
    cout << "Laenge des Gebaeudes angeben" << endl;
    cin >> buildingLength;
    cout << "Breite des Gebaeudes angeben" << endl;
    cin >> buildingWidth;

    if (((buildingLength + koordinateY) > areaLength) or (buildingWidth + koordinateX) > areaWidth) {
        buildingAreaBlocked = true;
    }
    else {
        for (int i = koordinateY; i < (buildingWidth + koordinateY); i++) {
            for (int j = koordinateX; j < (buildingLength + koordinateX); j++) {
                if (bauplan[i][j] != 0) {
                    buildingAreaBlocked = true;
                }
            }
        }
    }

    if (!buildingAreaBlocked) {
        for (int i = koordinateY; i < (buildingWidth + koordinateY); i++) {
            for (int j = koordinateX; j < (buildingLength + koordinateX); j++) {
                bauplan[i][j] = 1;
            }
        }
    }
    else {
        cout << "Baubereich blockiert" << endl;
    }
}

void bereichLoeschen(int areaLength, int areaWidth, int** bauplan) {
    int length;
    int width;
    int koordinateX;
    int koordinateY;

    cout << "Koordinate X der oberen linken Ecke des Bereichs angeben" << endl;
    cin >> koordinateX;
    cout << "Koordinate Y der oberen linken Ecke des Bereichs angeben" << endl;
    cin >> koordinateY;
    cout << "Laenge des Bereichs angeben" << endl;
    cin >> length;
    cout << "Breite des Bereichs angeben" << endl;
    cin >> width;

    if (((length + koordinateY) <= areaLength) or (width + koordinateX) <= areaWidth) {
        for (int i = koordinateY; i < (width + koordinateY); i++) {
            for (int j = koordinateX; j < (length + koordinateX); j++) {
                bauplan[i][j] = 0;
            }
        }
    }
    else {
        cout << "Zu loeschender Bereich ueberschreitet die Bauplangrenze" << endl;
    }


}



int main() {

    int length;
    int width;
    int menuSelection;
    bool running = true;

    cout << "laenge eingeben" << endl;
    cin >> length;
    cout << "breite eigeben" << endl;
    cin >> width;

    //Bauplan anlegen
    int** bauplan = new int* [length];
    for (int i = 0; i < length; i++) {
        bauplan[i] = new int[width];
    }

    //Bauplan initialisieren
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            bauplan[i][j] = 0;
        }
    }



    while (running) {
        cout << "Waehle, was du tun moechtest" << endl;
        cout << "1. Gebaeude setzen" << endl;
        cout << "2. Bereich loeschen" << endl;
        cout << "3. Ausgeben des aktuellen Bauplans" << endl;
        cout << "4. Beenden des Programms" << endl;

        cin >> menuSelection;

        switch (menuSelection) {
        case 1: {
            cout << "Gebaeude setzen" << endl;
            gebaeudeSetzen(length, width, bauplan);
        }break;
        case 2: {
            cout << "Bereich loeschen" << endl;
            bereichLoeschen(length, width, bauplan);
        }break;
        case 3: {
            cout << "Ausgeben des aktuellen Bauplans" << endl;
            bauplanAusgeben(length, width, bauplan);
        }break;
        case 4: {
            cout << "Beenden des Programms" << endl;
            running = false;
        }break;
        default: {
            cout << "Falsche eingabe";
        }
        }
    }

    return 0;
}
