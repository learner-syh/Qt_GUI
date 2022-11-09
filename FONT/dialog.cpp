#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->radioButtonBlack, SIGNAL(clicked()), this, SLOT(setTextColor()));
    QObject::connect(ui->radioButtonBlue, SIGNAL(clicked()), this, SLOT(setTextColor()));
    QObject::connect(ui->radioButtonRed, SIGNAL(clicked()), this, SLOT(setTextColor()));
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_checkBoxUnderline_clicked(bool checked)
{
    QFont font= ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxItalic_clicked(bool checked)
{
    QFont font= ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void Dialog::on_checkBoxBold_clicked(bool checked)
{
    QFont font= ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::setTextColor()
{
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->radioButtonBlack->isChecked()){
        plet.setColor(QPalette::Text,Qt::black);
    }else if(ui->radioButtonBlue->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue);
    }else if(ui->radioButtonRed->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }else{
        plet.setColor(QPalette::Text,Qt::black);
    }
    ui->plainTextEdit->setPalette(plet);
}

