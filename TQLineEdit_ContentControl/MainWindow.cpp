#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_default_clicked()
{
    ui->lineEdit_testResult->clear();
    ui->lineEdit_validator->setText("(?:[_\\dA-Fa-f]{2})(?::[_\\dA-Fa-f]{2}){0,3}");
    ui->lineEdit_inputMask->setText("HH:HH:HH:HH;_");
    ui->lineEdit_testInput->setText("12:34:5");
}

void MainWindow::on_lineEdit_testInput_textChanged(const QString &arg1)
{
    ui->lineEdit_testResult->setText(arg1);
}

void MainWindow::on_lineEdit_validator_textChanged(const QString &arg1)
{
    this->pStrValidator = new QRegExpValidator(QRegExp(arg1), this);
    ui->lineEdit_testInput->setValidator(this->pStrValidator);
}

void MainWindow::on_lineEdit_inputMask_textChanged(const QString &arg1)
{
    ui->lineEdit_testInput->setInputMask(arg1);
}
