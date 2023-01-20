#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;


class Material {
    //Attribute
protected:
    int preis;
public:
    //Standardkonstruktor
    Material() {};

    //Kopierkostruktor
    Material(const Material& _material);

    //swap for copy and swap
    void swap(Material& other);

    //Zuweisungsoperator
    Material& operator=(Material _material);

    //Standarddestruktor
    ~Material() {};

    //getter
    int getPreis() {
        return preis;
    }
};

class Holz : public Material {
public:
    Holz() {
        preis = 100;
    }
};

class Metall : public Material {
public:
    Metall() {
        preis = 200;
    }
};

class Kunststoff : public Material {
public:
    Kunststoff() {
        preis = 300;
    }
};
