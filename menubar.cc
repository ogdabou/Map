#include "menubar.hh"

MenuBar::MenuBar()
{
    file_ = this->addMenu("&Fichier");

    about_ = this->addAction("&About");
    open_ = file_->addAction("&Open image");
    scan_ = file_->addAction("&Image from a scanner");
    exit_ = file_->addAction("&Exit");

    QObject::connect(exit_, SIGNAL(triggered()), qApp, SLOT(quit()));
}


void MenuBar::setExitStatus(QString status)
{
    exit_->setStatusTip(status);
}

MenuBar::~MenuBar()
{
    delete open_;
    delete about_;
    delete scan_;
    delete exit_;
    delete file_;
}
