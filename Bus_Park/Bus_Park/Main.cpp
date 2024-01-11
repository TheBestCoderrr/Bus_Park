#include "Bus_Park.h"

int main() {
	
	Bus_Park bus_park;
	size_t user_answer = 1;
	cout << "0 - Exit\n1 - add bus\n2 - find bus\n3 - print bus\n4 - save" << endl;
	while (user_answer != 0) {
		cout << "Enter num: ";
		cin >> user_answer;
		switch (user_answer) {
		case 0:
			break;
		case 1:
		{
			string numberBus;
			cout << "Enter number bus: ";
			cin >> numberBus;
			string fname;
			cout << "Enter first name: ";
			cin >> fname;
			string lname;
			cout << "Enter last name: ";
			cin >> lname;
			string routeNumber;
			cout << "Enter route number: ";
			cin >> routeNumber;
			size_t countPlaces;
			cout << "Enter cout places: ";
			cin >> countPlaces;
			bus_park.AddBus(numberBus, fname, lname, routeNumber, countPlaces);
		}
		break;
		case 2:
		{
			string numberBus;
			cout << "Enter number bus: ";
			cin >> numberBus;
			if(bus_park.findBus(numberBus)) cout << "Bus founded" << endl;
			else cout << "Bus not founded" << endl;
		}
		break;
		case 3:
		{
			string numberBus;
			cout << "Enter number bus: ";
			cin >> numberBus;
			bus_park.printBus(numberBus);
		}
		break;
		case 4:
			bus_park.save("Bus_Park.txt");
			break;
		default:
			cout << "Invalid variant" << endl;
			break;
		}
	}
}