#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"


using namespace std;



class clsFindCurrencyScreen : protected clsScreen
{



private:

	enum enFindMethod
	{
		pByCode=1,pBycountry=2
	};


	static void _PerformChooseMethod(enFindMethod option)
	{
		switch (option)
		{
		case clsFindCurrencyScreen::pByCode:
			CodeMethod();
			break;
		case clsFindCurrencyScreen::pBycountry:
			CountryMethod();
			
			break;
		default:
			break;
		}
	}
	static void CodeMethod()
	{
		string CurrencyCode;
		cout << "\nPlease Enter CurrencyCode: ";
		CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_ShowResults(Currency);
	}
	static void CountryMethod()
	{
		string Country;
		cout << "\nPlease Enter Country Name: ";
		Country = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountry(Country);
		_ShowResults(Currency);
	}
	static short ReadNumber()
	{
		short num;
		cout << "Find By [1] Code or [2] Country?\n";
		num = clsInputValidate::ReadIntNumberBetween(1, 2, "Find By [1] Code or [2] Country? ");
		return num;

	}
	static void _PrintCurrencyCardInfo(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";
	}
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCardInfo(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}


public:

	static void ShowFindCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("Find Currency Screen");
		_PerformChooseMethod(enFindMethod(ReadNumber()));
	}



};

