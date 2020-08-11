#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "delegate.h"

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QStandardItem>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QVector>
#include <sstream>
#include <vector>
#include <iostream>
#include <QJsonDocument>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStandardItem>
#include <QList>
#include <QCompleter>
#include <QMouseEvent>
#include <QStyleFactory>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVector<QVector<QString>> readJson();
    void displayResults();
    void setSelectOff(){SelectAll = false;};
    void setSelectOn(){SelectAll = true;};
    QSqlDatabase mydb;
    void clearContam();
    void clearTags();
    QStandardItemModel * model1;
    bool isSubset(QString arr1[], QString arr2[], int m, int n);
    void clearDate();
    void EditDisabled();
    void updateDB();
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
//        mydb.setDatabaseName("C:\\Users\\jcabr\\OneDrive\\Documents\\seraspec-search-replace\\spec\\waveforms.db3"); //CAN NOT ADD TO RESOURCE FOLDER
        mydb.setDatabaseName("C:\\Users\\jcabr\\OneDrive\\Documents\\MEDINVENTIVE\\SeraSpec\\New folder\\waveforms.db3"); //CAN NOT ADD TO RESOURCE FOLDER
        if(!mydb.open()){
            return false;
        }
        else{
            return true;
        }
    }


    void enableEdits(bool);
    void editDB();
    QVector<QString> getEditList();
    void setTitle(int);
    void setEditList(QVector<QString> lst);
    QVector<QVector<QString>> readJson_Edit();
    void clearEdit();
private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene_;
    bool SelectAll = false;
    QVector<QString> contam_selected;
    QVector<QString> tag_selected;
    QString type_selected = "N/A";
    QString analyte_selected ="N/A";
    QString runType_selected ="N/A";
    QString acqMode_selected ="N/A";
    QString camfilter_selected = "N/A";
    QString defaultDate = "Wed Jan 1 2020";
    bool empty_;
    Delegate *mydelegate;
    QVector<QModelIndex> indexChanged;
    bool tablechanged;
    int rowCount = 50;

    QVector<QString> id_lst;
    QVector<QVector<QString>> const_selected;
    QString run_selected = "";
    QString type_selected_Edit = "";
    QString analyte_selected_Edit = "";
    QVector<QString> tag_selected_Edit;
private slots:
    void submit();
    void onTableClicked(const QModelIndex &);
    void onEditClicked();
    void addContam(QString);
    void setContamText();
    void addTag(QString);
    void setTagText();
    void on_myTable_sectionClicked(int index);
    void clearSelection();
    void addType(QString);
    void addAnalyte(QString);
    void addRunType(QString);
    void addAcqMode(QString);
    void onRowCount(QString);
    void addCameraFilter(QString);
    void DelegateEdit(QStandardItem*);
    void onOkClick();

    void onOkClicked_Edit();
    void onCancelClicked();
    void onCheckClick(bool);
    void onContamEdit();
    void addContam_Edit(QString);
    void resetContam();
    void clearContam_Edit();
    void addTag_Edit(QString);
    void setTagText_Edit();
    void clearTags_Edit();
    void addAnalyte_Edit(QString);
    void setAnalyteText_Edit();
    void addType_Edit(QString);
    void setTypeText_Edit();
    void addRun_Edit(QString);
    void setRunText_Edit();

};

#endif // MAINWINDOW_H

