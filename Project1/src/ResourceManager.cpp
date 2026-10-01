#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <iomanip>


bool ResourceManager::loadFromFile(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	
	if (fin.fail())
	{
		cout << "File error" << endl;
		return false; // error of file-reading
	}

	string id, name, type, status;
	while (getline(fin, id, '|'))
	{
		getline(fin, name, '|'); // reads until '|' excluding this character
		getline(fin, type, '|');
		getline(fin, status); // read until enter/space
		
		Resource resource(id, name, type, status);
		resources.push_back(resource);
	}
	
	// close resources
	fin.close();
	// successful reading
	return true;
}

// Linear Search - finding a resource by ID
int ResourceManager::findResource(string resourceID) const
{
	for (int i = 0; i < (int) resources.size(); i++)
	{
		if (resources[i].getResourceID() == resourceID)
		{
			return i;
		}
	}
	return -1;
}


int ResourceManager::getCount() const
{
	return resources.size();
}


Resource& ResourceManager::getResource(int index)
{
	return resources[index];
}


bool ResourceManager::setAvailability(string resourceID, string status)
{
	int index = findResource(resourceID);
	
	if (index == -1)
	{
		return false;   // no such resource
	}
	
	resources[index].setAvailabilityStatus(status);
	return true;
}


void ResourceManager::viewResources() const
{
	cout << "===== Resources Info: =====" << endl; 

	for (int i = 0; i < (int) resources.size(); i++)
	{
		cout << "Resource ID: " << resources[i].getResourceID() << endl;
		cout << "Resource Name: " << resources[i].getResourceName() << endl;
		cout << "Resource Type: " << resources[i].getResourceType() << endl;
		cout << "Resource Availability Status: " << resources[i].getAvailabilityStatus() << endl;
	}
	cout << endl;
}


void ResourceManager::displayAvailability() const
{
	int availableCount = 0;
	
	cout << left << setw(8) << "ID" << setw(24) << "Name" << "Status" << endl;
	
	for (int i = 0; i < (int)resources.size(); i++)
	{
		cout << left << setw(8) << resources[i].getResourceID()
		     << setw(24) << resources[i].getResourceName()
		     << resources[i].getAvailabilityStatus() << endl;
		
		if (resources[i].getAvailabilityStatus() == "Available")
		{
			availableCount++;
		}
	}
	
	cout << endl << availableCount << " of " << resources.size() << " resources available." << endl;
}