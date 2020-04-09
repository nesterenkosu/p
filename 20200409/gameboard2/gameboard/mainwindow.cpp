#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *w = new QWidget();
    w->setLayout(ui->verticalLayout);
    this->setCentralWidget(w);
    is_first=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qint32 h = ui->le_H->text().toInt();
    qint32 w = ui->le_W->text().toInt();


    QPushButton *button;

    if(is_first!=1) {
        delete(grid);
    }

    grid = new QGridLayout();
    grid->setSpacing(0);

    for(qint32 i=0;i<h;i++)
        for(qint32 j=0;j<w;j++){
            button=new QPushButton(" ",this);
            button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
            grid->addWidget(button,i,j);
            connect(button,SIGNAL(clicked()),this,SLOT(on_gameboard_clicked()));
        }
    ui->verticalLayout->addLayout(grid);

    is_first= 0;
}

void MainWindow::on_gameboard_clicked(){
    ((QPushButton* )QObject::sender())->setText("*");
}
