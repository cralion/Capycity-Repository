#include "Building.h"
#include <iostream>


//Kopierkonstruktor
Building::Building(const Building& _building) {
    koordinateX = _building.koordinateX;
    koordinateY = _building.koordinateY;
    breite = _building.breite;
    laenge = _building.laenge;
    grundpreis = _building.grundpreis;
    label = _building.label;
}

//swap for copy and swap
void Building::swap(Building& other) {
    using std::swap;
    swap(koordinateX, other.koordinateX);
    swap(koordinateY, other.koordinateY);
    swap(breite, other.breite);
    swap(laenge, other.laenge);
    swap(grundpreis, other.grundpreis);
    swap(label, other.label);
}

//Zuweisungsoperator
Building& Building::operator=(Building _building) {
    swap(_building);
    return *this;
}