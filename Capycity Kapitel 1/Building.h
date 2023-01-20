#pragma once
#include "Material.h"
#include <map>
#include <unordered_map>

class Building
{
protected:
    int coordinateX;
    int coordinateY;
    int width = 1;
    int length = 1;
    int area = 0;
    int power = 0; //Pro Flaecheneinheit
    int basePrice = 0;
    int materialPrice = 0;
    char label = '0';

    //Materialien
    Wood* wood = new Wood();
    Metal* metal = new Metal();
    Plastic* plastic = new Plastic();
    //Map fuer Materialliste
    std::unordered_map<Material*, int> materialList;
    //Map da Kapseln in eine externe Klasse uebersichtlichkeit erschwert. Die Materialliste gehoert zum Gebaeude.


public:
    //Konstruktor
    Building(int coordX, int coordY, int length, int width) {
        this->coordinateX = coordX;
        this->coordinateY = coordY;
        this->length = length;
        this->width;
        this->area = (length * width);
    }

    //Kopierkonstruktor
    Building(Building& build);

    //swap fuer copy and swap
    void swap(Building& build);

    //Zuweisungsoperator
    Building& operator=(Building build);

    //Destruktor
    ~Building() {
        delete[] wood;
        delete[] metal;
        delete[] plastic;
    }

    //Getter and Setter
    int getCoordinateX();
    int getCoordinateY();

    int getWidth();
    int getLength();

    int getArea();
    void setArea(int area);

    int getPower();

    int getBasePrice();
    int getMaterialPrice();
    int getTotalPrice();


    char getLabel();

    int getWood();
    int getMetal();
    int getPlastic();

};

class SolarPowerPlant : public Building {
public:

    //Konstruktor
    SolarPowerPlant(int coordX, int coordY, int length, int width) : Building(coordX, coordY, length, width) {

        basePrice = 500;
        power = 1000; //Pro Flaecheneinheit
        label = 'S';

        //Initialisiere Materialliste
        materialList[wood] = int(1);
        materialList[metal] = int(3);
        materialList[plastic] = int(2);

    }
};

class WindTurbine : public Building {
public:
    WindTurbine(int coordX, int coordY, int length, int width) : Building(coordX, coordY, length, width) {

        basePrice = 1000;
        power = 2500; //Pro Flaecheneinheit
        label = 'W';

        //Initialisiere Materialliste
        materialList[wood] = int(1);
        materialList[metal] = int(2);
        materialList[plastic] = int(3);

    }
};

class HydroelectricPowerPlant : public Building {
public:
    HydroelectricPowerPlant(int coordX, int coordY, int length, int width) : Building(coordX, coordY, length, width) {

        basePrice = 2000;
        power = 5000; //Pro Flaecheneinheit
        label = 'A';

        //Initialisiere Materialliste
        materialList[wood] = int(3);
        materialList[metal] = int(3);
        materialList[plastic] = int(2);

    }
};

