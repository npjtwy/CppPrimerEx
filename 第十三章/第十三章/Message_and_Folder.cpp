#include "Message_and_Folder.h"

void Message::save(Folder &f)
{
	folders.insert(&f);		//��������Message��Folder��ӽ�folder
	f.addMsg(this);			//���� message ��ӽ� f ��Message������
}
void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

//�������Ƴ�Ա ��������ָ�� �� message��ָ��
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folder(m);
}
Message& Message::operator=(const Message &m)
{
	this->contents = m.contents;
	remove_from_Folders();	//�ӱ� Message  folders ��ÿ��Folder��ɾ��ָ��Message��ָ��
	this->folders = m.folders;		//���� m ��ָ��
	add_to_Folder(m);		//���� Message ��ӵ�ָ�� m ��ÿ�� Folder ��
	return *this;
}
Message::~Message()
{
	remove_from_Folders();	//�ӱ� Message  folders ��ÿ��Folder��ɾ��ָ��Message��ָ��
}

void Message::add_to_Folder(const Message &m)
{

	for (auto f : m.folders)
	{
		f->addMsg(this);		//���Folder�����һ��ָ��Message��ָ��
	}

}
void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

inline
void swap(Message &lm, Message &rm)
{
	using std::swap;
	//���� lm rm��Folder��ָ��

	//���Ƴ�ָ������ Message �� Folder 
	for (auto f : lm.folders)
	{
		f->remMsg(&lm);
	}
	for (auto f : rm.folders)
	{
		f->remMsg(&rm);
	}
	//���� ����
	swap(lm.contents, rm.contents);
	swap(lm.folders, rm.folders);
	//�������� Folder ��ָ��
	for (auto f : lm.folders)
	{
		f->addMsg(&lm);
	}
	for (auto f : rm.folders)
	{
		f->addMsg(&rm);
	}
}




void Folder::remMsg(Message *m)
{
	messages.erase(m);
}
void Folder::addMsg(Message *m)
{
	messages.insert(m);
}