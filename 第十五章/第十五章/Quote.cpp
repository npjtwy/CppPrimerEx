#include "Quote.h"
#include "basket.h"


/*
int main()
{
	Bulk_quote bq("adfd34", 98.6, 16, 0.8);
	Bulk_quote bq2 = bq;
	Bulk_quote bq3(bq);

	Bulk_quote bq4("dasd", 32, 12, 0.9);

	bq4 = bq;

	bq.printinfo();

	system("pause");
	return 0;
}
*/

//15_28
/*
int main()
{
	vector<Quote> qv;
	Quote q("cpp", 2);
	Bulk_quote bq("java", 3, 4, 0.8);

	qv.push_back(q);
	qv.push_back(bq);

	cout << qv[1].net_price(5) + qv[0].net_price(5) << endl;


	system("pause");
	return 0;
}
*/
//15_29

int main()
{
	vector<shared_ptr<Quote>> qv;
	Quote q("cpp", 2);
	Bulk_quote bq("java", 3, 4, 0.8);
	Basket bskt;
	qv.push_back(make_shared<Quote>(q));
	qv.push_back(make_shared<Bulk_quote>(bq));
	qv.push_back(make_shared<Quote>("C#", 18));
	for (auto i : qv)
	{
		bskt.add_item(*i);
	}

	bskt.total_receipt(std::cout);
	
	system("pause");
	return 0;
}