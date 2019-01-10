#pragma once

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QUrl>
#include <QFile>
#include <QMimeData>

#include <QListWidget>
#include "FtpTools.h"
#include "qapplication.h"


class MyQListWidget : public QListWidget
{
	Q_OBJECT
public:
	MyQListWidget(QWidget *parent = Q_NULLPTR);
	SOCKET control_socket;
	SOCKET data_socket;

protected:

	void dragEnterEvent(QDragEnterEvent * event);
	void dragMoveEvent(QDragMoveEvent * event);
	void dropEvent(QDropEvent *event);
	void dragLeaveEvent(QDragLeaveEvent * event);
};

