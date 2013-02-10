#ifndef MENUBAR_HH
#define MENUBAR_HH

#include <QtWidgets>
#include <QMenuBar>
#include <QAction>

class MenuBar : public QMenuBar
{
private:
    QMenu *file_;

    QAction *about_;
    QAction *scan_;
    QAction *open_;
    QAction *exit_;

public:
    MenuBar();
    ~MenuBar();

public slots:
    void setExitStatus(QString status);
};

#endif // MENUBAR_HH
