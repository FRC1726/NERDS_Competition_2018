#include <NERDS/NodeMap.h>

#include <algorithm>
#include <cmath>
#include <set>

struct CompareNodes{
	Node* operator()(Node* lhs, Node* rhs){
		return lhs->getCost() < rhs->getCost() ? lhs : rhs;
	}
};

NodeMap::NodeMap() {
	//Create map layout here

}

NodeMap::~NodeMap() {
	auto nodesCopy = _nodes;

		for(auto node : nodesCopy){
			delete node;
		}
}

std::vector<Polar> NodeMap::generatePath(Cartesian source, Cartesian target){
	Node* end = findPath(findClosestNode(source), findClosestNode(target));

	std::vector<Polar> path;
	Polar currentPosition = end->getCoordinates().toPolar();
	while(end){
		Node* nextNode = end->getParent();
		end->removeParent();

		if(nextNode == NULL){
			break;
		}

		Polar nextPosition(nextNode->getCoordinates().toPolar());

		path.push_back(currentPosition - nextPosition);

		currentPosition = nextPosition;
		end = nextNode;
	}

	path.push_back(currentPosition - source.toPolar());

	std::reverse(path.begin(), path.end());

	return path;
}

Node* NodeMap::findClosestNode(Cartesian position){
	Node* closestNode = _nodes[0];
	double closestDistance;

	Cartesian nodePosition = closestNode->getCoordinates();
	double x = pow(nodePosition.getX() - position.getX(), 2);
	double y = pow(nodePosition.getY() - position.getY(), 2);

	closestDistance = fabs(sqrt(x + y));

	for(auto node : _nodes){
		nodePosition = node->getCoordinates();
		x = pow(nodePosition.getX() - position.getX(), 2);
		y = pow(nodePosition.getY() - position.getY(), 2);

		double distance = fabs(sqrt(x + y));
		if(distance < closestDistance){
			closestNode = node;
			closestDistance = distance;
		}
	}

	return closestNode;
}

Node* NodeMap::findPath(Node* source, Node* target){
	std::set<Node*, CompareNodes> openList;
	std::vector<Node*> closedList;

	source->setCost(0);

	openList.insert(source);

	Node* currentNode;

	while(!openList.empty()){
		currentNode = *(openList.begin());

		if(currentNode == target){
			return currentNode;
		}

		openList.erase(openList.begin());
		closedList.push_back(currentNode);

		for(auto connection : currentNode->getConnections()){
			if(std::find(closedList.begin(), closedList.end(), connection) != closedList.end()){
				continue;
			}

			double cost = connection->computeCost(currentNode, target);

			if(openList.find(connection) != openList.end()){

				if(cost < connection->getCost()){
					connection->setCost(cost);
					connection->setParent(currentNode);

					openList.erase(connection);
					openList.insert(connection);
				}
			}else{
				connection->setCost(cost);
				connection->setParent(currentNode);

				openList.insert(connection);
			}
		}
	}

	return NULL;
}
