
#include "mayor.h"

int mayor::query_repair_statistics()
{
	std::string repairOverTime;
	std::string repairOutstanding;
	std::string repairUtilization;
	std::fstream fin;
	fin.open(STATISTICSPATH, std::ios::in);
	fin>>repairOverTime;
	fin>>repairOutstanding;
	fin>>repairUtilization;
	std::cout<<"Repair work over time:"<<repairOverTime<<std::endl;
	std::cout<<"Repair work outstanding:"<<repairOutstanding<<std::endl;
	std::cout<<"Repair utilization:"<<repairUtilization<<std::endl;
	fin.close();
	return 0;
}
