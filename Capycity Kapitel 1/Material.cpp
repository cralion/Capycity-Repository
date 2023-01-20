#include "Material.h"

//Kopierkonstruktor
Material::Material(const Material& mat)
{
	//leer, da keine dynamischen Objekte
}

//swap fuer copy and swap
void Material::swap(Material& other) {
	using std::swap;
	swap(price, other.price);
}

//Zuweisungsoperator
Material& Material::operator=(Material mat) {
	swap(mat);
	return *this;
}

