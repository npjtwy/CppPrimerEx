#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <set>
class Folder;

class Message
{
	friend class Folder;
	friend void swap(Message &lm, Message &rm);
public:
	//��ʽ�ؽ�folders��ʼ��Ϊ�ռ� ���ڲ�������Ĭ��ֵ ���Ҳ��Ĭ�Ϲ��캯��
	explicit Message(const std::string &s = "") : contents(s) { }  
	//�������Ƴ�Ա ��������ָ�� �� message��ָ��
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	//�Ӹ���Folder����ӻ���ɾ�� Message
	void save(Folder&);
	void remove(Folder&);
	
private:
	//�������ƺ���Ҫʹ�õĹ��ߺ���
	//�� Message ��ӵ�ָ�������� Folder ��
	void add_to_Folder(const Message &m);
	//�� ��ָ�� Message ��folder��ɾ�� ��Message
	void remove_from_Folders();
private:
	std::string			contents;		//��Ϣ�ı�
	std::set<Folder*>	folders;		//������ Message �� Folder
};


class Folder
{
public:
	//ʵ����ӻ���ɾ�� Message
	//ʵ����ӻ���ɾ�� Message
	void remMsg(Message *m);
	void addMsg(Message *m);
private:
	std::set<Message*>		messages;		//������ָ��� Message ָ��
};
