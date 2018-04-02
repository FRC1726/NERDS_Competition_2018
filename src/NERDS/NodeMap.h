#ifndef SRC_NERDS_NODEMAP_H_
#define SRC_NERDS_NODEMAP_H_

#include <vector>
#include <NERDS/Polar.h>
#include <NERDS/Cartesian.h>
#include <NERDS/Node.h>

class NodeMap {
public:
	NodeMap();
	~NodeMap();

	std::vector<Polar> generatePath(Cartesian, Cartesian);
private:
	std::vector<Node*> _nodes;

	Node* findClosestNode(Cartesian);
	Node* findPath(Node*, Node*);
};

#endif /* SRC_NERDS_NODEMAP_H_ */
