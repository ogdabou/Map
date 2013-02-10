#include "mainwindow.hh"

MainWindow::MainWindow () : QMainWindow ()
{
    QRect screenSize = desktop_.screenGeometry();
    createAboutWindow();
    createCentralWidget();
    statusBar_ = new QStatusBar;
    menuBar_ = new MenuBar;
    this->setWindowTitle("MapBuilder");
    this->resize(screenSize.width()*3/4, screenSize.height()*3/4);
    this->setMenuBar(menuBar_);
    this->setStatusBar(statusBar_);
    makeConnection();
}

void MainWindow::makeConnection()
{
    QList<QMenu *> menuList = menuBar_->findChildren<QMenu*>();
    QList<QAction *> actionList = menuList[0]->actions();
    QAction *action = actionList[0];
    QObject::connect(action, SIGNAL(triggered()), this, SLOT(showFileWindow()));
    action = actionList[1];

    actionList = menuBar_->actions();
    action = actionList[1];
    QObject::connect(action, SIGNAL(triggered()), this, SLOT(showAbout()));

}

void MainWindow::showFileWindow()
{
    //QString dossier = QFileDialog::getExistingDirectory(this);
    QStringList fichiers = QFileDialog::getOpenFileNames(this, "Ouvrir un fichier",
                               QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    imageListModel_->setStringList(fichiers);

}

void MainWindow::changeStatus()
{
    statusBar_->showMessage("Opening file..");
}

void MainWindow::createAboutWindow()
{
    nbHittedAbout_ = 0;
    aboutWindow_ = new QLabel;
    aboutWindow_->setText("salut les copains");
    aboutWindow_->hide();
}

void MainWindow::showAbout()
{
    nbHittedAbout_ ++;
    aboutWindow_->resize(150,150);
    if (nbHittedAbout_ == 1)
        aboutWindow_->show();
    else
    {
        aboutWindow_->hide();
        nbHittedAbout_ = 0;
    }
}

void MainWindow::createCentralWidget()
{
    centralZone_ = new QWidget;
    QVBoxLayout *outerVert = new QVBoxLayout;
    QHBoxLayout *imagesFooter = new QHBoxLayout;
    QListView *imageList = new QListView;

    imageListModel_ = new QStringListModel;
    imageList->setModel(imageListModel_);
    imageList->setGeometry(0, 0, 20, 20);


    imagesFooter->setContentsMargins(5, 5, 5, 5);
    imagesFooter->addWidget(imageList);
    outerVert->addLayout(imagesFooter);

    centralZone_->setLayout(outerVert);
    this->setCentralWidget(centralZone_);
}

MainWindow::~MainWindow ()
{
    delete menuBar_;
    delete statusBar_;
}
