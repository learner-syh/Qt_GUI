#ifndef SETPATH_H
#define SETPATH_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SetPath; }
QT_END_NAMESPACE

class SetPath : public QMainWindow
{
    Q_OBJECT

public:
    SetPath(QWidget *parent = nullptr);
    ~SetPath();
private:
    QString qt_path;
    QString software_path;
    QString pack_path;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::SetPath *ui;
};
#endif // SETPATH_H
