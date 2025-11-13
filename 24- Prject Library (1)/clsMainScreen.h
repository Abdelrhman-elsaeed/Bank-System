#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";

#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsersScreen.h";
#include "Global.h";
#include "clsLoginRegisterScreen.h";
#include "clsCurrencyExchangeMainScreen.h"



using namespace std;

class clsMainScreen : protected clsScreen
{
private:

    enum _enMainMenueOptions{
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eRegister = 8, eCurrencyExxhange = 9, eExit = 10
    };

    static void _ShowAllClientsScreen()
    {
        //cout << "\nClient List Screen Will be here...\n";

        clsClientListScreen::PrintCLientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::AddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
       // cout << "\nUpdate Client Screen Will be here...\n";

        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";

        clsFindClientScreen::ShowFindClientScreen();


    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
       // cout << "\nUsers Menue Will be here...\n";

        clsManageUsers::ShowManageUsersMenue();

    }

    static void _ShowEndScreen()
    {
        //cout << "\nEnd Screen Will be here...\n";
        CurrentUser = clsUser::Find("", "");

    }

    static void _LoginRegisterScreen()
    {
        //cout << "here you will find register screen\n";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
      
    }

    static void _ShowCurrencyExchangeScreen()
    {
        //cout << "i have to puts the currency screen here and then add the sub screen of the currency \n";
        clsCurrencyExchangeMainScreen::ShowMainMenueScreen();

    }

    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\nPress any key to go back to Main Menue...\n";
        system("pause>0");

        ShowMainMenueScreen();
    }

    static short _ReadMainMenuOption()
    {
        short num;
        num = clsInputValidate::ReadIntNumberBetween(1, 10, "Please Choose Between [1] tp [10] \n");

        return num;


    }

    static void _PerfromMainMenueOption(_enMainMenueOptions option)
    {

        switch (option)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case clsMainScreen::eRegister:
            system("cls");
            _LoginRegisterScreen();
            _GoBackToMainMenue();
        case clsMainScreen::eCurrencyExxhange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
        case clsMainScreen::eExit:
            system("cls");
            _ShowEndScreen();
            break;
        default:
            break;
        }

    }

public:

	static void ShowMainMenueScreen()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("Main Menu");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromMainMenueOption((_enMainMenueOptions)_ReadMainMenuOption());

	}







};

