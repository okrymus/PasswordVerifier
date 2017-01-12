// The program checks the input as a password meets the stated criteria. If it doesn't,the program displays a message telling the user the reason.
// Password Verifier program
// Programmer: Panupong Leenawarat
// Last mofified 1/26/2016

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

// Prototype
bool verified(char *);
void invalidPassword(bool vLength, bool vDigit, bool vUpper, bool vLower, bool vAlpha, bool vSpecificChars);

const int SIZE_OF_PASSWORD = 20;

int main()
{
	char password[SIZE_OF_PASSWORD];

	// The program's introduction and create an empty line
	cout
		<< endl
		<< "\t                PASSWORD VERIFIER PROGRAM" << endl 
		<< "\t                    By Lee. Panupong     " << endl << endl;
	
	char sign = 26;
	// The password's criteria  
	cout 
		<< "Enter a password that meets the following criteria:                          " << endl
		<< sign << "Minimum of 6 characters in length.                                   " << endl
		<< sign << "Contains at least one uppercase and at at least one lowercase letter." << endl
		<< sign << "Contains at least one digit.                                         " << endl
		<< sign << "Contain one of the following characters: ! @ # $ %.                  " << endl << endl;
	cout << sign;
	
	// Get input password is not validated
	cin.getline(password, SIZE_OF_PASSWORD);

	// Verify the password and while the input password is invalid, ask for a new password
	while (!verified(password))
	{
		// Create empty lines
		cout << endl << endl;
		// Ask for re-enter password
		cout << " Re-Enter Password: ";

		cin.getline(password, SIZE_OF_PASSWORD);
		
		// Create empty lines
		cout << endl << endl;
	}
	 // Display when the input password is a valid password
	cout << endl <<"\tThe password " << password << " is a valid password! \n\n\n";

	system("pause");
	return 0;
}

bool verified(char *password)
{
	int length = strlen(password);
	bool vLength = false,
		 vUpper = false,
		 vLower = false,
		 vDigit = false,
		 vAlpha = false,
		 vSpecificChars = false,
		 vSpecialChars = true;
		

	// Check the password is at least 6 characters long and if it is larger than 6, vLength = true
	if (length >= 6) 
		vLength = true;

	for (int count = 0; count < length; count++)
	{
		// Check the password contains at least one digit
		if (isdigit(password[count])) vDigit = true;
		// Check the password contains at least one uppercase and at at least one lowercase letter
		if (islower(password[count])) vLower = true;
		if (isupper(password[count])) vUpper = true;
		//  Check the password contains at least one letter
		if (isalpha(password[count])) vAlpha = true;
		// Check the password contains one of the following characters: !@ # $ %
		if (password[count] == '!') vSpecificChars = true;
		if (password[count] == '@') vSpecificChars = true;
		if (password[count] == '#') vSpecificChars = true;
		if (password[count] == '$') vSpecificChars = true;
		if (password[count] == '%') vSpecificChars = true;
	}

	// The program displays a message telling the user why the password does not meet the criteria.
	invalidPassword(vLength, vDigit, vUpper, vLower, vAlpha, vSpecificChars);
	
	// If any the variables is false, return false, or if all are true, return true
	return vLength && vUpper && vLower && vDigit && vAlpha && vSpecificChars;
}

void invalidPassword(bool vLength, bool vDigit, bool vUpper, bool vLower, bool vAlpha, bool vSpecificChars)
{
	// If any the variables is false, process it
	if (vLength == false || vDigit == false || vUpper == false || vLower == false || vAlpha == false || vSpecificChars == false)
	{
		// Display invalid password
		cout 
			<< endl << endl
			<< "\t\t        ======================== " << endl
		    << "\t\t        !!! Invalid Password !!! " << endl
			<< "\t\t        ======================== " << endl << endl;
		
		cout << "\a" << "\t     Your password DOES NOT contain the following: \n\n";
	}
	
	// Show the reason why it is invalid
	if (vLength == false) 
		cout << "\t\t* At least 6 characters long! \n";
	if (vAlpha == false) 
		cout << "\t\t* At least one letter. \n";
	if (vDigit == false) 
		cout << "\t\t* At least one numerical digit. \n";
	if (vLower == false) 
		cout << "\t\t* At least one lower case letter. \n";
	if (vUpper == false) 
		cout << "\t\t* At least one upper case letter. \n";
	if (vSpecificChars == false)
		cout << "\t\t* At least one \"! @ # $ %\" character. \n";
	
	return;
}