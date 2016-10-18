#pragma once
// ¼ò»¯°æ std::string 
#include <memory>
#include <iostream>

class String
{
public:
	String();
	String(const String&);
	String& operator=(const String&);
	String(char *p);
	~String();
	void free();
	char* begin()const;
	char* end()const;
	size_t size()const;
private:
	void allocate_n_copy(char *fir, char *lst);
private:
	char *elements;
	char *first_free;
	std::allocator<char> alloc;
};