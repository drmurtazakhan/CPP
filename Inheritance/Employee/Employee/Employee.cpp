#include <iostream>
#include <string>
using namespace std;

class Employee
{
	public:
		// constructors
		Employee():name("None"),id(0000), salary(0){}

        Employee::Employee(const char *new_name, int new_id, int new_salary)
		{
			name=new_name;
			id = new_id;
			salary = new_salary;
		}

      
		//destructor
		~Employee(){}

	
       //accessors
       int getID()const { return id; }
       int getSalary() const { return salary; }
	   

	   //mutators
       void setID(int new_id) { id = new_id; }
       void setSalary(int new_salary) { salary = new_salary; }

   	   //methods
   	   void print()
	   {
		   cout << "Name: " << name << "  ";
		   cout << "ID: " << id << " ";
		   cout << "Salary: " << salary << " ";;
	   }



	protected:
		const char*	name;
		int id;
		int salary;
};

class Manager : public Employee
{
public:

   // Constructors
   Manager(const char *new_name, int new_id, int new_salary, int new_mangOfDept)
   : Employee(new_name,new_id, new_salary) // constructor of super class
   {
	   
	   mangOfDept = new_mangOfDept;
   }

   ~Manager(){}

   // Accessors
   int getmangOfDept() const { return mangOfDept; }
   void setmangOfDept(int new_mangOfDept) { mangOfDept = new_mangOfDept; }

   // Other methods
   void print()
   {
	   Employee::print();
	   cout << "Mang. of Dept.: " << mangOfDept << " ";
   }
   

private:
   int mangOfDept;
};


int main()
{

	   Employee e1;

	   Employee e2("Ali",3412, 70000); 
       cout << "\n" << "e2: "; e2.print();

       Manager e3("Ahmad", 3400, 80000,3412);
	   cout << "\n" << "e3: "; e3.print();

	return 0;
}

