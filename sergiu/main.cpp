#include "Set.h"
#include <string>
#include <iostream>
#include "Test.h"
using namespace std;
void showParkingLot(Set<string> s)
{
	Iterator<string> i{ s };
	int k = 0;
	while (i.valid())
	{
		if (i.getCurrent() != "")
			cout << "|" << i.getCurrent() << "| ";
		else 
			cout << "|        | ";
		k++;
		i.next();
		if (k % 13 == 0)
			cout << endl << endl;
	}
}
void showResidentLot(Set<string> s,string name)
{
	Iterator<string> i{ s };
	int k = 0;
	while (i.valid())
	{
		if (i.getCurrent() != "" && i.getCurrent() != name)
			cout << "|" << i.getCurrent() << "| ";
		else if (i.getCurrent() != "" && i.getCurrent() == name)
			cout << "|**" << i.getCurrent() << "**| ";
		else
			cout << "|        | ";
		k++;
		i.next();
		if (k % 13 == 0)
			cout << endl << endl;
	}
}

int main()
{
	Test t;
	t.testAll();
	   
	cout << "Welcome to the parking lot" << endl << "This is how it looks now at the beginning" << endl<<endl;
	for (int i = 0; i < 13; i++)
		cout << "|        | ";
	cout << endl<<endl;
	for (int i = 0; i < 13; i++)
		cout << "|        | ";
	cout << endl<<endl;
	int c = 0;
	Set<string> s;
	while (true)
	{
		cout << "Press -1 to exit the program" << endl;
		cout << "Press 0 to view the parking lot " << endl;
		cout << "Press 1 to add a new resident" << endl;
		cout << "Press 2 to remove a given resident" << endl;
		cout << "Press 3 to search for a resident " << endl;
		cin >> c;
		if (c == -1)
			break;
		else if (c == 0)
			showParkingLot(s);
		else if (c == 1)
		{
			cin.ignore();
			string name;
			cout << "Enter the resident's name:" << endl;
			getline(cin, name);
			s.add(name);
		}
		else if (c == 2)
		{
			string name;
			cin.ignore();
			cout << "Enter the resident's name:" << endl;
			getline(cin, name);
			s.remove(name);
		}
		else if (c == 3)
		{
			string name;
			cin.ignore();
			cout << "Enter the resident's name:" << endl;
			getline(cin, name);
			bool r = s.search(name);
			if (r == false)
				cout << "The resident doesn't have a car in this parking lot" << endl;
			else
			{
				cout << "The resident has a car in this parking lot" << endl;
				showResidentLot(s,name);
			}
		}

	}
}