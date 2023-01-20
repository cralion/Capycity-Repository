#pragma once
#include "Material.h"
#include "Building.h"
#include <vector>



class CapycitySim {

public:
    int bauplanLaenge;
    int bauplanBreite;
    char** bauplan;
    static const int buildingsSize = 10;
    Building* buildings[buildingsSize];

    void bauplanAusgeben();
    void gebaeudeSetzen(int koordinateX, int koordinateY, Building* building);
    void gebaeudeLoeschen(Building* building);
    void run();



    CapycitySim(int bauplanLaenge, int bauplanBreite) {
        this->bauplanLaenge = bauplanLaenge;
        this->bauplanBreite = bauplanBreite;

        //buildings Array initialisieren
        for (int i = 0; i < buildingsSize; i++) {
            buildings[i] = nullptr;
        }

        //Mehrdimensionales Array anlegen / Bauplan erstellen
        bauplan = new char* [bauplanLaenge];
        for (int i = 0; i < bauplanLaenge; i++)
            bauplan[i] = new char[bauplanBreite];

        //Bauplan initialisieren
        for (int i = 0; i < bauplanLaenge; i++) {
            for (int j = 0; j < bauplanBreite; j++) {
                bauplan[i][j] = '0';
            }
        }
    }

    ~CapycitySim() {
        for (int i = 0; i < bauplanLaenge; i++) {
            delete[] bauplan[i];
        }
        delete[] bauplan;
    }
};
