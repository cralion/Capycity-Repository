#include "Building.h"

//Kopierkonstruktor
Building::Building(Building& build) {
    wood = new Wood();
    metal = new Metal();
    plastic = new Plastic();
}

//swap fuer copy and swap
void Building::swap(Building& other) {
    using std::swap;
    swap(coordinateX, other.coordinateX);
    swap(coordinateY, other.coordinateY);
    swap(width, other.width);
    swap(length, other.length);
    swap(basePrice, other.basePrice);
    swap(materialPrice, other.materialPrice);
    swap(label, other.label);
}

//Zuweisungsoperator
Building& Building::operator=(Building build) {
    swap(build);
    return *this;
}

//Getter
int Building::getCoordinateX() {
    return coordinateX;
}
int Building::getCoordinateY() {
    return coordinateY;
}

int Building::getWidth() {
    return width;
}
int Building::getLength() {
    return length;
}

int Building::getArea() {
    return area;
}
void Building::setArea(int area) {
    this->area = area;
}

int Building::getPower() {
    return power;
}

int Building::getBasePrice() {
    return basePrice;
}
int Building::getMaterialPrice() {
    //Berechne Materialpreis
    return (materialList[wood] * wood->getPrice()) +
        (materialList[metal] * metal->getPrice()) +
        (materialList[plastic] * plastic->getPrice());
}
int Building::getTotalPrice() {
    return getBasePrice() + (getMaterialPrice() * area);
}

char Building::getLabel() {
    return label;
}

int Building::getWood() {
    return materialList[wood];
}
int Building::getMetal() {
    return materialList[metal];
}
int Building::getPlastic() {
    return materialList[plastic];
}