#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <set>
#include <utility>//std::move ����
class Folder;
class Message
{
	friend void swap(Folder &lf, Folder &rf);
	friend void swap(Message &lm, Message &rm);
	friend class Folder;
public:
	//��ʽ�ؽ�folders��ʼ��Ϊ�ռ� ���ڲ�������Ĭ��ֵ ���Ҳ��Ĭ�Ϲ��캯��
	explicit Message(const std::string &s = "") : contents(s) { }  
	//�������Ƴ�Ա ��������ָ�� �� message��ָ��
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	//�ƶ����캯��
	Message(Message &&m);
	//�ƶ���ֵ�����
	Message& operator=(Message &&rhs);
	//�Ӹ���Folder����ӻ���ɾ�� Message
	void save(Folder&);
	void remove(Folder&);
	//ʵ����folders����ӻ���ɾ��Ԫ��
	void remFld(Folder *f);
	void addFld(Folder *f);
	
private:
	//�������ƺ���Ҫʹ�õĹ��ߺ���
	//�� Message ��ӵ�ָ�������� Folder ��
	void add_to_Folder(const Message &m);
	//�� ��ָ�� Message ��folder��ɾ�� ��Message
	void remove_from_Folders();
	//�ӱ� Message ���ƶ� Folder ָ�� ���ƶ����캯��ʹ�ã�
	void move_Folder(Message *m);
private:
	std::string			contents;		//��Ϣ�ı�
	std::set<Folder*>	folders;		//������ Message �� Folder
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
	//ʵ����ӻ���ɾ�� Message
	//ʵ����ӻ���ɾ�� Message
	void remMsg(Message *m);
	void addMsg(Message *m);
private:
	std::set<Message*>		messages;		//������ָ��� Message ָ��

	void add_to_Message(const Folder &f);
	void remove_from_Message();
};
void swap(Folder &lf, Folder &rf);