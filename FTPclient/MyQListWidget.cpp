#include "MyQListWidget.h"





MyQListWidget::MyQListWidget(QWidget * parent)
	: QListWidget(parent)
{
	
}




void MyQListWidget::dragEnterEvent(QDragEnterEvent * event)
{
	event->accept();
}

void MyQListWidget::dragMoveEvent(QDragMoveEvent *event)
{	
	
	event->accept();
}

void MyQListWidget::dropEvent(QDropEvent *event)
{
	QString str = event->mimeData()->text();
	string temp = str.toStdString().substr(str.toStdString().find_last_of('/')+1);
	FtpTools ftp;
	ftp.UploadFile(control_socket, data_socket, str.toStdString());
	
	if (!str.isEmpty())
	{
		QListWidgetItem *item = new QListWidgetItem(this);
		QStyle::StandardPixmap sp = (QStyle::StandardPixmap)(25);

		item->setData(Qt::DecorationRole, qApp->style()->standardPixmap(sp).scaled(QSize(16, 16), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		item->setData(Qt::DisplayRole, temp.c_str());
		
		
		event->accept();
	}
}
void MyQListWidget::dragLeaveEvent(QDragLeaveEvent *event) {

	event->accept();



}


