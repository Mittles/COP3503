#include "Territory.h"

Territory::Territory(int num, string name, int borderNum, string borders_array[]) {
	this->num = num;
	this->name = name;
    owner = 0;
	for (int i=0; i<borderNum; i++) {
        borders.push_back(borders_array[i]);
	}
}

Territory::Territory() {
}

Territory::~Territory() {
}
