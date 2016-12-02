#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>
#include <vector>
using  namespace std;
class Quote
{
	friend bool operator!=(const Quote& lhs, const Quote& rhs);
public:
	Quote() = default;
	Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) {}
	string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n * price; }
	virtual ~Quote() = default;
	virtual void debug() { cout << bookNo << " " << price << endl; }

	//定义拷贝控制函数
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) { cout << "Quote(const Quote &q)" << endl; }
	
	Quote(Quote &&q) : bookNo(std::move(q.bookNo) ), price(std::move(q.price))
	{
		cout << "Quote(Quote &&q)" << endl;
	}

	Quote& operator=(const Quote &rhs)
	{
		if (*this != rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
	}
		
		cout << "Quote& operator=(const Quote &rhs)" << endl;
		return *this;
	}

	Quote& operator=(Quote &&rhs)
	{
		if (*this != rhs)
		{
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);
		}
		
		cout << "Quote& operator=(Quote &&rhs)" << endl;
		return *this;
	}


	virtual void printinfo()
	{
		cout << "bookNo: " << bookNo << "price: " << price << endl;
	}

	//返回一份对象的拷贝 ， 供 Basket 的 add_item 成员调用
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }
protected:
	double price = 0.0;
	string bookNo;
};

bool operator!=(const Quote& lhs, const Quote& rhs)
{
	if (lhs.bookNo == rhs.bookNo  &&  lhs.price == rhs.price)
		return false;
	else
		return true;
}

class Bulk_quote : public Quote
{
	friend bool operator!=(const Bulk_quote &lhs, const Bulk_quote &rhs);
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double p, std::size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}
	double net_price(std::size_t n) const override
	{
		if (n >= min_qty)		return n * discount * price;
		else
		{
			return n * price;
		}
	}
	virtual void debug() { cout << min_qty << " " << discount << endl; }

	Bulk_quote(const Bulk_quote &bq) : Quote(bq)
	{
		min_qty = bq.min_qty;
		discount = bq.discount;
		cout << "Bulk_quote(const Bulk_quote &bq)" << endl;
	}

	Bulk_quote(Bulk_quote &&bq) : Quote(std::move(bq))
	{
		min_qty = std::move(bq.min_qty);
		discount = std::move(bq.discount);
		cout << "Bulk_quote(Bulk_quote &&bq)" << endl;
	}

	Bulk_quote& operator=(const Bulk_quote &rhs)
	{
		if (*this != rhs)
		{
			Quote::operator=(rhs);
			min_qty = rhs.min_qty;
			discount = rhs.discount;
		}
		
		cout << "Bulk_quote& operator=(const Bulk_quote &rhs)" << endl;
		return *this;
	}

	Bulk_quote& operator=(Bulk_quote && rhs)
	{
		if (*this != rhs)
		{
			Quote::operator=(rhs);
			min_qty = std::move(rhs.min_qty);
			discount = std::move(rhs.discount);
		}
		
		cout << "Bulk_quote operator=(Bulk_quote &&rhs)" << endl;
		return *this;
	}

	void printinfo()
	{
		cout << "bookNo: " << bookNo << " price: " << price << endl << "min_qty: " << min_qty << " discount: " << discount << endl;
	}

	virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
	virtual Bulk_quote* clone() && {return new Bulk_quote(std::move(*this)); }
	
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

bool operator!=(const Bulk_quote &lhs, const Bulk_quote &rhs)
{
	if (Quote(lhs) != Quote(rhs) || lhs.min_qty != rhs.min_qty || lhs.discount != rhs.discount)
		return true;
	else
		return false;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	//根据传入的对象类型调用 Quto::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << n << " total due: " << ret << endl;
	return ret;
}
/*
class Limit_quote : public Quote
{
public:
	Limit_quote() = default;
	Limit_quote(const std::string &book, double p, std::size_t lcnt, double disc) :
		Quote(book, p), limit_count(lcnt), discount(disc) {}

	double net_price(std::size_t cnt)
	{
		if (cnt <= limit_count)
			return cnt * (1 - discount) * price;
		else
			return (cnt - limit_count)*price + cnt * (1 - discount) * price;
	}
private:
	std::size_t limit_count = 0;
	double discount = 0.0;
};

*/
/*
class Disc_quote : public Quote
{
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double p, std::size_t qty, double disc) :
		Quote(book, p), quantity(qty), discount(disc) {}
	virtual double net_price(std::size_t n) const override = 0;
protected:
	std::size_t		quantity = 0;
	double			discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string &book, double pric, std::size_t qty, double disc) : 
		Disc_quote(book, pric, qty, disc) { }

	double net_price(std::size_t cnt) const override
	{
		if (cnt >= quantity)	return cnt * (1 - discount) * price;
		else
		{
			return cnt * price;
		}
	}
private:
};
*/