#include <iostream>
#include <string>
using namespace std;

class Person
{
	public:
		// constructors
		Person():name("none"),age(0), weight(0){}

        Person::Person(const char *new_name,int new_age, int new_weight)
		{
			name=new_name;
			age = new_age;
			weight = new_weight;
		}

      
		//destructor
		~Person(){}

	
       //accessors & mutators
       int GetAge()const { return age; }
       void SetAge(int age) { age = age; }
       int GetWeight() const { return weight; }
       void SetWeight(int weight) { weight = weight; }

	   //methods
   	   void print()
	   {
		   cout << "Name: " << name << "  ";
		   cout << "Age: " << age << " years, ";
		   cout << "Weight: " << weight << " Kg\n";
	   }


	protected:
		const char*	name;
		int age;
		int weight;
};

int main()
{
       Person e1; //defult constructor is used
       cout << "e1 is " << e1.GetAge() << " years old\n";
       cout << "e1 weigh " << e1.GetWeight() << " Kg\n";
	   //using mutator methods
       e1.SetAge(1);
	   e1.SetWeight(5);

	   cout << "e1 is growing, ";
	   e1.print();
	   
	   //creating object using constructor
       Person e2("Ahmad",39, 70); 
  	   cout << "e2:"; e2.print();
	   

	return 0;
}

