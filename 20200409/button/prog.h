#ifndef PROG_H
#define PROG_H


#include <QMainWindow>
#include <QApplication>
#include <QTextCodec>
#include <QPushButton>

class Prog: public QMainWindow
{		
	Q_OBJECT
	public:
		QPushButton *button;
		Prog(QWidget *parent=0);		
		
	private slots:	//Обработчики событий	
		void OnClick();
		
};
#endif
