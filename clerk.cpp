#include "clerk.h"

clerk::clerk()
{	requester = NULL;
}
clerk::clerk(std::string requesterName, std::string requesterAddress, std::string requesterContact, std::string requesterIDNumber)
{
	requester = new resident(requesterName, requesterAddress, requesterContact, requesterIDNumber);
}
int clerk::request_raiser(std::string location, std::string startPoint, std::string endPoint)
{
	std::ofstream fout;std::ifstream fin;
	int requestID = -1;
	int activeRequests = -1;
	int priority = -1;					// Default priority of repair request. Denotes that the priority hasn't been set yet.
	std::string rawMaterials;
	std::string machinesRequired;
	std::string personnelRequired;

	fin.open(REQUESTIDPATH, std::ios::in);
	fin>>requestID;						// Retrieves last request ID from file.
	fin.close();
	fout.open(REQUESTIDPATH, std::ios::out);
	fout<<requestID+1;					// Updates request ID by incrementing the old value.
	fout.close();

	fin.open(ACTIVEREQUESTSPATH, std::ios::in);
	fin>>activeRequests;						// Retrieves last request ID from file.
	fin.close();
	fout.open(ACTIVEREQUESTSPATH, std::ios::out);
	fout<<activeRequests+1;					// Updates request ID by incrementing the old value.
	fout.close();

	fout.open(DATAPATH, std::ios_base::app);
	if (fout.is_open())
	{	fout<<requestID+1<<","<<location<<","<<startPoint<<","<<endPoint<<","<<requester->residentName<<","<<requester->address<<","<<requester->contact<<","<<requester->IDNumber<<","<<priority<<","<<rawMaterials<<","<<machinesRequired<<","<<personnelRequired<<std::endl;
		fout.close();
		std::cout<<"Request ID:"<<requestID+1<<std::endl;
		return 0;
	}
	else
	{	std::cout<<"Error opening file while raising request by resident.";
		return 1;
	}
}
