//2.0

#include <iostream>
#include <string>
using namespace std;

class date
{
public:
	int year = 0;
	int month = 0;
	int day = 0;
	int dofw = 0;
	string zodiac;
	int dow(int m, int d, int y);
	string zodiacsign(int m, int d);
private:
};

int main()
{
	date of;
	string date;
	cout << "Input a valid date in MM/DD/YYYY format: ";
	cin >> date;
	
			of.month = stoi(date.substr(date.find_first_of('(') + 1, date.find('/')));
			of.day = stoi(date.substr(date.find('/') + 1, date.find('/')));
			of.year = stoi(date.substr(date.find_last_of('/') + 1, date.find(')')));
	
	system("pause");
	return 0;
}

