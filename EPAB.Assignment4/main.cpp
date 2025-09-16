#include<iostream>
#include<conio.h>

using namespace std;


// Structure

struct Employee {
    int ID;
    string FirstName;
    string LastName;
    float HoursWorked;
    float HourlyRate;
};

//Function prototype

Employee * pGetEmployeeInfo(int &size);
void PayReport(Employee* pEmployees,  int size);

int main()
{
    int size = 0;
    Employee *pEmployees = pGetEmployeeInfo(size);

    PayReport(pEmployees, size);
    
    // Clean up dynamically allocated memory
    delete[] pEmployees;
	(void)_getch();
	return 0;
   
}

Employee *pGetEmployeeInfo(int &size)
{

    cout << "Enter the number of employees: ";
    cin >> size;

    Employee *pEmployees = new Employee[size];

    for (int i = 0; i < size; i++)
    {
        cout << "\n\nEnter the ID for Employee " << (i + 1) << ": "; 
        cin >> pEmployees[i].ID;

        cout<< "\nEnter the First Name for Employee " << (i + 1) << ": ";
        cin >> pEmployees[i].FirstName;

        cout << "\nEnter the Last Name for Employee " << (i + 1) << ": ";
        cin >> pEmployees[i].LastName;

        cout << "\nEnter the Hours Worked for Employee " << (i + 1) << ": ";
        cin >> pEmployees[i].HoursWorked;

        cout << "\nEnter the Hourly Rate for Employee " << (i + 1) << ": ";
        cin >> pEmployees[i].HourlyRate;
    }

    return pEmployees;
}

void PayReport(Employee* pEmployees, int size)
{
    cout << "\nPay Report\n";
    cout << "----------\n";

    float TotalPay = 0.0f;

    for (int i = 0; i < size; i++)
    {
        float weeklyPay = (pEmployees[i].HoursWorked) * (pEmployees[i].HourlyRate); //Weekly Pay

        cout << pEmployees[i].ID << ". ";
        cout << pEmployees[i].FirstName << " ";
        cout << pEmployees[i].LastName << ": ";
        cout<<"$" << weeklyPay << "\n\n";


        TotalPay += weeklyPay;
    }

    cout << "Total pay: $" << TotalPay;

   
}