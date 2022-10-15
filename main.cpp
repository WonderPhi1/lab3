#include <iostream>
#include <list>
#include <string> 
#include <cmath>

using namespace std;


class IPerson{
  public:
    string Fname;
    string Lname;
    string Email;
    string Phone;

  public:
    /**
     * @brief 
     * IPerson constructer of fname ,lname,email,phone
     */
    IPerson(string fname, string lname, string email, string phone){
      Fname = fname;
      Lname = lname;
      Email = email;
      Phone = phone;
    }
    
    string getFirstName(){
      /**
       *  Returns first name
       * @brief 
       * 
       *
       */
      return Fname;
    }
    
    string getLastName(){
      /**
       * @brief 
       * Returns Lname
       */
      return Lname;
    }

    string getEmail(){
      /**
       * @brief 
       * Returns Email
       * 
       */
      return Email;
    }
    
    string getPhone(){
      /**
       * @brief 
       * Returns Phone
       * 
       */
      return Phone;
    }

    virtual string getFullName() = 0;

};

class Staff : public IPerson{
  protected:
    /// @brief 
    string Position;
    string Department;
    int Rate;
    int HoursWorked;
  
  public:
    /// @brief 
    /// @param firstName 
    /// @param lastName 
    /// @param email 
    /// @param phone 
    /// @param position 
    /// @param department 
    /// @param rate 
    /// @param hoursWorked 

    /**
     * @brief 
     * Constructer for staff 
     */
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
      /**
       * @brief 
       * Returns Position
       * 
       */
      return Position;
    }
     
    string getDepartment(){
      /**
       * @brief 
       * Returns Department
       * 
       */
      return Department;
    }
    
    int getRate(){
      /**
       * @brief 
       * Returns Rate
       * 
       */
      return Rate;
    }
     
    int getHoursWorked(){
      /**
       * @brief 
       * Returns HoursWorked
       * 
       */
      return HoursWorked;
    }
    
    int getSalary(){
      /**
       * @brief 
       * Calculates salary by multiplying HoursWorked by Rate
       * 
       */
      return HoursWorked * Rate;
    }
    
    string getFullName(){
      /**
       * @brief 
       * Returns fullName which is FName + Lname
       * 
       * 
       */
      string fullName = this->Fname + " " + this->Lname;
      return fullName;
    }
};
/// @brief 
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
      return 3;
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
    /// @brief 
    string CourseName;
    int Mark;
  
  public:
    Course(string courseName, int mark){
      CourseName = courseName;
      Mark = mark;
    }
    //Get mark 
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
  Student* s1 = new Student("Phillip", "Obiora", "phillip.obiora@leth.ca", "4036674504", "uleth", courses);
  cout << "--------------------Student--------------------" << endl;
  cout << "Name: " << s1->getFullName() << endl;
  cout << "Email: " << s1->getEmail() << endl;
  cout << "Phone: " << s1->getPhone() << endl;
  cout << "School: " << s1->getSchool() << endl;
  cout << "GPA: " << s1->getGPA() << endl;

  // Create Staff object and use get salary method
  Staff *sta1 = new Staff("Joe", "Blow", "Joe.Blow@uleth.ca", "7775557777", "Teacher", "Business", 30, 80);
  cout << "--------------------Staff--------------------" << endl;
  cout << "Name: " << sta1->getFullName() << endl;
  cout << "Salary: " << sta1->getSalary() << endl;


  // Create Teacher and use get salary method 
  Teacher *t1 = new Teacher("Jane", "Doe", "Jane.Doe@uleth.ca", "5555557777", "Teacher", "Arts", 25, 40, courses);
  cout << "--------------------Teacher--------------------" << endl;
  cout << "Name: " << t1->getFullName() << endl;
  cout << "Phone: " << t1->getPhone() << endl;
  cout << "Position: " << t1->getPosition() << endl;
  cout << "Department: " << t1->getDepartment() << endl;
  cout << "Rate: " << t1->getRate() << endl;
  cout << "Hours Worked: " << t1->getHoursWorked() << endl;
  cout << "Salary: " << t1->getSalary() << endl;

  return 0;
}