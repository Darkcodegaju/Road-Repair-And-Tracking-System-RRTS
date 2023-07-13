#include "supervisor.h"

int supervisor::enter_information(int requestID, int newPriority, std::string newRawMaterials, std::string newMachinesRequired, std::string newPersonnelRequired)
{
	std::string str;

	std::fstream fin, fout;
	fin.open(DATAPATH, std::ios::in);
	fout.open(TEMPDATAPATH, std::ios::out);

	if(fout.is_open())
	{
		while(getline(fin, str))
		{
			std::istringstream in(str);
			char tempStr[128];
			std::string temp[12];
			for (int i = 0; i < 12; i++)
			{
				in.getline(tempStr, 128, ',');
				temp[i] = tempStr;		// temp[] contains the 12 pieces of information that was stored in the CSV file
			}

			if(requestID == stoi(temp[0]))
			{
				for (int i = 0; i <= 7; i++)
					fout<<temp[i]<<",";
				fout<<newPriority<<","<<newRawMaterials<<","<<newMachinesRequired<<","<<newPersonnelRequired;
			}
			else
			{
				for (int i = 0; i < 12; i++)
					fout<<temp[i]<<",";
			}
			fout<<std::endl;
		}
		// Rename temp.txt to data.txt now.
		rename(TEMPDATAPATH, DATAPATH);
		remove(TEMPDATAPATH);
		std::cout<<"Values updated successfully !!"<<std::endl;
	}
	else
	{	std::cout<<"Error opening file while updating information by supervisor."<<std::endl;
		return 1;
	}
	fin.close();
	fout.close();
	return 0;
}

int supervisor::repair_scheduler()
{
	int i=0, activeRequests=-1, j=0, k=0, swap;
	std::fstream fin, fout;
	fin.open(ACTIVEREQUESTSPATH, std::ios::in);
	fin>>activeRequests;						// Retrieves last request ID from file.
	fin.close();

	std::string str[activeRequests+1], swap_str;		// str stores each road repair request.
	int priorities[activeRequests+1];			// priorities stores the priority of each road repair request.

	fin.open(DATAPATH, std::ios::in);

	if(fin.is_open())
	{
		while(getline(fin, str[i]))
		{
			std::istringstream in(str[i]);
			char tempStr[128];
			for (int i = 0; i < 9; i++)
				in.getline(tempStr, 128, ',');
			priorities[i] = std::stoi(tempStr);
			if(priorities[i]==-1)
				priorities[i]=1000;
			i++;
		}
	}
	else
	{	std::cout<<"Error opening file while updating information by supervisor."<<std::endl;
		return 1;
	}

	// TODO: Use a divide and conquer approach sorting algorithm.
	// Bubble sort according to the road repair priority and alongside also sort the array str.
	for(j=0; j<(activeRequests-1); j++)
	{
		for(k=0; k<(activeRequests-j-1); k++)
		{
			if(priorities[k] > priorities[k+1])
			{
				swap			= priorities[k];
				priorities[k]   = priorities[k+1];
				priorities[k+1] = swap;

				swap_str = str[k];
				str[k] = str[k+1];
				str[k+1] = swap_str;
			}
		}
	}
	fin.close();

	fout.open(DATAPATH, std::ios::out);
	std::cout<<"\nData format: <Request ID> <Location> <Start Point> <End Point> <Name> <Address> <Contact> <ID Numbe> <Priority> <Required Raw Materials> <Required Machines> <Required Personnels>"<<std::endl<<std::endl;
	for(j=0; j<activeRequests; j++)
	{
		// Write sorted repair requests to file
		fout<<str[j]<<std::endl;

		// Now print the sorted repair requests to console. This is to generate the "report".
		std::istringstream in(str[j]);
		char tempStr[128];
		for (int i = 0; i < 12; i++)
		{
			in.getline(tempStr, 128, ',');
			std::cout<<tempStr<<" ";
		}
		std::cout<<std::endl;
	}
	fout.close();
	return 0;
}
int supervisor::enter_statistics()
{
	std::string repairOverTime;
	std::string repairOutstanding;
	std::string repairUtilization;
	std::fstream fout;
	fout.open(STATISTICSPATH, std::ios::out);
	scanf("%*c");

	std::cout<<"Enter repair work over time:";
	getline(std::cin, repairOverTime);
	fout<<repairOverTime<<std::endl;

	std::cout<<"Enter repair work outstanding:";
	getline(std::cin, repairOutstanding);
	fout<<repairOutstanding<<std::endl;

	std::cout<<"Enter repair utilization:";
	getline(std::cin, repairUtilization);
	fout<<repairUtilization<<std::endl;

	fout.close();
	std::cout<<"Values updated successfully by supervisor!!"<<std::endl;
	return 0;
}
