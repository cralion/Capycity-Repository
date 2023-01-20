#pragma once
#include "Material.h"


class Building {
protected:
    int koordinateX;
    int koordinateY;
    int breite = 1;
    int laenge = 1;
    int grundpreis;
    int materialpreis = 0;
    char label = '0';

public:
    Holz* holz = new Holz();
    Metall* metall = new Metall();
    Kunststoff* kunststoff = new Kunststoff();

    //Konstruktor
    Building() {

    }
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

    static const int materialienSize = 10;
    Material* materialien[materialienSize] = { holz, metall, metall, kunststoff, nullptr, nullptr, nullptr, nullptr,
                                              nullptr, nullptr };

    Solarkraftwerk(int koordinateX, int koordinateY) {
        this->koordinateX = koordinateX;
        this->koordinateY = koordinateY;
        breite = 5;
        laenge = 3;
        //Berechne Materialpreis
        for (int i = 0; i < materialienSize; i++) {
            if (materialien[i] != nullptr) {
                materialpreis += materialien[i]->getPreis();
            }
        }
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
        //Berechne Materialpreis
        for (int i = 0; i < materialienSize; i++) {
            if (materialien[i] != nullptr) {
                materialpreis += materialien[i]->getPreis();
            }
        }
        grundpreis = 1000;
        label = 'W';
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
        //Berechne Materialpreis
        for (int i = 0; i < materialienSize; i++) {
            if (materialien[i] != nullptr) {
                materialpreis += materialien[i]->getPreis();
            }
        }
        grundpreis = 2000;
        label = 'A';
    }
};

