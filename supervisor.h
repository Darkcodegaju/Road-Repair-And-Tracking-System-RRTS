
#ifndef SUPERVISOR_H_HEADER
#define SUPERVISOR_H_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "constants.h"

class supervisor
{
public:
	int enter_information(int requestID, int newPriority, std::string newRawMaterials, std::string newMachinesRequired, std::string newPersonnelRequired);
	int repair_scheduler();
	int enter_statistics();
};

#endif