#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->move(250,10); // set position of window app
    ui->lsItemInCart->addItem("ID \t Name \t\t\t Price\t\tAmount");
}

MainWindow::~MainWindow()
{
    delete ui;
}
//close program
void MainWindow::closeEvent(QCloseEvent *event){
    QMessageBox box;
    box.setWindowTitle(tr("KidsToys"));
    box.setWindowIcon(QIcon((":/Resource/logo/logoKT.png")));
    box.setIcon(QMessageBox::Question);
    box.setText(tr("Do you really want to quit?"));
    box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    box.setDefaultButton(QMessageBox::Yes);
    box.button(QMessageBox::Yes)->setText(tr("Yes"));
    box.button(QMessageBox::Yes)->setIcon(QIcon(":/Resource/icons/ok.png"));
    box.button(QMessageBox::No)->setText(tr("No"));
    box.button(QMessageBox::No)->setIcon(QIcon(":/Resource/icons/cancel.png"));
    int reply = box.exec();
    if (reply == QMessageBox::No){
        event->ignore();
    }
}
// Out receipt put in file .txt
void MainWindow::outPutFileText(){
    ofstream outputFile;
    Receipt r;
    Employee p;
    r.receiptNumber = rand()%(1000000000 - 1000000 + 1) + 1000000;
    p.name = ui->txtNameEmployee->text();
    r.custormerName = ui->txtNameCustomer->text();
    r.phoneNumber = ui->txtPhone->text();
    outputFile.open("SalesData.txt",ios::app);
    if(outputFile){
        outputFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        outputFile << "Receipt Number: " << r.receiptNumber << endl;
        outputFile << "Employee Name: " << p.name.toStdString() << endl;
        outputFile << "Customer Name: " << r.custormerName.toStdString() << endl;
        outputFile << "Phone Number: " << r.phoneNumber.toStdString() << endl;
        outputFile << "--------------------------------------------------------------------------------------------\n";
        outputFile <<"Number \t Id \t\t\t Name \t\t\t\t     Price\t Amount\n";
        int number = 0;
        for (int i = 0; i < v.size(); ++i) {
            if(v[i].amount > 0)
                outputFile  << ++number << "\t\t" <<v[i].id <<"\t\t\t" <<v[i].itemName << " \t\t " << v[i].itemPrice <<"$\t\t   "<<v[i].amount << endl;
            totalCount += countItem(v[i]) * v[i].amount;
        }
        outputFile << "---------------------------------------------------------------------------------------------\n";
        outputFile << "Quantity:\t\t\t\t\t\t\t\t\t\t\t\t   " << totalCount << endl;
        outputFile << "---------------------------------------------------------------------------------------------\n";
        outputFile << "Total:\t\t\t\t\t\t\t\t\t\t\t\t   " << total <<"$"<< endl;
        outputFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        outputFile << "\n";
    }
}
//Count item by id product
int MainWindow::countItem(Product item){
    int count = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i].id == item.id)
            count++;
    }
    return count;
}
//Clicked button to open index page
void MainWindow::on_btnCart_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnPayment_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_btnPayment_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnQuit_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_btnProduct_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnCart_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnQuit_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_btnProduct_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_btnCart_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnPayment_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

//Clear all data, create a new order
void MainWindow::on_btnNew_clicked()
{
    ui->lsItemInCart->clear();
    ui->txtPhone->clear();
    ui->txtNameCustomer->clear();
    ui->txtNameEmployee->clear();
    v.clear();
    total = 0;
    totalCount = 0;
    ui->stackedWidget->setCurrentIndex(0);
    ui->lbTotalBillPrice_2->setNum(0);
    ui->lbTotalPrice->setNum(0);
    ui->lbAmount1->setNum(0);
    ui->lbAmount2->setNum(0);
    ui->lbAmount3->setNum(0);
    ui->lbAmount4->setNum(0);
    ui->lbAmount5->setNum(0);
    ui->lbAmount6->setNum(0);
    ui->lbAmount7->setNum(0);
    ui->lbAmount8->setNum(0);
    ui->lbAmount9->setNum(0);
    ui->lsItemInCart->addItem("ID \t Name \t\t\t Price\t\tAmount");
}

//Cliked button to pay
void MainWindow::on_btnPay_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->lbTotalBillPrice_2->setNum(total);
}
//Clicked button to open index page
void MainWindow::on_btnBack_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnProduct_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnCart_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnPayment_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnQuit_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


// Confirm info customer and products (receipt)
void MainWindow::on_btnConfirm_2_clicked()
{
    outPutFileText();
    ui->stackedWidget->setCurrentIndex(4);
}
//Confirm products in cart
void MainWindow::addProductToCart(){
    ui->lsItemInCart->clear();
    ui->lsItemInCart->addItem("ID \t Name \t\t\t Price\t\tAmount");
    total = 0;
    string str;
    for (int i = 0; i < v.size(); ++i) {
        str = v[i].id+ "\t" + v[i].itemName + "\t\t   " + to_string(v[i].itemPrice) + "\t\t"+to_string(v[i].amount);
        if(v[i].amount > 0)
            ui->lsItemInCart->addItem(str.c_str());
        total += v[i].itemPrice * v[i].amount;
    }
    ui->lbTotalPrice->setNum(total);
}
//Clicked button have to confirm data products
void MainWindow::on_btnComplete_clicked()
{
    addProductToCart();
    ui->stackedWidget->setCurrentIndex(2);
}

//Clicked button to open index page
void MainWindow::on_btnProduct_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnProduct_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_btnHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnQuit_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_btnCart_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btnPayment_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_btnHome_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnHome_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_btnHome_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btnHome_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//Add items to data
void MainWindow::addItemToData(Product&item){
    if(v.size()==0)
        v.push_back(item);
    else{
        v.push_back(item);
        for(int i =0; i < v.size() - 1; i++){
            if(v[i].id == v.back().id){
                v.pop_back();
                item.amount = v[i].amount + 1;
                v.push_back(item);
                v.erase(v.begin() + i);
            }
        }
    }
}
//Cliked button to add product in data
void MainWindow::on_btnAdd1_clicked()
{
    Product item;
    item.id = "DR30";
    item.itemName = "Dragon Robot        ";
    item.itemPrice = 30;
    item.amount = 1;
    addItemToData(item);
    ui->lbAmount1->setNum(item.amount);
}


void MainWindow::on_btnAdd2_clicked()
{
    Product item;
    item.id = "LHC9";
    item.itemName = "Lego Heartlake City";
    item.itemPrice = 99;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount2->setNum(item.amount);
}


void MainWindow::on_btnAdd3_clicked()
{
    Product item;
    item.id = "BM20";
    item.itemName = "Barbie Myra         ";
    item.itemPrice = 20;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount3->setNum(item.amount);
}

void MainWindow::on_btnAdd4_clicked()
{
    Product item;
    item.id = "RB40";
    item.itemName = "Robot Bruno         ";
    item.itemPrice = 40;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount4->setNum(item.amount);
}


void MainWindow::on_btnAdd5_clicked()
{
    Product item;
    item.id = "LS20";
    item.itemName="Lego Spacecraft     ";
    item.itemPrice=20;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount5->setNum(item.amount);
}



void MainWindow::on_btnAdd6_clicked()
{
    Product item;
    item.id = "DZN4";
    item.itemName="Dark Zed Ninja     ";
    item.itemPrice=40;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount6->setNum(item.amount);
}


void MainWindow::on_btnAdd7_clicked()
{
    Product item;
    item.id = "MDM6";
    item.itemName="Moto Ducati Model   ";
    item.itemPrice=60;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount7->setNum(item.amount);
}


void MainWindow::on_btnAdd8_clicked()
{
    Product item;
    item.id = "STM2";
    item.itemName="Shark Teeth Model  ";
    item.itemPrice=20;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount8->setNum(item.amount);
}


void MainWindow::on_btnAdd9_clicked()
{
    Product item;
    item.id = "RB50";
    item.itemName="Robot Brachio       ";
    item.itemPrice=50;
    item.amount=1;
    addItemToData(item);
    ui->lbAmount9->setNum(item.amount);
}

//Del item
int MainWindow::delItem(string str, int itemPrice){
    int minusCount = 0;
    for (int i = 0; i < v.size(); ++i) {
        if(v[i].id == str && v[i].amount > 0){
            minusCount = --v[i].amount;
            total -= itemPrice;
            break;
        }
    }
    return minusCount;
}

//Remove Item
void MainWindow::on_btnMinus1_clicked()
{
    string str="DR30";
    int minusCount = delItem(str,30);
    ui->lbAmount1->setNum(minusCount);
}

//Sort by price
void MainWindow::on_btnSort_clicked()
{
    ui->lsItemInCart->clear();
    ui->lsItemInCart->addItem("ID \t Name \t\t\t Price\t\tAmount");
    sort(v.begin(),v.end(),[](const Product &left,const Product &right){return left.itemPrice < right.itemPrice;});
    string str;
    for (int i = 0; i < v.size(); ++i) {
        str = v[i].id+ "\t" + v[i].itemName + "\t\t   " + to_string(v[i].itemPrice) + "\t\t"+to_string(v[i].amount);
        if(v[i].amount > 0)
            ui->lsItemInCart->addItem(str.c_str());
    }
}

//Point Delete
void MainWindow::on_lsItemInCart_currentRowChanged(int currentRow)
{
    selected = currentRow;
}


void MainWindow::on_btnDel_clicked()
{
    if(selected != -1){
        QListWidgetItem*it = ui->lsItemInCart->takeItem(selected);
        delete it;
        ui->lsItemInCart->setCurrentRow(-1);
    }
}

void MainWindow::on_btnMinus2_clicked()
{
    string str="LHC9";
    int minusCount = delItem(str,99);
    ui->lbAmount2->setNum(minusCount);
}


void MainWindow::on_btnMinus3_clicked()
{
    string str="BM20";
    int minusCount = delItem(str,20);
    ui->lbAmount3->setNum(minusCount);
}


void MainWindow::on_btnMinus4_clicked()
{
    string str="RB40";
    int minusCount = delItem(str,40);
    ui->lbAmount4->setNum(minusCount);
}


void MainWindow::on_btnMinus5_clicked()
{
    string str="LS20";
    int minusCount = delItem(str,20);
    ui->lbAmount5->setNum(minusCount);
}


void MainWindow::on_btnMinus6_clicked()
{
    string str="DZN4";
    int minusCount = delItem(str,40);
    ui->lbAmount6->setNum(minusCount);
}


void MainWindow::on_btnMinus7_clicked()
{
    string str="MDM6";
    int minusCount = delItem(str,60);
    ui->lbAmount7->setNum(minusCount);
}


void MainWindow::on_btnMinus8_clicked()
{
    string str="STM2";
    int minusCount = delItem(str,20);
    ui->lbAmount8->setNum(minusCount);
}


void MainWindow::on_btnMinus9_clicked()
{
    string str="RB50";
    int minusCount = delItem(str,50);
    ui->lbAmount9->setNum(minusCount);
}


