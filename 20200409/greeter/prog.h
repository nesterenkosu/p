#ifndef PROG_H
#define PROG_H


#include <QMainWindow>
#include <QApplication>
#include <QTextCodec>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Prog: public QMainWindow
{		
	Q_OBJECT
	public:
		QVBoxLayout *vbox;
		QLabel *title,*result;
		QLineEdit *edit;
		QPushButton *button;
		
		Prog(QWidget *parent=0);
		
	private slots:	//Обработчики событий	
		void OnClick();
		
};
#endif
