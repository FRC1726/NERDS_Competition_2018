#ifndef DeleteNetworkTables_H
#define DeleteNetworkTables_H

#include "../CommandBase.h"

class DeleteNetworkTables : public CommandBase {
public:
	DeleteNetworkTables();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DeleteNetworkTables_H
