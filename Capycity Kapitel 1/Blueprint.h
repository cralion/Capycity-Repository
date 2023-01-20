#pragma once
#ifndef BUILDING_H
#include <vector>
#include "Building.h"
using std::cout;
using std::endl;
using std::cin;
#endif BUILDING_H



class Blueprint
{
public:
	int blueprintLength = 0;
	int blueprintWidth = 0;
	//Building ** blueprintMatrix;
	Building*** blueprint;

	//Array fuer Buildings
	static const int buildingsSize = 10;
	Building* buildings[buildingsSize];

	//Methoden
	//Funktor fuer den Vergleich zweier Bauplaene
	bool operator() (Blueprint* other);
	void placeBuilding(int coordX, int coordY, int length, int width, char buildingType);
	void outputBlueprint();
	void deleteBuilding(Building* buildingToDelete);
	bool buildingInMatrix(Building* build);
	Building* getBuildingPointer(int coordX, int coordY);
	void deleteArea(int coordX, int coordY, int length, int width);
	int getBuildingArea(Building* building);
	int getTotalPrice();
	float getCoefficient();




	//Konstruktor
	Blueprint(int length, int width) : blueprintLength(length), blueprintWidth(width) {
		//Initialisiere buildings[]
		for (int i = 0; i < buildingsSize; i++) {
			buildings[i] = nullptr;
		}

		//Erstelle Matrix des Bauplans
		blueprint = new Building * *[blueprintLength];
		for (int i = 0; i < blueprintLength; i++) { //Evtl. wieder auf blueprintWidth korrigieren
			blueprint[i] = new Building * [blueprintWidth];
		}

		//Matrix des Bauplans initialisieren
		for (int i = 0; i < blueprintLength; i++) {
			for (int j = 0; j < blueprintWidth; j++) {
				blueprint[i][j] = nullptr;
			}
		}
	}

	//Destruktor
	~Blueprint() {
		for (int i = 0; i < blueprintLength; i++) {
			delete[] blueprint[i];
		}
		delete[] blueprint;
	}

};

