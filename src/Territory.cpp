#include "Territory.h"

Territory::Territory(int num, string name, int borderNum, string borders_array[]) {
	this->num = num;
	this->name = name;
	owner = 0;
	troops = 0;

	for (int i=0; i<borderNum; i++) {
        borders.push_back(borders_array[i]);
	}
}

int Territory::getNum() {
    return this->num;
}

int Territory::getOwner() {
    return this->owner;
}

string Territory::getName() {
    return this->name;
}

vector<string> Territory::getBorders() {
    return this->borders;
}

Territory::~Territory() {
}

