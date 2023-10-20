#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

#include <iostream>
#include <vector>
#include "department.h"
using namespace std;

class ServiceMode {
public:
	virtual ~ServiceMode(void) {}
	virtual void load(vector<Department>&) = 0;
	virtual void save(vector<Department>&) = 0;
};

#endif//SERVICE_MODE_H
