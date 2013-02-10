#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QWidget>
#include <QMenuBar>
#include <QRect>
#include <QEvent>
#include <QLayout>
#include <QApplication>
#include <QPushButton>
#include <QDebug>

#include "menubar.hh"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //si on veut creer de nouveaux slots / signaux

private:
    MenuBar *menuBar_;
    QStatusBar *statusBar_;
    QDesktopWidget desktop_;
    QLabel *aboutWindow_;
    QStringListModel *imageListModel_;
    QWidget *centralZone_;
    int nbHittedAbout_;


public:   
    MainWindow();
    ~MainWindow();

    void makeConnection();
    void createAboutWindow();
    void createCentralWidget();
    
public slots:
    void changeStatus();
    void showAbout();
    void showFileWindow();
};

#endif // MAINWINDOW_HH
