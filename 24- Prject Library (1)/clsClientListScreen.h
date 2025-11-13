#pragma once

#include <iostream>
#include <iomanip>

#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsScreen.h";



using namespace std;


class clsClientListScreen : protected clsScreen
{

private :  

    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(30) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }

    

public:

   static void PrintCLientsList()
{
       if (!CheckAccessRights(clsUser::enPermissions::pListClients))
       {
           return;
       }

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    clsScreen::_DrawScreenHeader("Client List", to_string(vClients.size()) + " Client(s).");

   
    cout << "\n___________________________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(30) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n___________________________________________________________________";
    cout << "_________________________________________\n" << endl;


    if (vClients.size()==0)
    {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else
    {
        for (clsBankClient& C : vClients)
        {
            PrintClientRecordLine(C);
            cout << endl;
        }
    }

}



};

