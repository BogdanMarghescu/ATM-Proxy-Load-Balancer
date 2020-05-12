#include "ServerList.h"

ServerList::ServerList(const string& request) : serverList()
{
	stringstream req(request);
	string type;
	req >> type;
	if (type == "INFO")
	{
		string ip;
		bool stat;
		int hits;
		float load;
		while (req >> ip >> stat >> load >> hits)
		{
			Server sv(ip, stat, load, hits);
			serverList.push_back(sv);
		}
	}
}

void ServerList::updateServerList(const string& request)
{
	serverList.clear();
	stringstream req(request);
	string type;
	req >> type;
	if (type == "INFO")
	{
		string ip;
		bool stat;
		int hits;
		float load;
		while (req >> ip >> stat >> load >> hits)
		{
			Server sv(ip, stat, load, hits);
			serverList.push_back(sv);
		}
	}
}

void ServerList::print(QTableWidget* table)	
{
	string statusType[] = { "Down", "Up" };
	table->clearContents();
	table->setRowCount(0);
	for (const auto& server : serverList)
	{
		table->insertRow(table->rowCount());
		int rowcount = table->rowCount() - 1;

		QTableWidgetItem* ipAdress = new QTableWidgetItem(QString::fromStdString(server.getIPAdress()));
		ipAdress->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		table->setItem(rowcount, IPAdress, ipAdress);

		QTableWidgetItem* status = new QTableWidgetItem(QString::fromStdString(statusType[server.getStatus()]));
		status->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		table->setItem(rowcount, Status, status);

		QTableWidgetItem* load = new QTableWidgetItem(QString::number(server.getLoad()) + "%");
		load->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		table->setItem(rowcount, Load, load);

		QTableWidgetItem* hits = new QTableWidgetItem(QString::number(server.getHits()));
		hits->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
		table->setItem(rowcount, Hits, hits);
	}
}