
#ifndef RESIDENT_H_FILE
#define RESIDENT_H_FILE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "constants.h"
using namespace std;


class resident
{
public:
	string residentName;
	string address;
	string contact;
	string IDNumber;
	
	resident();
	resident( string residentName,  string address,  string contact,  string IDNumber);
	int request_raiser( string location,  string startPoint,  string endPoint);
};

#endif
