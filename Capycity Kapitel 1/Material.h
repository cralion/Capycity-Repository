#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Material
{
protected:

	int price = 0;

public:

	//Konstruktor
	Material() {
		price = 0;
	}

	//Kopierkonstruktor
	Material(const Material& mat);

	//swap fuer copy and swap
	void swap(Material& other);

	//Zuweisungsoperator
	Material& operator=(Material mat);

	//Destruktor
	~Material() {}
};

class Wood : public Material {
public:

	//Konstruktor
	Wood() {
		price = 100;
	}

	//Getter
	int getPrice() {
		return price;
	}

	//Destruktor
	~Wood() {}
};

class Metal : public Material {
public:

	//Konstruktor
	Metal() {
		price = 200;
	}

	//Getter
	int getPrice() {
		return price;
	}

	//Destruktor
	~Metal() {}
};

class Plastic : public Material {
public:

	//Konstruktor
	Plastic() {
		price = 300;
	}

	//Getter
	int getPrice() {
		return price;
	}

	//Destruktor
	~Plastic() {}
};

