#include "multiMap.h"
#include"multiMapIterator.h"
#include <stdexcept>
#include <vector>
#include "SLLAIterator.h"
#include <iostream>
using namespace std;

MultiMap::MultiMap() {
	this->elements = new SLLA;
	//theta(1)
}

MultiMap::~MultiMap() {
	delete this->elements;
	//theta(1)
}

void MultiMap::add(TKey c, TValue v) {
	auto pair = make_pair(c, v);
	this->elements->add(pair);
	//O(n)
}

bool MultiMap::remove(TKey c, TValue v) {
	auto pair = make_pair(c, v);
	std::vector<TValue> values = this->search(c);
	if (values.size() == 0)
		return false;
	for (int i = 0; i < values.size(); i++) {
		if (values[i] == v) {
			this->elements->remove(pair);
			return true;
		}
	}
	return false;
	//theta(n)
}

vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> elems;
	return this->elements->searchValue(c);
	//theta(n)
}

int MultiMap::size() const {
	return this->elements->getSize();
	//theta(1)
}

bool MultiMap::isEmpty() const {
	return this->elements->isEmpty();
	//theta(1)
}

int MultiMap::getKeyRange() const
{
	if (this->elements->getSize() == 0)
		return -1;
	int minimumKey = INT_MAX, maximumKey = INT_MIN;
	for (int i = 0; i < this->elements->getSize(); i++) {
		TKey element = this->elements->getElement(i).first;
		if (element < minimumKey)
			minimumKey = element;
		if (element > maximumKey)
			maximumKey = element;
	}
	return maximumKey - minimumKey;
	//theta(n)
}

std::vector<TValue> MultiMap::valueBag() const
{
	std::vector<TValue> values;
	auto current = this->elements->head;
	while (current != -1) {
		values.push_back(this->elements->elements[current].second);
		current = this->elements->next[current];
	}
	return values;
	//theta(n)
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
	//theta(1)
}