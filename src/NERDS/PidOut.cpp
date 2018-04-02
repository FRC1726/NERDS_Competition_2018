/*
 * PidOut.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: ShawnSargent
 */

#include "PidOut.h"

PidOut::PidOut() {
	value = 0;
}

void PidOut::PIDWrite (double output){
	value = output;
};

double PidOut::getPid (){
	return value;
};
