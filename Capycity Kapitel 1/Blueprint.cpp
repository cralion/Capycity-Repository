#include "Blueprint.h"

//Methoden

//Funktor
bool Blueprint::operator() (Blueprint* other) {
	//Anzahl der gleichen Felder
	int similarities = 0;
	//Pruefe, ob Laengen uebereinstimmen
	if (this->blueprintLength == other->blueprintLength) {
		//Pruefe Breiten uebereinstimmen
		if (this->blueprintWidth == other->blueprintWidth) {
			//Pruefe, ob Matritzen inhaltsgleich sind
			for (int i = 0; i < this->blueprintLength; i++) {
				for (int j = 0; j < this->blueprintWidth; j++) {
					//Pruefe ob beide Felder == nullptr -> Gleichheit eines Feldes
					if ((blueprint[i][j] == nullptr) and (other->blueprint[i][j] == nullptr)) {
						similarities++;
					}
					else {
						//Wenn einer der beiden Poiter trotzdem Nullpointer ist fuehre keinen Vergleich durch -> keine Gleichheit eines Feldes
						if (!((blueprint[i][j] == nullptr) or (other->blueprint[i][j] == nullptr))) {
							//Wenn keine Nullpointer vorhanden, vergleiche die Label
							if (blueprint[i][j]->getLabel() == other->blueprint[i][j]->getLabel()) {
								//Wenn Label gleich -> Gleichheit eines Feldes
								similarities++;
							}
						}

					}
				}
			}
			//Wenn Anzahl der gleichen Felder mit Gesamtflaeche uebereinstimmt sind die Bauplaene identisch
			if ((blueprintLength * blueprintWidth) == similarities)
				return true;
			else
				return false;

		}
		else
			return false;
	}
	else
		return false;
}

//Gebaeude platzieren
void Blueprint::placeBuilding(int coordX, int coordY, int length, int width, char buildingType) {
	//Pruefung, ob Baubereich blockiert oder Grenzen des Baubereichs ueberschritten
	bool buildingAreaBlocked = false;
	Building* building = nullptr;

	if (((length + coordY) > blueprintLength) or (width + coordX) > blueprintWidth) {
		buildingAreaBlocked = true;
	}
	else {
		for (int i = coordY; i < (length + coordY); i++) {
			for (int j = coordX; j < (width + coordX); j++) {
				if (blueprint[i][j] != nullptr) {
					buildingAreaBlocked = true;
				}
			}
		}
	}

	//Setze Gebaeude, wenn Baubereich nicht blockiert
	if (!buildingAreaBlocked) {
		//Erstelle Gebaude(zeiger) abhaengig von Gebaudetyp
		switch (buildingType) {
		case 'S': {
			building = new SolarPowerPlant(coordX, coordY, length, width);
		} break;
		case 'W': {
			building = new WindTurbine(coordX, coordY, length, width);
		} break;
		case 'A': {
			building = new HydroelectricPowerPlant(coordX, coordY, length, width);
		} break;
		default: {
			cout << "Gebaeude konnte nicht erstellt werden" << endl;
		} break;
		}

		//Fuege erstelltes Gebaeude dem Array buildings hinzu
		bool freeSlotFound = false;
		for (int i = 0; i < buildingsSize; i++) {
			if (buildings[i] == nullptr) {
				buildings[i] = building; //Gebaeude an freien Platz einfuegen
				cout << "Pointerinhalt des gespeicherten Gebaeudes:" << buildings[i] << endl;
				freeSlotFound = true;
				i = buildingsSize; //Abbruch der Schleife
			}

			if (!freeSlotFound)
				cout << "kein Freier Slot" << endl;
		}

		//Setze Gebaudezeige im Bauplan
		if (freeSlotFound) {
			for (int i = coordY; i < (length + coordY); i++) {
				for (int j = coordX; j < (width + coordX); j++) {
					blueprint[i][j] = building;
				}
			}
		}

	}
	else {
		cout << "Baubereich blockiert" << endl;
	}

}

//Bauplan ausgeben
void Blueprint::outputBlueprint() {
	for (int i = 0; i < blueprintLength; i++) {
		for (int j = 0; j < blueprintWidth; j++) {
			if (blueprint[i][j] == nullptr) {
				cout << '0' << " ";
			}
			else {
				cout << blueprint[i][j]->getLabel() << " ";
			}

		}
		cout << endl;
	}
	cout << endl;
	cout << "Kennzahl: " << getCoefficient() << endl;
	cout << "Gesamtkosten: " << getTotalPrice() << endl << endl;
	cout << "Fuer Einzelpreise der Gebaeude -> 1. Gebaeudeliste ausdrucken" << endl << endl;

}

//Gesamtes Gebaude mit Koordinate als indentifikation loeschen
void Blueprint::deleteBuilding(Building* buildingToDelete) {
	cout << "Adresse des zu loeschenden Gebaedes:" << buildingToDelete << endl;
	//Suche Building in Array
	bool buildingFound = false;
	for (int i = 0; i < buildingsSize; i++) {
		if (buildings[i] == buildingToDelete) {
			buildingFound = true;
			//Loesche Building-Zeiger aus der Blueprint-Matrix bzw. setze auf nullptr
			for (int i = 0; i < blueprintLength; i++) {
				for (int j = 0; j < blueprintWidth; j++) {
					if (blueprint[i][j] == buildingToDelete)
						blueprint[i][j] = nullptr;
				}
			}
			//delete[] buildingToDelete;
			i = buildingsSize; //Beende Schleife
		}
	}
}


//Pruefe ob Gebaude in Matrix vorhanden
bool Blueprint::buildingInMatrix(Building* building) {
	bool buildingInMatrix = false;
	for (int i = 0; i < blueprintLength; i++) {
		for (int j = 0; j < blueprintWidth; j++) {
			if (blueprint[i][j] == building)
				buildingInMatrix = true;
		}
	}
	return buildingInMatrix;
}

//Methode fuer Debugging:
//Erhalte Building-Zeiger von Koordinaten in der Matrix
Building* Blueprint::getBuildingPointer(int coordX, int coordY) {
	return blueprint[coordX][coordY];
}

void Blueprint::deleteArea(int coordX, int coordY, int length, int width) {

	if (!(((length + coordY) > blueprintLength) or ((width + coordX) > blueprintWidth))) {
		for (int i = coordY; i < (coordY + length); i++) {
			for (int j = coordX; j < (width + coordX); j++) {
				blueprint[i][j] = nullptr;
			}
		}
		//Pruefung ob Gesamte Flaeche geloescht wurde => Gebaeude aus Gebaeudeliste loeschen
		for (int i = 0; i < buildingsSize; i++) {
			if (!buildingInMatrix(buildings[i])) {
				buildings[i] = nullptr;
			}
		}

		//Flaeche fuer verbleibende Gebauede aktualisieren
		for (int i = 0; i < buildingsSize; i++) {
			if (buildings[i] != nullptr) {
				if (buildingInMatrix(buildings[i])) {
					buildings[i]->setArea(getBuildingArea(buildings[i]));
				}
			}
		}
	}
	else {
		cout << "definierter Bereich ueberschreitet die Grenzen des Bauplans" << endl << endl;
	}



}

int Blueprint::getBuildingArea(Building* building) {
	int area = 0;
	for (int i = 0; i < blueprintLength; i++) {
		for (int j = 0; j < blueprintWidth; j++) {
			if (blueprint[i][j] == building)
				area++;
		}
	}
	return area;
}

int Blueprint::getTotalPrice() {
	int totalPrice = 0;
	for (int i = 0; i < buildingsSize; i++) {
		if (buildings[i] != nullptr) {
			totalPrice += (buildings[i]->getBasePrice() + (getBuildingArea(buildings[i]) * buildings[i]->getMaterialPrice()));
		}
	}
	return totalPrice;
}

float Blueprint::getCoefficient() {
	//Gesamtleistung berechnen
	float totalPower = 0;
	for (int i = 0; i < blueprintLength; i++) {
		for (int j = 0; j < blueprintWidth; j++) {
			if (blueprint[i][j] != nullptr) {
				totalPower += blueprint[i][j]->getPower();
			}
		}
	}
	//Kennzahl berechnen
	if ((getTotalPrice() * blueprintLength * blueprintWidth) != 0) {
		int area = blueprintLength * blueprintWidth;
		float coefficient = (totalPower / (getTotalPrice() * area));
		return coefficient;
	}
	else
		return 0;
}