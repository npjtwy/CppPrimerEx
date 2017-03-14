#define _CRT_SECURE_NO_WARNINGS
#include "iostream"
#include <string>
#include <stack>
using  namespace std;
/*
	Ex9_52 使用 stack 处理括号化得表达式 
*/ 
void Ex9_52()
{
	string str = "3*(7+8)+3/(2+1)";
	cout << str << endl;
	string::iterator it1 = str.begin();
	auto seen = 0;
	stack<char> strstack;
	while (it1 != str.end())
	{
		if (*it1 == '(')
		{
			++seen;
		}
		if (*it1 == ')' && seen)
		{
			while (strstack.top() != '(')
			{
				strstack.pop();
			}
			strstack.pop();
			strstack.push('X');
			++it1;
		}
		else
		{
			strstack.push(*it1);
			++it1;
		}
		
	}
	/*
	stack<char> newstack;
	while (!strstack.empty())
	{
	newstack.push(strstack.top());
	strstack.pop();
	}
	while (!newstack.empty())
	{
	cout << newstack.top();
	newstack.pop();
	}
	cout << endl;
	*/
	//这里可以简单点
	string output;
	for (; !strstack.empty(); strstack.pop()) 
	{
		output.insert(output.begin(), strstack.top());
	}
	cout << output << endl;

}

int main()
{
	Ex9_52();
	
	system("pause");
	return 0;
}
/* github
#include <stack>
using std::stack;
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

int main()
{
auto& expr = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";
auto repl = '#';
auto seen = 0;

stack<char> stk;

for (auto c : expr) {
stk.push(c);
if (c == '(') ++seen;   // open
if (seen && c == ')') { // pop elements down to the stack
while (stk.top() != '(') stk.pop();
stk.pop();      // including the open parenthesis
stk.push(repl); // push a value indicate it was replaced
--seen;         // close
}
}

// Test
string output;
for (; !stk.empty(); stk.pop()) output.insert(output.begin(), stk.top());
cout << output << endl; // "This is # and # over"
*/
