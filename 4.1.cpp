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
	string wordday[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
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
			if(!goodmonth)
			{
				
				if (of.month < 1 || of.month > 12)
				{
					cout << "\nInvalid entry for Month.. Try again with a new valid date " << endl;
				}
				else
				{
					goodmonth = 1;
				}
			}
			if(!goodday)
			{
				
				if (of.month == 1 || of.month == 3 || of.month == 5 || of.month == 7 || of.month == 8 || of.month == 10 || of.month == 12)
				{
					if (of.day < 1 || of.day >31)
					{
						cout << "\nInvalid entry for Day.. Try again with a new valid date " << endl;
						
					}
					else
					{
						goodday = 1;
					}
				}
				if (of.month == 4 || of.month == 6 || of.month == 9 || of.month == 11)
				{
					if (of.day < 1 || of.day >30)
					{
						cout << "\nInvalid entry for Day.. Try again " << endl;
					}
					else
					{
						goodday = 1;
					}
				}
				if (of.month == 2)
				{
					if (of.year % 400 == 0 || ((of.year % 4 == 0) && (of.year % 100 != 0)))
					{
						if (of.day < 1 || of.day >29)
						{
							cout << "\nInvalid entry for Day.. Try again " << endl;
						}
						else
						{
							goodday = 1;
						}
					}
					else
					{
						if (of.day < 1 || of.day >28)
						{
							cout << "Invalid entry for Day.. Try again " << endl;
						}
						else
						{
							goodday = 1;
						}
					}
				}
			}
			if (goodday == 1 && goodmonth == 1 && goodyear == 1) // Check if date is valid and good
			{
				gooddate = 1;
			}
			else
			{
				correctformat = 0;
				slashcount = 0;
				incorrectcount = incorrectcount + 1;
				cout << "\nInvalid date.. count : " << incorrectcount << endl;
			}
			if (incorrectcount >= 3)
			{
				cout << "\nToo many errors.. Exiting now " << endl;
				system("pause");
				exit(1);
			}
			
			of.dofw = of.dow(of.month, of.day, of.year);
			cout << endl << "Date is on a " << wordday[of.dofw] << endl;
			of.zodiac = of.zodiacsign(of.month, of.day);
			cout << "Zodiac sign is " << of.zodiac << endl;
		}
	
	system("pause");
	return 0;
}

int date::dow(int m, int d, int y)
{
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  //Array derived from number of days after a multiple of 7 each month starts, subtracting one from months after february
	if (m<3)                                             //Day is incremented by 1 each year
	{
		y--;                                                //y, t[m-1], and d give how many days to shift from starting point
	}
	return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;     //Starting point set by the constant integer
																   //y/4-y/100+y/400 adds leap days to equation
}   

string date::zodiacsign(int m, int d)
{
	string signs[] = { "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces" };

	if (m == 3)
	{
		if (d>0 && d <= 20)
		{
			return signs[11]; //Pisces
		}
		if (d >= 21)
		{
			return signs[0]; //Aries
		}
	}
	if (m == 4)
	{
		if (d>0 && d <= 19)
		{
			return signs[0]; // Aries
		}
		if (d >= 20)
		{
			return signs[1]; //Taurus
		}
	}
	if (m == 5)
	{
		if (d>0 && d <= 20)
		{
			return signs[1]; // Taurus
		}
		if (d >= 21)
		{
			return signs[2]; // Gemini

		}
	}
	if (m == 6)
	{
		if (d>0 && d <= 20)
		{
			return signs[2]; // Gemini
		}
		if (d >= 21)
		{
			return signs[3]; //Cancer
		}
	}
	if (m == 7)
	{
		if (d>0 && d <= 22)
		{
			return signs[3]; // Cancer
		}
		if (d >= 23)
		{
			return signs[4]; //Leo
		}
	}
	if (m == 8)
	{
		if (d>0 && d <= 22)
		{
			return signs[4]; //Leo
		}
		if (d >= 23)
		{
			return signs[5]; //Virgo
		}
	}
	if (m == 9)
	{
		if (d>0 && d <= 22)
		{
			return signs[5]; //Virgo
		}
		if (d >= 23)
		{
			return signs[6]; //Libra
		}
	}
	if (m == 10)
	{
		if (d>0 && d <= 22)
		{
			return signs[6]; //Libra
		}
		if (d >= 23)
		{
			return signs[7]; //Scorpio
		}
	}
	if (m == 11)
	{
		if (d>0 && d <= 21)
		{
			return signs[7]; //Scorpio
		}
		if (d >= 22)
		{
			return signs[8]; //Sag
		}
	}
	if (m == 12)
	{
		if (d>0 && d <= 21)
		{
			return signs[8]; //Sag
		}
		if (d >= 22)
		{
			return signs[9]; //Capricorn
		}
	}
	if (m == 1)
	{
		if (d>0 && d <= 19)
		{
			return signs[9]; //Capricorn
		}
		if (d >= 20)
		{
			return signs[10]; //Aquarius
		}
	}
	if (m == 2)
	{
		if (d>0 && d <= 18)
		{
			return signs[10]; //Aquarius
		}
		if (d >= 19)
		{
			return signs[11]; //Pisces
		}
	}
    return signs[11]; //Pisces
}
