#include "atmproxy.h"

ATMproxy::ATMproxy(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(size());
    validateLogin();
}

string ATMproxy::getUsername()
{
	return ui.UsernameInput->text().toStdString();
}

string ATMproxy::getPassword()
{
	return ui.PasswordInput->text().toStdString();
}

void ATMproxy::validateLogin()
{
    QRegExp cred_rx("[_$@#\\w]{8,16}");
    QValidator* validator = new QRegExpValidator(cred_rx, this);
    ui.UsernameInput->setValidator(validator);
    ui.PasswordInput->setValidator(validator);
}

bool ATMproxy::validCredentials()
{
    return (ui.UsernameInput->hasAcceptableInput()) * (ui.PasswordInput->hasAcceptableInput());
}

void ATMproxy::on_LogIn_clicked()
{
    if (!validCredentials())
    {
        QMessageBox::critical(this, "Wrong Input for Username or Password", "The username and password must be between 8 and 16 characters, and can only contain alphanumeric characters, as well as characters \"_\", \"@\", \"#\", \"$\"!\n\n");
    }
    else
    {
        User::getInstance(getUsername(), getPassword());
        string credentials = "AUTH " + getUsername() + " " + getPassword();
        Client& cl = Client::getInstance();
		bool is_error;
		string type, credentialResponse;
		try
		{
			cl.startClient();
			int connectStatus = cl.connectProxy();
			if (connectStatus == 0)
			{
				string credentialResponse = cl.sendCredentials(credentials);
				stringstream resp(credentialResponse);
				resp >> type >> is_error;
				if (is_error)
				{
					User::destroyInstance();
					cl.closeClientConnections();
					Log::getInstance().write("Failed log in\n");
					throw new UserException(1);
				}
				else
				{
					this->hide();
					emit openMenu(getUsername());
				}
			}
		}
		catch (UserException* ue)
		{
			Log::getInstance().write("USER ERROR #" + to_string(ue->getCode()) + ": " + ue->getMessage() + "\n");
			QMessageBox::critical(this, "Authentication Error", ue->getError().c_str());
			delete ue;
		}
		catch (ConnectException* ce)
		{
			Log::getInstance().write("CONNECTION ERROR #" + to_string(ce->getCode()) + ": " + ce->getMessage() + "\n");
			QMessageBox::critical(nullptr, "Connection Error", ce->getError().c_str());
			delete ce;
			exit(-1);
		}
    }
}

void ATMproxy::on_Create_User_clicked()
{
    if (!validCredentials())
    {
        QMessageBox::critical(this, "Wrong Input for Username or Password", "The username and password must be between 8 and 16 characters, and can only contain alphanumeric characters, as well as characters \"_\", \"@\", \"#\", \"$\"!\n\n");
    }
    else
    {
		User::getInstance(getUsername(), getPassword());
		string credentials = "CREATE_USER " + getUsername() + " " + getPassword();
		Client& cl = Client::getInstance();
		bool is_error;
		string type, credentialResponse;
		try
		{
			cl.startClient();
			int connectStatus = cl.connectProxy();
			if (connectStatus == 0)
			{
				string credentialResponse = cl.sendCredentials(credentials);
				stringstream resp(credentialResponse);
				resp >> type >> is_error;
				if (is_error)
				{
					User::destroyInstance();
					cl.closeClientConnections();
					Log::getInstance().write("Failed user creation\n");
					throw new UserException(2);
				}
				else
				{
					this->hide();
					emit openMenu(getUsername());
				}
			}
		}
		catch (UserException* ue)
		{
			Log::getInstance().write("USER ERROR #" + to_string(ue->getCode()) + ": " + ue->getMessage() + "\n");
			QMessageBox::critical(this, "Authentication Error", ue->getError().c_str());
			delete ue;
		}
		catch (ConnectException* ce)
		{
			Log::getInstance().write("CONNECTION ERROR #" + to_string(ce->getCode()) + ": " + ce->getMessage() + "\n");
			QMessageBox::critical(nullptr, "Connection Error", ce->getError().c_str());
			delete ce;
			exit(-1);
		}
    }
}

void ATMproxy::on_Exit_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Exit ATM Proxy", "Do you want to quit ATM Proxy?", QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes)
	{
        QApplication::quit();
		Log::getInstance().write("Closing client...\n");
		Log::destroyInstance();
		Client::destroyInstance();
		Base64::destroyInstance();
	}
}

void ATMproxy::returnLoginMenu()
{
	ui.UsernameInput->clear();
	ui.PasswordInput->clear();
	show();
}