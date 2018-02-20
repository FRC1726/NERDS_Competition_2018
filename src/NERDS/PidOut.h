/*
 * PidOut.h
 *
 *  Created on: Jan 24, 2018
 *      Author: ShawnSargent
 */

#ifndef SRC_NERDS_PIDOUT_H_
#define SRC_NERDS_PIDOUT_H_

#include <PIDOutput.h>

class PidOut : public PIDOutput{
public:
	PidOut();
	void PIDWrite (double output);
	double getPid ();
private:
	double value;
};

#endif /* SRC_NERDS_PIDOUT_H_ */
