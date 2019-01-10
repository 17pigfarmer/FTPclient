#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_ftpclient.h"
#include "FtpTools.h"
#include <MyQListWidget.h>




class FTPclient : public QMainWindow
{
	Q_OBJECT

public:
	FTPclient(QWidget *parent = Q_NULLPTR);

private:
	Ui::FTPclientClass ui;
	SOCKET data_socket;
	SOCKET control_socket;
	int data_port;
	FtpTools ftp;

protected:



private slots:
	void on_query_button_clicked();
	void on_download_button_clicked();
	void on_quit_button_clicked();
	void on_files_itemSelectionChanged();
};
