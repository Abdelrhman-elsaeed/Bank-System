#pragma once
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h";
#include "clsScreen.h";
#include "Global.h";



using namespace std;



class clsLoginScreen : protected clsScreen
{

protected:

	static bool _Login()
	{
		bool LoginFailed = false;
		string password, username;

		short FaildCount = 0 ;

		

		do
		{

			

			cout << "Please Enter User Name\n";
			cin >> username;

			cout << "Please Enter Password\n";
			cin >> password;

			CurrentUser = clsUser::Find(username, password);
			LoginFailed = CurrentUser.IsEmpty();


			if (LoginFailed ==true)
			{
				
				cout << "\nInvalid Username/Password!\n\n";
				FaildCount++;
				cout << "You Have " << 3 - FaildCount << " Trails " << endl;

			}

			if (FaildCount == 3)
			{

				cout << "You Are Locked After 3 trials \n";
				return false;


			}


		} while (LoginFailed == true);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenueScreen(); // instead of we puts it directly on the main function 
		return true;

	}


public:

	static bool ShowLoginScreen()
	{
		 system("cls");
		_DrawScreenHeader("\t  Login Screen");
		 return _Login();
	}
	


};

