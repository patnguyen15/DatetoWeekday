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
	int incorrectcount = 0;
	bool goodyear = 0;
	bool goodmonth = 0;
	bool goodday = 0;
	bool gooddate = 0;
	bool correctformat = 0;
	date = "";
	int slashcount = 0;
	int invalidcount = 0;
    int doubledashcount = 0;
	int doubledasherror = 1;
  
		while (!gooddate)
		{
			while (!correctformat)
			{
				cout << "Please enter a date in the following format: MM/DD/YYYY \n\n";
				cin >> date;
                
                invalidcount = 0;
                slashcount = 0;
                doubledashcount = 0;
                doubledasherror = 0;
                
                for (int i = 0; i < date.size(); i++)
				{
            
                    
                   
                        
                    if (isdigit(date[i])){
                       
                        doubledashcount = 0;

                    }
                    
                    if ( (!(isdigit(date[i])) && !(date[i]='/')) || (!(isdigit(date[0]))) ||  (!(isdigit(date.back())))){
            
                        invalidcount = invalidcount + 1;
                        
                    }
					if (date[i] == '/')
					{
						slashcount = slashcount + 1;
                        doubledashcount = doubledashcount +1;
                        if(doubledashcount ==2){
                            doubledasherror = 1;
                        }
                        
					}
     
                    
					
				}
				if (slashcount == 2 && invalidcount == 0 && doubledasherror == 0)
				{
					correctformat = 1;
				}
				else
				{
					incorrectcount = incorrectcount + 1;
					cout << "\nIncorrect format.. count : " << incorrectcount << endl;
				}
				if (incorrectcount >= 3)
				{
					cout << "\nToo many errors.. Exiting now " << endl;
					system("pause");
					exit(1);
				}
                
			}
			of.month = stoi(date.substr(date.find_first_of('(') + 1, date.find('/')));
			of.day = stoi(date.substr(date.find('/') + 1, date.find('/')));
			of.year = stoi(date.substr(date.find_last_of('/') + 1, date.find(')')));
			
			if(!goodyear)
			{
			
				if (of.year < 1)
				{
					cout << "Invalid entry for Year..Try again with a new valid date " << endl;
				}
				else
				{
					goodyear = 1;
				}
		}
		}
	
	system("pause");
	return 0;
}

