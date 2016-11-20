#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Please enter number of simulations:\n" ;
	double num;				// int's size is too small for MC, using double
	cin >> num;
	cout << num;
	if (num>1000000000) {
		string yesnot;
		cout << "Number of simulation is too big, are you sure to continue? (Y/N):";
		
		cin >> yesnot ;
		YESNO:

		if (yesnot == "Y") {
			cout << "Please expect long calculation time...\n";
			return 0;
		}
		else if (yesnot == "N") {
			cout << "Execution ended.\n";
		}
		else {
			cout << "Please enter Y/N \n";
			cin >> yesnot;
			goto YESNO;
		}
		
		cout << yesnot;


	}

	return 0;
}
