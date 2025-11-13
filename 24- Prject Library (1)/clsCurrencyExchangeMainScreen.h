#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:


	enum _eCurrencyExchange
	{
		pListcurrency = 1, pFindCurrency = 2, pUpdateRate = 3,
		pCurrencyCalculator = 4, pMainMenu = 5
	};

	static void _ListCurrencies()
	{
		//cout << "Here you will put list currency\n";
		clsCurrenciesListScreen::ShowListCurrencyScreen();

	}
	static void _FindCurrency()
	{
		//cout << "Here you will put Find Currency\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _UpdateRate()
	{
		//cout << "Here you will put Update Rate\n";

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();


	}
	static void _CurrencyCalculator()
	{
		//cout << "Here you will put Currency Claculator\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}
	static void _BackToExchangeMenue()
	{
		cout << setw(37) << left << "" << "\nPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowMainMenueScreen();


	}
	static void PerformExchangeMenue(_eCurrencyExchange option)
	{

		switch (option)
		{
		case clsCurrencyExchangeMainScreen::pListcurrency:
			system("cls");
			_ListCurrencies();
			_BackToExchangeMenue();
			break;
		case clsCurrencyExchangeMainScreen::pFindCurrency:
			system("cls");
			_FindCurrency();
			_BackToExchangeMenue();
			break;
		case clsCurrencyExchangeMainScreen::pUpdateRate:
			system("cls");
			_UpdateRate();
			_BackToExchangeMenue();
			break;
		case clsCurrencyExchangeMainScreen::pCurrencyCalculator:
			 system("cls");
			_CurrencyCalculator();
			_BackToExchangeMenue();
			break;
		case clsCurrencyExchangeMainScreen::pMainMenu:
			system("cls");
			break;
		default:
			break;
		}
	}

	static short _ReadExchangeOption()
	{
		short num;

		num = clsInputValidate::ReadIntNumberBetween(1, 5, "Please Choose Between [1] tp [5] \n");
		return num;
	};
public:


	static void ShowMainMenueScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Currency Exchange Menu");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		PerformExchangeMenue(_eCurrencyExchange(_ReadExchangeOption()));

	}





};

