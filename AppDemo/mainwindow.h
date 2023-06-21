#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <vector>
#include <string>
#include <QString>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    struct Product
    {
        string id;
        string itemName;
        int itemPrice;
        int amount;
    };
    struct Employee{
        QString name;
    };
    struct Receipt
    {
      int receiptNumber;
      QString custormerName, phoneNumber;
    };
private slots:
    void on_btnCart_1_clicked();

    void on_btnPayment_2_clicked();

    void on_btnPayment_1_clicked();

    void on_btnQuit_1_clicked();

    void on_btnProduct_2_clicked();

    void on_btnCart_2_clicked();

    void on_btnQuit_2_clicked();

    void on_btnProduct_4_clicked();

    void on_btnCart_4_clicked();

    void on_btnPayment_4_clicked();

    void on_btnAdd1_clicked();

    void on_btnAdd2_clicked();

    void on_btnAdd3_clicked();

    void on_btnNew_clicked();

    void on_btnPay_clicked();

    void on_btnBack_clicked();

    void on_btnProduct_5_clicked();

    void on_btnCart_5_clicked();

    void on_btnPayment_5_clicked();

    void on_btnQuit_5_clicked();

    void on_btnConfirm_2_clicked();

    void on_btnComplete_clicked();

    void on_btnProduct_1_clicked();

    void on_btnProduct_3_clicked();

    void on_btnHome_clicked();

    void on_btnQuit_3_clicked();

    void on_btnCart_3_clicked();

    void on_btnPayment_3_clicked();

    void on_btnHome_2_clicked();

    void on_btnHome_4_clicked();

    void on_btnHome_5_clicked();

    void on_btnAdd4_clicked();

    void on_btnAdd5_clicked();

    void on_btnAdd6_clicked();

    void on_btnAdd7_clicked();

    void on_btnAdd8_clicked();

    void on_btnAdd9_clicked();

    void on_btnHome_3_clicked();

    void on_btnMinus1_clicked();

    void on_lsItemInCart_currentRowChanged(int currentRow);

    void on_btnDel_clicked();

    void on_btnMinus2_clicked();

    void on_btnMinus3_clicked();

    void on_btnMinus4_clicked();

    void on_btnMinus5_clicked();

    void on_btnMinus6_clicked();

    void on_btnMinus7_clicked();

    void on_btnMinus8_clicked();

    void on_btnMinus9_clicked();

    void on_btnSort_clicked();

private:
    Ui::MainWindow *ui;
    int selected = -1;
public:
    vector<Product> v;
    vector<Product> temp;
    int total = 0;
    int totalCount = 0;

    void closeEvent(QCloseEvent *event);
    void outPutFileText();
    void addProductToCart();
    int countItem(Product item);
    void addItemToData(Product &item);
    int delItem(string str, int itemPrice);
};
#endif // MAINWINDOW_H
