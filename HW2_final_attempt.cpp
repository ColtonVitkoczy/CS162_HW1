#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


// Colton Vitkoczy
// The purpose of this program is to have the user enter in a keyword then go through variuos steps to output
// an alternate version of the keyword that can be used as a password. The user can repeat this multiple times until 
// they find a password that they like. 


const int KEYWORD = 50;

void ask_for_rules();                                        // Asks the user to see instructions.
void read_keyword(char keyword[]);                           // Gets keyword from user.
bool check_for_uppercase(bool & upper_used, char keyword[]); // Flag variable if upper case is used
void replace_capitals(char keyword[], bool & upper_used);    // Replaces capitals with _
void duplicate_vowel(char keyword[]);                        // Duplicates vowels
void print_password_uppercase(bool & upper_used, char keyword[]); // Outputs new password with ASCII and $ at end
void print_password_notupper(bool & upper_used, char keyword[]);  // Outputs new password with ASCII and $ in front 
void ask_repeat(char & repeat);                                   // Asks to repeat

int main()
{
	// Declaring variables
	char keyword[KEYWORD];    // Keyword that's used to generate a password.
	bool upper_used = false;  // Flag variable to check if upper case was used.
	char repeat = 'N';

        // Calling functions
	ask_for_rules();          // Asks user to see instructions
	do
	{
	read_keyword(keyword);                                 // Declaring the keyword variable
	upper_used = check_for_uppercase(upper_used, keyword); // Checks for uppercase letters then updates flage variable
	replace_capitals(keyword, upper_used);                 // Checks for capitals and replazes with '_'
	duplicate_vowel(keyword);                              // Checks for vowels and duplicates vowels
	print_password_uppercase(upper_used, keyword);         // Prints password if upper used and last ASCII
	print_password_notupper(upper_used, keyword);          // Prints password if upper not used and last ASCII
	ask_repeat(repeat);
	} while(toupper(repeat) == 'Y');
 
	return 0;

}

// Ask user to see instructoins
void ask_for_rules()
{
	char rules = 'N';
	cout << "Would you like to see the rules for this game?" << endl;
	cin >> rules;
	cin.ignore(100, '\n');

	if (toupper(rules) == 'Y')
	{
		cout << "The password is generated as follows" << endl; 
		cout << "First the user will enter the keyword they want to use" << endl;
		cout << "Next, the program will take the keyword and look for capital letters" << endl;
		cout << "and change it to an '_' followed by a lowercase of that letter." << endl;
		cout << "After this, the keyword is checked for vowels; if any are found," << endl;
		cout << "a vowel is added next to it. Following this, the program will take the last" << endl;
		cout << "char in the keyword and turn it into its ASCII value. Then, if no capital" << endl;
		cout << "letter is detected, a $ sign will be added to the end of the password that" << endl;
		cout << "has benn generated. Finally, the array of characters produced from the" << endl;
		cout << "steps above will be placed in reverse order." << endl;
		cout << endl;
	}
}

// Prompts the user to enter in their keyword
void read_keyword(char keyword[])
{
	cout << "Please enter in a keyword youd like to use to create a password : ";
	cin.get(keyword, KEYWORD, '\n'); // I used get line for whitespace
	cin.ignore(100, '\n'); // Not sure if i have to still use this here?
}

// Checks for uppercase letters in the keyword then updates the flag variable upper_used... Which I can't get it to do...
bool check_for_uppercase(bool & upper_used, char keyword[])
{
	int len = strlen(keyword);    // length of array
	for (int i = 0; i < len; ++i)
	{
		if (isupper(keyword[i]))
			upper_used = true;
	}
	return upper_used;
}

// Checks for capital letters then shifts the array over from that value and replaces with an '_'
void replace_capitals(char keyword[], bool & upper_used)
{

	int len = strlen(keyword); // variable to get length of keyword
	int replace_position = 0;  // variable position to get replaced
	char replace_with = '_';   // char to replace with
	for (int i = 0; i <= len; ++i)
	{
		if (isupper(keyword[i]))
		{
			keyword[i] = tolower(keyword[i]);
			replace_position = i;
			for (int j = len; j > replace_position; --j)
			{
				keyword[j] = keyword[j-1];
			}
			keyword[replace_position] = replace_with;
			len = len + 1;
		}
	}
} 
// Chacks for vowels and duplicates them
void duplicate_vowel(char keyword[])
{

	int len = strlen(keyword); // length of array
	int vowel_position = 0;    // vowel position to shift array
	int i = 0;

	for (int i = 0; i <= len; ++i)
	{
		if (keyword[i] == 'a' ||keyword[i] == 'e' ||keyword[i] == 'i' ||keyword[i] == 'o' ||keyword[i] == 'u') // And sometimes Y?
		{
			vowel_position = i;
			for(int j = len; j > vowel_position; --j)
			{
				keyword[j] = keyword[j-1];
			}
			i = i + 1; // this starts the for loop up top one position after the vowel.
			len = len + 1; // this increases length of array for new memory stored.
		}
	}
}


// prints out the new password with a $ sign at the end if password is used.
// And, outputs passwords last char ASCII value
void print_password_uppercase(bool & upper_used, char keyword[])
{
	int len = strlen(keyword); // length of array
	char replace_with = '$';   // char to replace with
	int i = 0;                 // counter
	int ascii_value = keyword[len-1]; // prints out the last chars ASCII value as int

	if (upper_used)
	{
		cout << "Your new password is : ";
		for (int i = 0; i < len; ++i)
		{
			cout << keyword[i];
			if (i == len - 2)
			{
				cout << ascii_value << replace_with << endl;
				++i;
			}
		}
	}

}

// My own step: adding a dollar sign to the front if no capital letter is used.
// And, outputs passwords last char ASCII value 
void print_password_notupper(bool & upper_used, char keyword[])
{
	int len = strlen(keyword);  // length of array
	char replace_with = '$';    // replace char
	int i = 0;                  // counter
	int ascii_value = keyword[len-1];  // prints out the last chars ASCII value as int

	if (!upper_used)
	{
		cout << "Your new password is : ";
		cout << replace_with;
		for (int i = 0; i < len; ++i)
		{
			cout << keyword[i];
			if (i == len - 2)
			{
				cout << ascii_value << endl;
				++i;
			}
		}
	}
}
// Asks to re enter keyword
void ask_repeat(char & repeat)
{

	cout << "Would you like to enter in a different keyword?" << endl;
	cin >> repeat;
	cin.ignore(100, '\n');
}





