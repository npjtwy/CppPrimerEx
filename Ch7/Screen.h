//编写screen类  
// 7_23: screen表示显示器中的一个窗口。每个screen包含一个用于保存screen内容的string成员和
//三个string::size_type类型的成员，他们分别表示光标的尾置以及屏幕的高和宽


//7_27  给自己的screen类添加move， set和display函数

//7_32  添加Window_mgr类 其中clear是Window_mgr的成员  是Screen的友元

//7_33 给Scren类中加 size（）函数

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);

private:
	std::vector<Screen> screens /*= { Screen(24, 80, ' ') }*/;//添加上注释内容会报错
};


class Screen
{

friend void Window_mgr::clear(ScreenIndex);

public:	
	typedef std::string::size_type pos;
	//添加构造函数
	Screen() = default;
	//Screen( pos& ht,  pos& wd, char contents) : height(ht), width(wd), 
	//	contents(ht * wd, ' ') {}   //contents(ht * wd, ' ') 是string类的构造函数
	Screen(const pos& ht, const pos& wd, char c) : height(ht), width(wd),
		contents(ht * wd, c) {}

	char get() const { return contents[cursor]; }
	char get(pos& r, pos& c) const { return contents[r*width + c]; }

	Screen& move(pos, pos);
	Screen& set(pos, pos, char);
	Screen& set(char);
	Screen& display(std::ostream& os){ do_display(os); return *this; }
	Screen::pos size() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	void do_display(std::ostream& os) const { os << contents; }
};

Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

Screen& Screen::set(pos r, pos col, char c)
{
	Screen::contents[r*width + col] = c;
	return *this;
}

Screen& Screen::set(char ch)
{
	contents[cursor] = ch;
	return *this;
}

void Window_mgr::clear(ScreenIndex ix)
{
	Screen &s = screens[ix];
	s.contents = std::string(s.width * s.height, ' ');  //有点问题？？？  github上的答案也报错
}

Screen::pos Screen::size() const
{
	return height * width;
}

#endif // !SCREEN_H


/*#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED



#include <vector>
#include <string>
#include <iostream>

class Screen;

class Window_mgr {
public:
using ScreenIndex = std::vector<Screen>::size_type;
inline void clear(ScreenIndex);

private:
std::vector<Screen> screens;
};

class Screen {
friend void Window_mgr::clear(ScreenIndex);

public:
using pos = std::string::size_type;

Screen() = default; // 1
Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {} // 2
Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
{
} // 3

char get() const { return contents[cursor]; }
char get(pos r, pos c) const { return contents[r * width + c]; }
inline Screen& move(pos r, pos c);
inline Screen& set(char c);
inline Screen& set(pos r, pos c, char ch);

const Screen& display(std::ostream& os) const
{
do_display(os);
return *this;
}
Screen& display(std::ostream& os)
{
do_display(os);
return *this;
}

private:
void do_display(std::ostream& os) const { os << contents; }

private:
pos cursor = 0;
pos height = 0, width = 0;
std::string contents;
};

inline void Window_mgr::clear(ScreenIndex i)
{
if (i >= screens.size()) return; // judge for out_of_range.
Screen& s = screens[i];
s.contents = std::string(s.height * s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
cursor = r * width + c;
return *this;
}

inline Screen& Screen::set(char c)
{
contents[cursor] = c;
return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
contents[r * width + c] = ch;
return *this;
}



#endif // TEST_H_INCLUDED
*/