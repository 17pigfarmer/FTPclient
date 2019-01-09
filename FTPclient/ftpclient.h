#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_ftpclient.h"
#include "FtpTools.h"

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

private slots:
	void on_query_button_clicked();
	void on_upload_button_clicked();
	void on_download_button_clicked();
	void on_quit_button_clicked();
	void on_file_list_itemSelectionChanged();
};
