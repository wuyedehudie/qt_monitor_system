#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    init();
}

MainView::~MainView()
{
    delete ui;
}

void MainView::init(){
    //关闭边缘框
    this->setWindowFlags(Qt::FramelessWindowHint);
}
//关闭窗口按钮
void MainView::on_close_btn_clicked()
{
    this->close();
}


void MainView::on_minimize_clicked()
{
    this->showMinimized();
}

