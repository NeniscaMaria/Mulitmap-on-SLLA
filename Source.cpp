//ADT MultiMap – using a SLLA with (key, value) pairs. A key can appear in multiple pairs.Pairs do not have to be ordered.

#include <iostream>
#include "extendedTest.h"
#include "shortTest.h"
#include "multiMap.h"
#include "assert.h"
using namespace std;

int main() {
	std::cout << "Short tests for multiMap running..." << std::endl;
	//testAll();
	std::cout << "Short tests for multiMap finsihed! Extended tests for multiMap running..." << std::endl;
	testAllExtended();
	std::cout << "Extended tests for multiMap finished!" << std::endl;
	MultiMap m;
	assert(m.getKeyRange() == -1);
	m.add(1, 100);
	m.add(2, 200);
	m.add(3, 300);
	m.add(4, 500);
	m.add(5, 600);
	m.add(6, 800);
	std::vector<TValue> values{ 800,600,500,300,200,100 };
	assert(m.valueBag() == values);
	system("pause");
	return 0;
}