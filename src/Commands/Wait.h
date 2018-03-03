#ifndef Wait_H
#define Wait_H

#include "../CommandBase.h"
namespace nerd{


class Wait : public CommandBase {
public:
	Wait(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

}

#endif  // Wait_H
