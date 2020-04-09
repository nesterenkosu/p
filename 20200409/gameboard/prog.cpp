#include "prog.h"
#include <stdio.h>
#include <fcntl.h>
#include <QtDebug>

Prog::Prog(QWidget *parent):QMainWindow(parent)
{
	//qDebug() << "Hi";
	vbox = new QVBoxLayout(this);
	hbox = new QHBoxLayout(this);
	
	vbox->addLayout(hbox);
	
	lb_h = new QLabel(tr("Высота"),this);
	hbox->addWidget(lb_h);
	
	ed_h = new QLineEdit(this);
	hbox->addWidget(ed_h);
	
	lb_w = new QLabel(tr("Ширина"),this);
	hbox->addWidget(lb_w);
	
	ed_w = new QLineEdit(this);
	hbox->addWidget(ed_w);
	
	btn_go = new QPushButton(tr("Ввод"),this);
	hbox->addWidget(btn_go);
	
	/*grid=new QGridLayout(this);
	for(qint32 i=0;i<5;i++)
	    for(qint32 j=0;j<5;j++) {
		grid->addWidget(new QPushButton("",this),i,j);
		//printf("%d %d \n",i,j);
	}*/
	//b=1;
	//vbox->addLayout(grid);
	
	is_first=1;
	
	QWidget *w = new QWidget();
	w->setLayout(vbox);
	setCentralWidget(w);
	
	connect(btn_go,SIGNAL(clicked()),this,SLOT(btn_go_clicked()));
}

void Prog::btn_go_clicked() {
	//qDebug() << "Clicked";
	
	qint32 h = ed_h->text().toInt();
	qint32 w = ed_w->text().toInt();
	
	if(is_first!=1) {
	    delete(grid);
	}
	
	grid=new QGridLayout(this);
	grid->setSpacing(0);
	
	QPushButton *b;
	for(qint32 i=0;i<h;i++)
	    for(qint32 j=0;j<w;j++) {
		b=new QPushButton(" ",this);
		b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
		grid->addWidget(b,i,j);
		connect(b,SIGNAL(clicked()),this,SLOT(gameboard_clicked()));
		//printf("%d %d \n",i,j);
	    }
		//grid->addWidget(new QPushButton("",this),i,j);
	
	vbox->addLayout(grid);
	
	is_first=0;
}

void Prog::gameboard_clicked() {
    //qDebug() << "Field clicked";
    ((QPushButton*)QObject::sender())->setText("*");
}


