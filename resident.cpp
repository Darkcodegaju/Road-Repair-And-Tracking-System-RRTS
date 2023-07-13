#include "resident.h"
using namespace std;

resident::resident()
{
	residentName = address = contact = IDNumber = "";
}
resident::resident( string residentName,  string address,  string contact,  string IDNumber)
{
	this->residentName = residentName;
	this->address = address;
	this->contact = contact;
	this->IDNumber = IDNumber;
	
}
int resident::request_raiser( string location,  string startPoint,  string endPoint)
{
	ofstream fout; ifstream fin;
	int requestID = -1;
	int activeRequests = -1;
	int priority = -1;					// Default priority of repair request. Denotes that the priority hasn't been set yet.
	string machinesRequired;
	string personnelRequired;
	string rawMaterials;

	fin.open(REQUESTIDPATH,  ios::in);
	fin>>requestID;						// Retrieves last request ID from file.
	fin.close();
	fout.open(REQUESTIDPATH,  ios::out);
	fout<<requestID+1;					// Updates request ID by incrementing the old value.
	fout.close();

	fin.open(ACTIVEREQUESTSPATH,  ios::in);
	fin>>activeRequests;						// Retrieves last request ID from file.
	fin.close();
	fout.open(ACTIVEREQUESTSPATH,  ios::out);
	fout<<activeRequests+1;					// Updates request ID by incrementing the old value.
	fout.close();
        
	fout.open(DATAPATH,  ios_base::app);
	if (fout.is_open())
	{	fout<<requestID+1<<","<<location<<","<<startPoint<<","<<endPoint<<","<<residentName<<","<<address<<","<<contact<<","<<IDNumber<<","<<priority<<","<<rawMaterials<<","<<machinesRequired<<","<<personnelRequired<< endl;
		fout.close();
		 cout<<"Request ID:"<<requestID+1<< endl;
		return 0;
	}
	else
	{	 cout<<"Error opening file while raising request by resident.";
		return 1;
	}
}
