
#include "administrator.h"

int administrator::enterAvailableResources(std::string manpower, std::string machines)
{
	std::fstream fout;
	fout.open(RESOURCESPATH, std::ios::out);
	fout<<manpower<<std::endl;
	fout<<machines<<std::endl;
	fout.close();
	std::cout<<"Available resources updated successfully !!"<<std::endl;
	supervisor s;
	std::cout<<"Now scheduling road repairs..."<<std::endl;
	return s.repair_scheduler();
}
int administrator::showAvailableResources()
{
	std::string manpower, machines;
	std::fstream fin;
	fin.open(RESOURCESPATH, std::ios::in);
	fin>>manpower;
	fin>>machines;
	std::cout<<"Available manpower:"<<manpower<<std::endl;
	std::cout<<"Available machines:"<<machines<<std::endl;
	fin.close();
	return 0;
}
