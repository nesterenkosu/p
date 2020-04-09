#include "prog.h"

Prog::Prog(QWidget *parent):QMainWindow(parent)
{	
	button=new QPushButton(tr("Нажмите на кнопку"),this);
	button->setGeometry(20,20,280,30);
	connect(button,SIGNAL(clicked()),this,SLOT(OnClick()));
}

void Prog::OnClick() {
	button->setText(tr("Поздравляем! Вы сделали это!!!"));
}



