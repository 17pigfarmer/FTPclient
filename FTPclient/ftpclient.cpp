#include "ftpclient.h"
#ifndef string
#define string std::string
#endif // string



FTPclient::FTPclient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void FTPclient::on_query_button_clicked() {

	if (ftp.WSA() == 0) {
		QMessageBox::critical(0, "critical message", "WSA fail!", QMessageBox::Default, 0, 0);
		return;
	}

	//set control_sock
	control_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in server;
	string server_address = ui.ip_text->text().toStdString();
	ftp.CreateSocketAddr_in(&server,server_address,21);
	

	//connect ftpserver
	if (ftp.ConnectServer(control_socket,&server)==0) {
		QMessageBox::critical(0, "critical message", "Connect fail!", QMessageBox::Default, 0, 0);
		closesocket(control_socket);
		return;
	}
	

	//log in
	data_port = ftp.LogIn(control_socket, ui.username_text->text().toStdString(), ui.password_text->text().toStdString());
	switch(data_port) {
		case -2:
			QMessageBox::critical(0, "critical message", "Username is wrong!", QMessageBox::Default, 0, 0);
			closesocket(control_socket);
			return;
		case -1:
			QMessageBox::critical(0, "critical message", "Password is wrong!", QMessageBox::Default, 0, 0);
			closesocket(control_socket);
			return;
		case 0:
			QMessageBox::critical(0, "critical message", "PASV failed!", QMessageBox::Default, 0, 0);
			closesocket(control_socket);
			return;
		default:
			QMessageBox::information(0, "infomation", "Log in success!", QMessageBox::Default, 0, 0);
	}

	//set data_socket
	data_socket = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in data_addr;
	ftp.CreateSocketAddr_in(&data_addr, server_address,data_port);

	//connect server data port
	if (ftp.ConnectServer(data_socket, &data_addr) == 0) {
		QMessageBox::critical(0, "critical message", "Connect fail!", QMessageBox::Default, 0, 0);
		closesocket(data_socket);
		return;
	}

	//get filelist
	string filelist;
	ftp.ListFile(control_socket, data_socket, filelist);
	int filenum = count(filelist.begin(), filelist.end(), '\r');

	ui.file_list->setViewMode(QListWidget::IconMode);
	ui.file_list->setResizeMode(QListWidget::Adjust);
	ui.file_list->setMovement(QListWidget::Static);
	string temp;
	for (int i = 0; i < filenum; i++) {
		QListWidgetItem *item = new QListWidgetItem(ui.file_list);
		QStyle::StandardPixmap sp = (QStyle::StandardPixmap)(25);

		item->setData(Qt::DecorationRole, qApp->style()->standardPixmap(sp).scaled(QSize(16, 16), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		temp = filelist.substr(0, filelist.find("\r"));
		filelist.erase(0, filelist.find("\n") + 1);
		item->setData(Qt::DisplayRole, temp.c_str());
	}





}

void FTPclient::on_upload_button_clicked()
{
	
}

void FTPclient::on_download_button_clicked()
{
	string filename = ui.file_list->currentItem()->text().toStdString();
	
	ftp.DownloadFile(control_socket, data_socket,filename, ui.dir_text->text().toStdString());
}

void FTPclient::on_quit_button_clicked()
{
	ftp.CloseSocket(control_socket, data_socket);
	ui.download_button->setEnabled(false);
	ui.file_list->clear();
	ui.username_text->clear();
	ui.password_text->clear();
	ui.ip_text->clear();
}

void FTPclient::on_file_list_itemSelectionChanged()
{
	if (ui.download_button->isEnabled() == false) {
		ui.download_button->setEnabled(true);
	}
}
