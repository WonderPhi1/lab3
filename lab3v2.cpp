

#include <iostream>
#include <list>
#include <string> 
#include <cmath>

using namespace std;
class Person
{

public:
	string fullPerson;
	string Fname;
	string Lname;
	string Email;
	int Phone;

	//Method 1 used in class staff
	//Get Person Data from user
	void getPersonData() {
		cout << "Enter First Name: ";
		cin >> Fname;
		cout << "Enter Last Name: ";
		cin >> Lname;
		cout << "Enter Email: ";
		cin >> Email;
		cout << "Enter Phone Number: ";
		cin >> Phone;
	}
	//Display Persons Data
	void displayPersonData() {
		cout << "\nFirst Name: " << Fname;
		cout << "\nLast Name: " << Lname;
		cout << "\nEmail: " << Email;
		cout << "\nPhone: " << Phone;

	}

	
};

//Not complete need to find a way to access specific objects in the list. The mark varible does nothing need to fix 
class Course {
public:
	string CourseName;
	string Mark;
	std::list<string> courselist = { " Math ", " Social Studies ", " Science ", " PE ", " English " };
};


//Change student class to work like the staff class
class Student : public Course, public Person {
public:
	string FullStudent;
	string course1;
	string course2;
	string course3;
	float grade1;
	float grade2;
	float grade3;

	//Bug GPA not caluclating correctly always is 0
	float getGPA() {
		float addedGrades = grade1 + grade2 + grade3;
		float average = addedGrades / 3.0;
		return addedGrades;
	}

	//Setter
	void setStudentData(string Fname, string Lname, string Email, int Phone, float grade1, float grade2, float grade3) {
		string phonetostring = std::to_string(Phone);

		FullStudent = Fname + Lname + Email + phonetostring;

	};


	//Getter
	void getStudent() {


		course1 = courselist.front();
		course2 = courselist.back();
		course3 = courselist.front();
		cout << FullStudent + course1 + course2 + course3 + "Student GPA: " << getGPA();
	};
};


//Using method 1 implementation from parent class Person
class Staff : public Person {
	string Postion;
	string Department;
	int Rate;
	int Hours;
	int salary;
public:
	int getSalary() {
		return Rate * Hours;
	}

	void getStaffData() {
		getPersonData();
		cout << "Enter Staff Postion:";
		cin >> Postion;
		cout << "Enter Staff Department:";
		cin >> Department;
		cout << "Enter Staff Pay Rate:";
		cin >> Rate;
		cout << "Enter Staff Hours worked:";
		cin >> Hours;

	}

	void displayStaffData() {
		displayPersonData();
		cout << "\nStaff's Postion:" << Postion;
		cout << "\nStaff's Department:" << Department;
		cout << "\nSalary: " << getSalary();

	}

};
int main()
{
	Staff s;
	Student stu;
	
	//Comment out/ remove comment for what method you want to try 

	
	cout << "\n----------Method 1---------\n";
	s.getStaffData();
	s.displayStaffData();
	
	
	
	
	
	return 0;





}


