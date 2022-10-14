#include <iostream>
#include <list>
#include <string> 
#include <cmath>

using namespace std;

class IPerson{
  protected:
    string Fname;
    string Lname;
    string Email;
    string Phone;

  public:
    IPerson(string fname, string lname, string email, string phone){
      Fname = fname;
      Lname = lname;
      Email = email;
      Phone = phone;
    }

    string getFirstName(){
      return Fname;
    }

    string getLastName(){
      return Lname;
    }

    string getEmail(){
      return Email;
    }

    string getPhone(){
      return Phone;
    }

    virtual string getFullName() = 0;

};

class Staff : public IPerson{
  protected:
    string Position;
    string Department;
    int Rate;
    int HoursWorked;

  public:
    Staff(string firstName, string lastName, string email, string phone, 
      string position, string department, int rate, int hoursWorked):
    IPerson(firstName, lastName, email, phone)
    {
      
      Position = position;
      Department = department;
      Rate = rate;
      HoursWorked = hoursWorked;
    }

    string getPosition(){
      return Position;
    }

    string getDepartment(){
      return Department;
    }

    int getRate(){
      return Rate;
    }

    int getHoursWorked(){
      return HoursWorked;
    }

    int getSalary(){
      return HoursWorked * Rate;
    }
    
    string getFullName(){
      string fullName = this->Fname + " " + this->Lname;
      return fullName;
    }
};

class Student : public IPerson {
  protected:
    string School;
    list<class Course> Courses;

  
  public:
    Student(string firstName, string lastName, string email, string phone, 
      string school, list<class Course> courses):
    IPerson(firstName, lastName, email, phone)
    {
      School = school;
      Courses = courses;
    }

    string getSchool(){
      return School;
    }

    int getGPA(){
      
    }

    string getFullName(){
      string fullName = this->Fname + " " + this->Lname;
      return fullName;
    }
};

class Teacher : public Staff{
  protected:
    list<class Course> Courses;

  public:
    Teacher(string firstName, string lastName, string email, string phone,
      string position, string department, int rate, 
      int hoursWorked, list<class Course> courses):
      Staff(firstName, lastName, email, phone, 
       position, department,rate, hoursWorked)
      {
        Courses = courses;
      }

    int getSalary(){
      return this->Rate * Courses.size();
    }
};

class Course{
  protected:
    string CourseName;
    int Mark;
  
  public:
    Course(string courseName, int mark){
      CourseName = courseName;
      Mark = mark;
    }

    int getMark(){
      return Mark;
    }

    string getCourseName(){
      return CourseName;
    }
};

int main(){
  // Create course list
  list<Course> courses;
  courses.push_back(Course("English", 80));
  courses.push_back(Course("Math", 90));
  courses.push_back(Course("Chemistry", 40));
  courses.push_back(Course("History", 70));

  // Create Student object and use get gpa method

  // Create Staff object and use get salary method

  // Create Teacher and use get salary method 
  

  return 0;
}