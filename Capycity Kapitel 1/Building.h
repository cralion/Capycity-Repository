#pragma once
#include "Material.h"
#include <map>
#include <unordered_map>


class Building {
protected:
    int koordinateX;
    int koordinateY;
    int breite = 1;
    int laenge = 1;
    int grundpreis;
    int materialpreis = 0;
    char label = '0';
    int value;


public:
    Holz* holz = new Holz();
    Metall* metall = new Metall();
    Kunststoff* kunststoff = new Kunststoff();
    std::unordered_map<Material*, int> materialListe;


    //Konstruktor
    Building() {}

    //Kopierkonstruktor
    Building(const Building& building);

    //swap for copy and swap
    void swap(Building& other);

    //Zuweisungsoperator
    Building& operator=(Building building);

    //Standartdestruktor
    ~Building() {
        delete[] holz;
        delete[] metall;
        delete[] kunststoff;
    }

    //Getter
    int getKoordinateX() {
        return koordinateX;
    }
    int getKoordinateY() {
        return koordinateY;
    }
    int getBreite() {
        return breite;
    }
    int getLaenge() {
        return laenge;
    }
    int getGrundpreis() {
        return grundpreis;
    }
    int getMaterialpreis() {
        return materialpreis;
    }

    char getLabel() {
        return label;
    }
};

class Solarkraftwerk : public Building {
private:
    //Holz, Metall, Metall, Metall, Kunststoff
public:


    Solarkraftwerk(int koordinateX, int koordinateY) {
        this->koordinateX = koordinateX;
        this->koordinateY = koordinateY;
        breite = 5;
        laenge = 3;

        //Initialisiere Materialliste
        materialListe[holz] = int(1);
        materialListe[metall] = int(3);
        materialListe[kunststoff] = int(1);

        //Berechne Materialpreis
        materialpreis = (materialListe[holz] * holz->getPreis()) + (materialListe[metall] * metall->getPreis()) + (materialListe[kunststoff] * kunststoff->getPreis());

        grundpreis = 500;
        label = 'S';
    }
};

class Windkraftwerk : public Building {
private:
    //Holz, Metall, Metall, Kunststoff, Kunststoff, Kunststoff

public:
    static const int materialienSize = 10;
    Material* materialien[materialienSize] = { holz, metall, metall, kunststoff, kunststoff, kunststoff, nullptr, nullptr,
                                              nullptr, nullptr };

    Windkraftwerk(int koordinateX, int koordinateY) {
        this->koordinateX = koordinateX;
        this->koordinateY = koordinateY;
        breite = 2;
        laenge = 2;

        //Initialisiere Materialliste
        materialListe[holz] = int(1);
        materialListe[metall] = int(3);
        materialListe[kunststoff] = int(1);

        //Berechne Materialpreis
        materialpreis = (materialListe[holz] * holz->getPreis()) + (materialListe[metall] * metall->getPreis()) + (materialListe[kunststoff] * kunststoff->getPreis());
    }
};

class Wasserkraftwerk : public Building {
private:
    //Holz, Holz, Holz, Metall, Metall, Metall, Kunststoff, Kunststoff
    static const int materialienSize = 10;
    Material* materialien[materialienSize] = { holz, holz, holz, metall, metall, metall, kunststoff, kunststoff,
                                              nullptr, nullptr };

public:
    Wasserkraftwerk(int koordinateX, int koordinateY) {
        this->koordinateX = koordinateX;
        this->koordinateY = koordinateY;
        breite = 5;
        laenge = 5;

        //Initialisiere Materialliste
        materialListe[holz] = int(1);
        materialListe[metall] = int(3);
        materialListe[kunststoff] = int(1);

        //Berechne Materialpreis
        materialpreis = (materialListe[holz] * holz->getPreis()) + (materialListe[metall] * metall->getPreis()) + (materialListe[kunststoff] * kunststoff->getPreis());

        grundpreis = 2000;
        label = 'A';
    }
};

