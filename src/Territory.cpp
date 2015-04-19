#include "Territory.h"

Territory::Territory(int num, string name, int borderNum, string borders_array[]) {
	this->num = num;
	this->name = name;
	owner = 5;
	troops = 0;
    troopsChanged = false;

	for (int i=0; i<borderNum; i++) {
        borders.push_back(borders_array[i]);
	}
}

void Territory::setTroops(int t){
    this->troops = t;
    troopsChanged = true;
}

int Territory::getTroops() {
    return this->troops;
}

int Territory::getNum() {
    return this->num;
}

string Territory::getName() {
    return this->name;
}

vector<string> Territory::getBorders() {
    return this->borders;
}

int Territory::getOwner(){
    return this->owner;
}

void Territory::setOwner(int o) {
    this->owner = o;
}

Territory::~Territory() {
}
