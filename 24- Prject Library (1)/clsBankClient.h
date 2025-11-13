#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;


class clsBankClient : public clsPerson
{
private:
	
    enum enMode { EmptyMode = 0 , UpdateMode =1 ,AddNewMode=2  };
    
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
    enMode _Mode;
    bool _MarkedForDelete = false;



    static clsBankClient _ConvertLineToClientObject(string Line , string delamater ="#//#")
    {
        vector <string> vClient;

        vClient = clsString::Split(Line, delamater);

        return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stod(vClient[6]));

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode,"", "", "", "", "", "", 0);
    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkedForDelete == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
               

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        

        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);


    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    string _PrepareTransferRecord( clsBankClient DestinationClient, double amount , string separator = "#//#")
    {
        string line = "";

        line += clsDate::GetSystemDateTimeString() + separator;
        line += AccountNumber() + separator;
        line += DestinationClient.AccountNumber() + separator;
        line += to_string(amount) + separator;
        line += to_string(AccountBalance) + separator;
        line += to_string(DestinationClient.AccountBalance) + separator;
        line += CurrentUser.UserName;

        return line;


    }

    void _TransferRegisterLog(clsBankClient DestinationClient, double amount)
    {
        fstream myfile;

        myfile.open("TransferRegister.txt", ios::out | ios::app);

        if (myfile.is_open())
        {
            myfile << _PrepareTransferRecord(DestinationClient, amount) << endl;

        }

        myfile.close();
    }

    struct stTransferLog;
    static stTransferLog  _ConvertTransferLogLineToRecord(string line , string separator="#//#")
    {
        stTransferLog box;
        vector <string> vLineSplited = clsString::Split(line, separator);
        // we split one line ok we need to push every word on the structure
        box.Date = vLineSplited[0];
        box.SourceAccountNumbr = vLineSplited[1];
        box.DistAccountNumbr= vLineSplited[2];
        box.amount = stod(vLineSplited[3]) ;
        box.SourceAccountBalance = stod(vLineSplited[4]);
        box.DistAccountBalance = stod(vLineSplited[5]);
        box.userName = vLineSplited[6];
      
        return box;

    }
   

public:

    struct stTransferLog
    {
        string Date;
        string SourceAccountNumbr;
        string DistAccountNumbr;
        double amount;
        double SourceAccountBalance;
        double DistAccountBalance;
        string userName;
    };
 

	clsBankClient(enMode mode , string FirstName , string LastName , string Email , string Phone, string AccountNumber, string PinCode,float AccountBalance ) 
		: clsPerson(FirstName,LastName,Email,Phone)
	{
        _Mode = mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

	}

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    //void Print()
    //{
    //    cout << "\nClient Card:";
    //    cout << "\n___________________";
    //    cout << "\nFirstName   : " << FirstName;
    //    cout << "\nLastName    : " << LastName;
    //    cout << "\nFull Name   : " << FullName();
    //    cout << "\nEmail       : " << Email;
    //    cout << "\nPhone       : " << Phone;
    //    cout << "\nAcc. Number : " << _AccountNumber;
    //    cout << "\nPassword    : " << _PinCode;
    //    cout << "\nBalance     : " << _AccountBalance;
    //    cout << "\n___________________\n";

    //}

    static clsBankClient Find(string AccountNumber)
    {
        


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            //---------------------------------------------------------
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();
            //---------------------------------------------------------
        }

        return _GetEmptyClientObject();

    }

    static clsBankClient Find(string AccountNumber , string PinCode)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            //---------------------------------------------------------
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();
            //---------------------------------------------------------
        }

        return _GetEmptyClientObject();

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient client1 = clsBankClient::Find(AccountNumber);

        return(!client1.IsEmpty());
       
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case clsBankClient::EmptyMode:
            return enSaveResults::svFaildEmptyObject;
            break;
        case clsBankClient::UpdateMode:
            // You Have to put update function here.
            _Update();
            return enSaveResults::svSucceeded;
            break;

        case clsBankClient::AddNewMode:

             if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
      
        }
    }

    static clsBankClient GetNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "" , 0);
    }

    bool SetMarkedForDeleted()
    {
        return _MarkedForDelete;
    }

    bool DeleteCLient()
    {
        vector <clsBankClient> client = _LoadClientsDataFromFile();

        for (clsBankClient& C : client)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;

                // if you puts ( _MarkedForDelete = true; ) this meaning that you only save the value on the memory copy "*this"
                // so you have to save it inside the vector ( c._MarkedForDelete = true; )
            }
        }
        _SaveCleintsDataToFile(client);

       *this = _GetEmptyClientObject();


        return true;

    }

    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount)
    {

        if (Amount > AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
       
    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

        for (clsBankClient &Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }

    bool Transfer(float Amount, clsBankClient& DestinationClient)
    {
        if (Amount > AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);

        _TransferRegisterLog(DestinationClient, Amount);
        return true;
    }

    static vector <stTransferLog> GetTransferLogList()
    {
        fstream myfile;

        stTransferLog StoreOneStructure;
        vector <stTransferLog> vStoreManyStructure;
        string line = "";



        myfile.open("TransferRegister.txt", ios::in);

        if (myfile.is_open())
        {

            while (getline(myfile, line))  
            {
                //here function to convert from file to structure
                StoreOneStructure = _ConvertTransferLogLineToRecord(line);
                vStoreManyStructure.push_back(StoreOneStructure);
            }
           
            myfile.close();
        }

        return vStoreManyStructure; // here we return vector of structure
    }


};

