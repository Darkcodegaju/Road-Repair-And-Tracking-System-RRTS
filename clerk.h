

#ifndef CLERK_H_HEADER
#define CLERK_H_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "resident.h"
#include "constants.h"

class clerk
{
	resident* requester;
public:
	clerk();
	clerk(std::string requesterName, std::string requesterAddress, std::string requesterContact, std::string requesterIDNumber);
	int request_raiser(std::string location, std::string startPoint, std::string endPoint);
};

#endif
