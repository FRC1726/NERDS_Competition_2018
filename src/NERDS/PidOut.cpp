/*
 * PidOut.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: ShawnSargent
 */

#include "PidOut.h"

PidOut::PidOut() {
}

void PidOut::PIDWrite (double output){
	value = output;
};

double PidOut::getPid (){
	return value;
};
