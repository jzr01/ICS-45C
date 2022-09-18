#include "String.cpp"
#include <iostream>
using namespace std;

int main()
{
//adjust code to print out your allocation counter


	String firstString = String("First");
	String secondString = String("Second");
	String thirdString = String(firstString);
	String fourthString = String("Fourth");
	String fifthString = String();


	cout << "+: " << firstString + secondString << endl; 		
	cout << "+=: " << (firstString += secondString) << endl;
	cout << "indexOf(char): " << firstString.indexOf('t') << endl;	
	cout << firstString << endl;
	cout << "indexOf(String): " << firstString.indexOf(secondString) << endl;	
	cout << "indexOf(String): " << firstString.indexOf(fourthString) << endl;	
	cout << "indexOf(String): " << fifthString.indexOf(fourthString) << endl;
	cout << "indexOf(String): " << firstString.indexOf(fifthString) << endl;
	cout << "LT: " << (secondString < firstString) << endl;			
	cout << "<<: "<< fifthString << endl;						
	cout << "<<: "<< fourthString << endl;						
	cout << "==: " << (fifthString == fourthString) << endl;		
	cout << "size(): "<< fifthString.size() << endl;					
	cout << "size(): "<< fourthString.size() << endl;				
	cout << "[]: "<< thirdString[1] << endl;						
	cout << "reverse(): "<< fourthString.reverse() << endl;				
	fifthString = thirdString;						
	cout << "<<: " << fifthString << " " << thirdString << endl;	
	cout << "[]: "<< fifthString[1] << endl;						
	cout << "[]: "<< fifthString[10] << endl;						

	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << endl;

	cout << (firstString < secondString) << endl;
	cout << (firstString == thirdString) << endl;

	return 0;
}
