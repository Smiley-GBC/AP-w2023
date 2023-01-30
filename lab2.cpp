// Platform
//		Games
//			Achievements

//	MailService
//		PostOffice
//			Package

/*
#include <iostream>
#include <string>

struct Package
{
	std::string deliveryAddress;
	std::string message;
};

class PostOffice
{
public:
	void SetPackages(Package* packages, int packageCount)
	{
		this->packages = packages;
		this->packageCount = packageCount;
	}

	// We must keep track of the size of our dynamic array (packages) otherwise its impossibe to figure out!
	// For example, we need a size to determine how many times we loop when outputting each element.
	//void PrintPackages()
	//{
	//	for (int i = 0; i < packageCount; i++)
	//	{
	//		printf("%s\n", packages[i].message.c_str());
	//	}
	//}

	void SetAddress(const std::string& address)
	{
		buildingAddress = address;
	}

	std::string GetAddress() const
	{
		return buildingAddress;
	}

private:
	std::string buildingAddress;
	Package* packages;
	int packageCount;
};

class MailService
{
public:
	void SetOffices(PostOffice* postOffices, int officeCount)
	{
		offices = postOffices;
		count = officeCount;
	}

	void SetName(const std::string& name)
	{
		businessName = name;
	}

	std::string GetName() const
	{
		return businessName;
	}

private:
	std::string businessName;
	PostOffice* offices;
	int count;
};

int main()
{
	int serviceCount;
	int officeCount;
	int packageCount;
	std::cout << "Welcome to mail simulator 2023" << std::endl;
	std::cout << "Please enter the amount of mail services you wish to create." << std::endl;
	std::cin >> serviceCount;
	std::cout << "Please enter the amount of post offices you wish to create." << std::endl;
	std::cin >> officeCount;
	std::cout << "Please enter the amount of packages you wish to create." << std::endl;
	std::cin >> packageCount;

	Package* packages = new Package[packageCount];
	PostOffice* offices = new PostOffice[officeCount];
	offices->SetPackages(packages, packageCount);
	MailService* services = new MailService[serviceCount];
	services->SetOffices(offices, officeCount);
	
	return 0;
}
//*/