#ifndef TEST_7_34_H
#define TEST_7_34_H

#include <string>
#include <iostream>
#include <vector>

int height;
class Screen
{
public:
	typedef std::string::size_type pos;
	void dummy_fcn(pos height)
	{
		cursor = width*height;
	}
protected:
private:
	pos cursor = 0;
	pos height = 0, width = 0;

};

typedef std::string Type;//编译不通过
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	Type initVal()
	{
		return 3.14;
	}
private:
	int val;
};
Exercise::Type Exercise::setVal(Type parm){
	val = parm + initVal();      //initVal需要实现
	return val;
}

class X
{
public:
	X(int i, int j) : base(i), rem(i % j) {}
	int rem, base;
};

//7_43 begin
//定义一个
class NoDfault
{
public:
	NoDfault(int a) : n(a) {}
private:
	int n;
};

class C
{
public:
	C() : cc(0) {}  // is not C(NoDfault c) : cc(c) {}
protected:
private:
	NoDfault cc;
};
//7_43 end

#endif //TEST_7_34_H