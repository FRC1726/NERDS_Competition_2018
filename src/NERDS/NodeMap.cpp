#include <NERDS/NodeMap.h>

#include <algorithm>
#include <cmath>
#include <utility>
#include <set>

NodeMap::NodeMap() {
	//Default Position (Mid)
	_currentNode = new Node(1, 1);

	_nodes.push_back(_currentNode);

	//Create map layout here
}

NodeMap::~NodeMap() {
	auto nodesCopy = _nodes;

		for(auto node : nodesCopy){
			delete node;
		}
}

std::vector<Polar> NodeMap::generatePath(Cartesian target) {
	Cartesian source = _currentNode->getCoordinates();
	return generatePath(source, target);
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

	std::reverse(path.begin(), path.end());

	return path;
}

void NodeMap::setPosition(Cartesian position){
	_currentNode = findClosestNode(position);
}

Cartesian NodeMap::getPosition(){
	return _currentNode->getCoordinates();
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
	std::set<std::pair<double, Node*> > openList;
	std::vector<Node*> closedList;

	openList.insert(std::make_pair<double, Node*&>(0, source));

	Node* currentNode;

	while(!openList.empty()){
		currentNode = openList.begin()->second;

		if(currentNode == target){
			return currentNode;
		}

		openList.erase(openList.begin());
		closedList.push_back(currentNode);

		for(auto connection : currentNode->getConnections()){
			auto closedIterator = std::find(closedList.begin(), closedList.end(), connection);
			if(closedIterator != closedList.end()){
				continue;
			}

			connection->setParent(currentNode);
			openList.insert(std::make_pair<double, Node*&>(connection->computeCost(currentNode, target), connection));
		}
	}

	return NULL;
}
