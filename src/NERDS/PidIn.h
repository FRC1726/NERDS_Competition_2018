#ifndef SRC_NERDS_PIDIN_H_
#define SRC_NERDS_PIDIN_H_

#include <functional>
#include <PIDSource.h>

class PidIn : public PIDOutput{
public:
	PidIn(std::function<double()> func) : inputFunction(func) {}
	double PIDGet() {return inputFunction()};
private:
	std::function<double()> inputFunction;
};

#endif /* SRC_NERDS_PIDIN_H_ */
