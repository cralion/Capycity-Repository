#include "Material.h"
#include <iostream>

//Kopierkostruktor
Material::Material(const Material& _material) {
    //Leer, da keine dynamischen Objekte
}

//swap for copy and swap
void Material::swap(Material& other) {
    using std::swap;
    swap(preis, other.preis);
}

//Zuweisungsoperator
Material& Material::operator=(Material _material) {
    swap(_material);
    return *this;
}