#ifndef SRC_NERDS_PIDOUT_H_
#define SRC_NERDS_PIDOUT_H_

#include <PIDOutput.h>
#include <functional>

template<class T>
class PidOut : public PIDOutput{
public:
	PidOut() : outputFunction([this] (double x) -> void {value = x;}), value(0) {}
	PidOut(std::function<T(double)> func) : outputFunction(func), value(0) {}
	void PIDWrite (double output) {outputFunction(output);}
	double getPid () {return value;}
private:
	std::function<T(double)> outputFunction;
	double value;
};

#endif /* SRC_NERDS_PIDOUT_H_ */
