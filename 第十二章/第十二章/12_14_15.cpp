#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>
using  namespace std;
struct destination
{};

struct connection
{

};
connection connect(destination*)
{
	connection c;
	return c;
}
void disconnect(connection)
{
	;
}

void end_connection(connection *p)
{
	disconnect(*p);
}
/*
void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
}*/
// lambda °æ±¾
void f(destination &d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p); });
}

int main()
{
	
	
	system("pause");
	return 0;
}