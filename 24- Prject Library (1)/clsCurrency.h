#pragma once



#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "clsString.h";

#include "clsLoginScreen.h";


using namespace std;


class clsCurrency

{
private:

	enum enMode{EmptyMode=0 , UpdateMode=1};

	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate; 

	static clsCurrency _ConvertLineToCurrencyObject(string line , string separator="#//#")
	{
		vector <string> vSplitedLine;
		vSplitedLine = clsString::Split(line, separator);


		return clsCurrency(enMode::UpdateMode, vSplitedLine[0], vSplitedLine[1], vSplitedLine[2], stod(vSplitedLine[3]));

		
	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Separator;
		stCurrencyRecord += Currency.CurrencyCode() + Separator;
		stCurrencyRecord += Currency.CurrencyName() + Separator;
		stCurrencyRecord += to_string(Currency.Rate());

		return stCurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrencysDataFromFile()
	{
		//get the date from file ?
		vector <clsCurrency> vCurrencyFromFile;

		fstream myfile;
		string line;


		myfile.open("Currencies.txt", ios::in);

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(line);
				vCurrencyFromFile.push_back(currency);

            }
			myfile.close();
		}


		return vCurrencyFromFile;



		// and channge what you want 
		//store the data again on the file




	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{
		
		fstream myfile;
		string line;
		myfile.open("Currencies.txt", ios::out);

		if (myfile.is_open())
		{

			for (clsCurrency C : vCurrencys)
			{
				line = _ConverCurrencyObjectToLine(C);
				myfile << line << endl;

			}

			myfile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}



public:

	clsCurrency(enMode mode, string country, string currencyCode, string currencyName, float rate)
	{
		_Mode = mode;
		_Country = country;
		_CurrencyCode = currencyCode;
		_CurrencyName = currencyName;
		_Rate = rate;

	}


    string Country()
	{
		return _Country;
    }

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float rate)
	{
		_Rate = rate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country) // i upper country from the file to make sure every thing going will
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static   clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode); // you have to get first the object full
		return (!C1.IsEmpty());

	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile(); // because i dont wnat to access the private function [ _LoadCurrencysDataFromFile ] so i make this one
	}

	float ConvertToUSD(float Amount)
	{
		return float (Amount / Rate());

	}

	float ConvertToOtherCurrency(float Amount , clsCurrency curr2)
	{

		return float(ConvertToUSD(Amount) * curr2.Rate());
		

	}


};

