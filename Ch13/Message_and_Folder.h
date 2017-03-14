#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <set>
#include <utility>//std::move 操作
class Folder;
class Message
{
	friend void swap(Folder &lf, Folder &rf);
	friend void swap(Message &lm, Message &rm);
	friend class Folder;
public:
	//隐式地将folders初始化为空集 由于参数具有默认值 因此也是默认构造函数
	explicit Message(const std::string &s = "") : contents(s) { }  
	//拷贝控制成员 用来管理指向 本 message的指针
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	//移动构造函数
	Message(Message &&m);
	//移动赋值运算符
	Message& operator=(Message &&rhs);
	//从给定Folder中添加或者删除 Message
	void save(Folder&);
	void remove(Folder&);
	//实现向folders中添加或者删除元素
	void remFld(Folder *f);
	void addFld(Folder *f);
	
private:
	//拷贝控制函数要使用的工具函数
	//将 Message 添加到指定参数的 Folder 中
	void add_to_Folder(const Message &m);
	//将 从指向本 Message 的folder中删除 本Message
	void remove_from_Folders();
	//从本 Message 中移动 Folder 指针 （移动构造函数使用）
	void move_Folder(Message *m);
private:
	std::string			contents;		//消息文本
	std::set<Folder*>	folders;		//包含本 Message 的 Folder
};


class Folder
{
	friend class Message;
	friend void swap(Message &lm, Message &rm);
	friend void swap(Folder &lf, Folder &rf);
public:
	Folder() = default;
	Folder(const Folder&);
	~Folder();
	Folder& operator=(const Folder &f);
	//实现添加或者删除 Message
	//实现添加或者删除 Message
	void remMsg(Message *m);
	void addMsg(Message *m);
private:
	std::set<Message*>		messages;		//保存所指向的 Message 指针

	void add_to_Message(const Folder &f);
	void remove_from_Message();
};
void swap(Folder &lf, Folder &rf);