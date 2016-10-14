#include "Message_and_Folder.h"

void Message::save(Folder &f)
{
	folders.insert(&f);		//将包含本Message的Folder添加进folder
	f.addMsg(this);			//将本 message 添加进 f 的Message集合中
}
void Message::remove(Folder &f)
{
	folders.erase(&f);
	f.remMsg(this);
}

//拷贝控制成员 用来管理指向 本 message的指针
Message::Message(const Message &m) : contents(m.contents), folders(m.folders)
{
	add_to_Folder(m);
}
Message& Message::operator=(const Message &m)
{
	this->contents = m.contents;
	remove_from_Folders();	//从本 Message  folders 的每个Folder中删除指向本Message的指针
	this->folders = m.folders;		//拷贝 m 的指针
	add_to_Folder(m);		//将本 Message 添加到指向 m 的每个 Folder 中
	return *this;
}
Message::~Message()
{
	remove_from_Folders();	//从本 Message  folders 的每个Folder中删除指向本Message的指针
}

void Message::add_to_Folder(const Message &m)
{

	for (auto f : m.folders)
	{
		f->addMsg(this);		//向该Folder中添加一个指向本Message的指针
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
	//交换 lm rm中Folder的指向

	//先移除指向两个 Message 的 Folder 
	for (auto f : lm.folders)
	{
		f->remMsg(&lm);
	}
	for (auto f : rm.folders)
	{
		f->remMsg(&rm);
	}
	//交换 内容
	swap(lm.contents, rm.contents);
	swap(lm.folders, rm.folders);
	//重新设置 Folder 的指向
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