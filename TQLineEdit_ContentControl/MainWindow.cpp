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
    ui->lineEdit_inputMask->setText(">HH:HH:HH:HH;_");
    ui->lineEdit_testInput->setText("12:AF:5");
    on_pushButton_setValidator_clicked();
    on_pushButton_setInputMask_clicked();
    ui->lineEdit_testInput->setFocus();
    ui->lineEdit_testResult->setText("12:AF:5:");
}

void MainWindow::on_lineEdit_testInput_textChanged(const QString &arg1)
{
    ui->lineEdit_testResult->setText(arg1);
}

void MainWindow::on_lineEdit_validator_textChanged(const QString &arg1)
{
    // set default to pushButton, so press return to set new validator
    ui->pushButton_setValidator->setDefault(true);
    ui->pushButton_setInputMask->setDefault(false);
}

void MainWindow::on_lineEdit_inputMask_textChanged(const QString &arg1)
{
    // set default to pushButton, so press return to set new inputMask
    ui->pushButton_setValidator->setDefault(false);
    ui->pushButton_setInputMask->setDefault(true);
}

void MainWindow::on_pushButton_setValidator_clicked()
{
    this->pStrValidator = new QRegExpValidator(QRegExp(ui->lineEdit_validator->text()), this);
    ui->lineEdit_testInput->setValidator(this->pStrValidator);
    ui->label_validator->setText(ui->lineEdit_validator->text());
}

void MainWindow::on_pushButton_setInputMask_clicked()
{
    ui->lineEdit_testInput->setInputMask(ui->lineEdit_inputMask->text());
    ui->label_inputMask->setText(ui->lineEdit_testInput->inputMask());
}
