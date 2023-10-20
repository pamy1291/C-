#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"
using namespace std;

class ServiceModeImpl : public ServiceMode{
public:
	void load(vector<Department>&);
	void save(vector<Department>&);
};
#endif//SERVICE_MODE_IMPL_H
