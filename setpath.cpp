#include "setpath.h"
#include "ui_setpath.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QDebug>


SetPath::SetPath(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SetPath)
{
    ui->setupUi(this);
}

SetPath::~SetPath()
{
    delete ui;
}


void SetPath::on_pushButton_clicked()
{
    qt_path = QFileDialog::getExistingDirectory(this,"选择目录","./",QFileDialog::ShowDirsOnly);
    if(!qt_path.isEmpty()){
        ui->lineEdit->setText(qt_path);
    }
    else{
        QMessageBox::information(this,tr("软件路径"),tr("软件路径未选择!"));
    }  //检验是否打开了文件

}

void SetPath::on_pushButton_2_clicked()
{
    software_path= QFileDialog::getOpenFileName(this,tr("选择软件路径"),"/home",tr("可执行文件(*.exe)"));//打开文件夹头文件3
    if(!software_path.isEmpty()){
        ui->lineEdit_2->setText(software_path);
    }
    else{
        QMessageBox::information(this,tr("软件路径"),tr("需要打包软件路径未选择!"));
    }  //检验是否打开了文件
}

void SetPath::on_pushButton_3_clicked()
{
    pack_path = QFileDialog::getExistingDirectory(this,"选择目录","./",QFileDialog::ShowDirsOnly);
    if(!pack_path.isEmpty()){
        ui->lineEdit_3->setText(pack_path);
    }
    else{
        QMessageBox::information(this,tr("软件路径"),tr("软件路径未选择!"));
    }  //检验是否打开了文件
}

void SetPath::on_pushButton_4_clicked()
{
    QString sourcePath = software_path;
    QString targetDir = pack_path;

    QFileInfo fileInfo(sourcePath);
    QString fileName = fileInfo.fileName();

    QDir targetFolder;
    if(!targetFolder.exists(targetDir)) {
        targetFolder.mkpath(targetDir);
    }

    QString newPath = targetDir + "/" + fileName;

    QFile::copy(sourcePath, newPath);

    if(QFile::exists(newPath)) {
        qDebug() << "Copy exe file succeeded.";
    } else {
        qDebug() << "Copy exe file failed:" ;
    }


    QFile batFile(pack_path + "\\rundeploy.bat");

    // 先创建空bat文件
    if (!batFile.open(QIODevice::WriteOnly)) {
      qDebug() << "Could not create bat file:" << batFile.errorString();
    }

    QTextStream out(&batFile);
    out << "set path=" << qt_path << "\n";
    out << "windeployqt.exe " << fileName << "\n";
    batFile.close();

    QFile batFile1(pack_path + "\\run.bat");

    // 先创建空bat文件
    if (!batFile1.open(QIODevice::WriteOnly)) {
      qDebug() << "Could not create bat file:" << batFile.errorString();
    }

    QTextStream out1(&batFile1);
    out1 << "set path=" << qt_path << "\n";
    out1 << fileName << "\n";
    batFile1.close();

}
