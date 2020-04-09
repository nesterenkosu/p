#include "prog.h"

Prog::Prog(QWidget *parent):QMainWindow(parent)
{	
	vbox=new QVBoxLayout(this);
	title=new QLabel(tr("Введите ваше имя"),this);
	edit=new QLineEdit(this);
	button=new QPushButton(tr("Нажмите на кнопку"),this);
	result=new QLabel();
	
	vbox->addWidget(title);
	vbox->addWidget(edit);
	vbox->addWidget(button);
	vbox->addWidget(result);
	
	QWidget *w = new QWidget();
	w->setLayout(vbox);
	setCentralWidget(w);
	
	connect(button,SIGNAL(clicked()),this,SLOT(OnClick()));
}

void Prog::OnClick() {
	result->setText(
	    tr("Здравствуй, ")+edit->text()+"!"
	);
}


