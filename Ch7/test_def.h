#ifndef TEST_DEF_H
#define TEST_DEF_H

#include <string>
#include <iostream>

typedef std::string Type;//±àÒë²»Í¨¹ý
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal()
	{
		return 3.14;
	};
private:
	int val;
};
Exercise::Type Exercise::setVal(Type parm){
	val = parm + initVal();
	return val;
}

#endif