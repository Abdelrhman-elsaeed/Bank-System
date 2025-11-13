#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";


using namespace std;


class clsUpdateClientScreen : protected clsScreen
{

private:

    static void _Print(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.FirstName;
        cout << "\nLastName    : " << client.LastName;
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.Email;
        cout << "\nPhone       : " << client.Phone;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.PinCode;
        cout << "\nBalance     : " << client.AccountBalance;
        cout << "\n___________________\n";

    }

    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }
public:

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        string AccountNumber = "";

        clsScreen::_DrawScreenHeader("Update CLient");

        cout << "Please Enter Your Account Number \n";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Can't find this account Number please enter another one\n ";
            AccountNumber = clsInputValidate::ReadString();

        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _Print(Client);

        cout << "\n\nUpdate Client Info:";
        cout << "\n____________________\n";

        _ReadClientInfo(Client);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client.Save(); // inside it will update or not after i read the new data from the user


        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _Print(Client);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }

    }



};

