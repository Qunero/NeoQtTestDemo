#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_default_clicked();

    void on_lineEdit_testInput_textChanged(const QString &arg1);

    void on_lineEdit_validator_textChanged(const QString &arg1);

    void on_lineEdit_inputMask_textChanged(const QString &arg1);

    void on_pushButton_setValidator_clicked();

    void on_pushButton_setInputMask_clicked();

private:
    QValidator *pStrValidator;
    QString strInputMask;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
