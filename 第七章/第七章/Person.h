//Person 


#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
using  namespace std;

class Person
{
	friend std::istream& read(std::istream&, Person&);
	friend std::ostream& print(std::ostream&, Person&);
public:
	//��ӹ��캯��
	Person() = default;
	//���캯���βα��� const
	Person( std::string& n,  std::string& ad) : name(n), addr(ad) {}
	Person(std::istream& is){ read(is, *this); }

	const string& getName() const { return name; };
	const string& getAddr() const { return addr; }; 
	

private:
	string name;
	string addr;
}; 

std::istream& read(std::istream& is, Person& people)
{
	is >> people.name >> people.addr;
	return is;
}

std::ostream& print(std::ostream& os, Person& people)
{
	os << people.name << ' ' << people.addr;
	return os;
}




#endif //PERSON_H