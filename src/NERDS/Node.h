#ifndef SRC_NERDS_NODE_H_
#define SRC_NERDS_NODE_H_

#include <vector>
#include <NERDS/Cartesian.h>

class Node {
public:
	Node(double, double, double = 1);
	~Node();

	void setParent(Node*);
	void removeParent();
	Node* getParent();

	bool addConnection(Node*);
	bool removeConnection(Node*);
	std::vector<Node*> getConnections();

	Cartesian getCoordinates();
	double computeCost(const Node*, const Node*);

private:
	double _x, _y;
	double _costMultiplier;

	std::vector<Node*> _connections;
	Node* _parent;
};

#endif /* SRC_NERDS_NODE_H_ */
