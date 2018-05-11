#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileInfoList>
#include <QDir>
#include <QDebug>
#include <QMap>
#include <QPair>
#include <QTreeView>
#include <QAbstractItemModel>
#include <QDirModel>
#include <QModelIndex>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QList>
#include "project_config.h"

namespace Ui {
class MainWindow;
}

enum BuildOrClean
{
    BUILD = 0,
    CLEAN,
    NONE
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     void AnalysisCurrentDirectoryFile(QStandardItem *item, QString root_dir,int dir_depth ,BuildOrClean options_type);
     void SetADirectoryCMakeListFile(QString current_dir, QString cmakelists_file, QList<QString> sub_lists, int dir_depth, QString lib_type_string = "STATIC");
     void GetDirecotryUnderCurrentDirectory(QString root_dir);
     void SetTree(QString dir);
     QString CreateCmakeListsFile(QString current_dir);
     void CleanCmakeListsFile(QString current_dir);

     void setProjectConfig(SProjcetConfig project_config);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

public slots:


private:
    Ui::MainWindow *ui;
//    QDirModel *dir_model;
    QStandardItemModel *dir_model;
    bool builded_flag;

    QStandardItem * root_item ;

    SProjcetConfig project_config;

};

#endif // MAINWINDOW_H
