#include "iostream"
#include <string>

using  namespace std;

void main()
{
	char ch, prech = '\0'; //***
	int aCont = 0, eCont = 0, oCont = 0, uCont = 0, iCont = 0, sCont = 0, tCont = 0, nCont = 0,
		fiCont = 0, ffCont = 0, flCont = 0;

	while (cin >> std::noskipws >> ch)  //git answer ===>> std::noskipws ²»ºöÂÔ¿Õ¸ñ
	{
		switch (ch)
		{
		case 'a': case 'A':
			++aCont;
			break;
		case 'e':  case 'E':
			++eCont;
			break;
		case  'i': 
			if (prech == 'f') ++fiCont;
		case 'I':
			++iCont;
			break;
		case 'o': case 'O':
			++oCont;
			break;
		case 'u': case 'U':
			++uCont;
			break;
		case ' ':
			++sCont;
			break;
		case '	':
			++tCont;
			break;
		case '\n':
			++nCont;
			break;
		case'f':
			if (prech == 'f') ++ffCont;
			break;
		case 'l':
			if (prech == 'f') ++flCont;
			break;
		default:
			break;
		}
		prech = ch;
	}
	
	cout << "Number of a: " << aCont << endl;
	cout << "Number of e: " << eCont << endl;
	cout << "Number of i: " << iCont << endl;
	cout << "Number of o: " << oCont << endl;
	cout << "Number of u: " << uCont << endl;
	cout << "Number of s: " << sCont << endl;
	cout << "Number of t: " << tCont << endl;
	cout << "Number of n: " << nCont << endl;
	cout << "Number of ff: " << ffCont << endl;
	cout << "Number of fi: " << fiCont << endl;
	cout << "Number of fl: " << flCont << endl;


	system("pause");
}