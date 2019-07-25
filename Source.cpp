//Calculates and displays the gross pay for each employee and the total gross pay for a division
//This program utilizes enumerated types (as Bonuses) and overloading of input streams.
//created by Kwesi Owubah on 07/24/2019

#include <iostream>

using namespace std;

//function prototype(s)
double getGrosspay(double, double, int);

enum daysOfweek { Sun, Mon, Tue, Wed, Thu, Fri, Sat, reset };

//Overload Input stream daysOfweek& x
istream& operator>> (istream& in, daysOfweek& x) {
	int val;
	if (in >> val) {
		switch (val) {
		case Sun:
		case Mon:
		case Tue:
		case Wed:
		case Thu:
		case Fri:
		case Sat:
			x = daysOfweek(val);
			break;
		default:
			throw out_of_range("Invalid value for type daysOfweek");
		}
	}
	return in;
}

int main()
{
	//declaring variables
	double hoursWorked = 0.0;
	daysOfweek extraDay;
	int eDayVal = 0;
	char bonusDay = ' ';
	char response = ' ';
	double payRate = 0.0;
	double grossPay = 0.0;
	string name = "";
	double totalGrossPay = 0.0;

	//Ask if there is an employee
		cout << " Is there an Employee? (Y for yes, N for No): " << endl;
		cin >> response;
	do
	{
		extraDay = reset;
		//enter input variables 
		cout << " Name: " << endl;
		cin >> name;
		cout << " Enter hours " << name << " has worked: " << endl;
		cin >> hoursWorked;
		//determine hours worked
		if (hoursWorked > 40)
			hoursWorked = hoursWorked + (0.15 * hoursWorked);
		cout << " Enter pay rate: " << endl;
		cin >> payRate;

		cout << "Did " << name << " work an extra day this week? (Y for yes) " << endl;
		cin >> bonusDay;
		if (bonusDay == 'Y' || bonusDay == 'y') {
			cout << " Which day did " << name << " work extra for this week? [0(Sun), 1(Mon), 2(Tue), 3(Wed), 4(Thu), 5(Fri), 6(Sat)]" << endl;
			try {
				cin >> extraDay;
				//Assign bonus value (eDayVal) depending on user input
				switch (extraDay) {
					case Sun:
						eDayVal = 3;
						break;
					case Mon:
						eDayVal = 1;
						break;
					case Tue:
						eDayVal = 1;
						break;
					case Wed:
						eDayVal = 1;
						break;
					case Thu:
						eDayVal = 1;
						break;
					case Fri:
						eDayVal = 2;
						break;
					case Sat:
						eDayVal = 3;
						break;
				default:
					throw out_of_range("Invalid value for type daysOfweek");
					break;
				}//end switch
			}
			catch (out_of_range e) {
				//Error stream
				cerr << e.what() << endl;
			}
			
		}//end bonus 

		cout << "Heeeeeeey" << eDayVal << endl;

		//call function to calculate gross pay
		grossPay = getGrosspay(hoursWorked, payRate, eDayVal);
		
		//Increment by employee
		totalGrossPay += grossPay;

		//display gross pay and total gross pay
		cout << "Gross pay: " << grossPay << endl;
		
		//Ask if there is another employee
		cout << " Another Employee? (Y for yes, N for No): " << endl;
		cin >> response;
	} while (response == 'Y' || response =='y');

	//Display total gross pay
	cout << "Total gross pay: " << totalGrossPay << endl;

	system("pause");
	return 0;
}

//*****function definitions*****
double getGrosspay(double workedHours, double ratePay, int dayExtra){
	double grossPay = 0.0;
	grossPay = (workedHours + dayExtra) * ratePay;
	return grossPay;
}