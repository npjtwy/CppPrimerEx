#include "Message_and_Folder.h"

//Message 实现
//从给定Folder中添加或者删除 Message
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

//实现向folders中添加或者删除元素
void Message::remFld(Folder *f)
{
	folders.erase(f);
}
void Message::addFld(Folder *f)
{
	folders.insert(f);
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
//移动构造函数
Message::Message(Message && m) : contents(std::move(m.contents))
{
	move_Folder(&m);		//移动 folders 并更新 Folder指针
}
//移动赋值运算符
Message & Message::operator=(Message && rhs)
{
	// TODO: 在此处插入 return 语句
	if (this != &rhs)     //检查自赋值
	{
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folder(&rhs);		//重置 folders 指向本 Message
	}
	return *this;
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
//从本 Message 中移动 Folder 指针 （移动构造函数使用）
void Message::move_Folder(Message * m)
{
	folders = std::move(m->folders);		//使用 set 的移动赋值运算符
	for (auto f : folders)
	{
		f->remMsg(m);		//从 Folder 中删除旧的 Message
		f->addMsg(m);		//将本 Message 添加到 Folder 中
	}
	m->folders.clear();		//清空 m 的 folders
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

//Folder 实现
inline
void swap(Folder &lf, Folder &rf)
{
	;
}
Folder::Folder(const Folder &f)
{
	messages = f.messages;
	add_to_Message(f);		//向 f 所指向的 Message 的 folders 中添加本 Folder
}
Folder::~Folder()
{
	remove_from_Message();		//将本 Folder 从所指的 Message 的 folders 中删除
}
Folder& Folder::operator=(const Folder &f)
{
	remove_from_Message();	//先把自己从所指的 Message 的 folders 中删除 在添加到 f 所指的 Message
	add_to_Message(f);
	messages = f.messages;
	return *this;
}
//将自身从所指的 Message 中的 folders 中删除或者添加进去
void Folder::add_to_Message(const Folder &f)
{
	for (auto m : f.messages)
	{
		m->addFld(this);
	}
}
void Folder::remove_from_Message()
{
	for (auto m : messages)
	{
		m->remFld(this);
	}
}
//从 messages 中移除或添加指定的 Message
void Folder::remMsg(Message *m)
{
	messages.erase(m);
}
void Folder::addMsg(Message *m)
{
	messages.insert(m);
}