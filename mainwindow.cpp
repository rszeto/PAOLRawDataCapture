#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chooseWidget = new ChooseCameraWidget(this);
    connect(chooseWidget, SIGNAL(startCapture()), this, SLOT(onStartCapture()));
    setCentralWidget(chooseWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartCapture() {
    delete chooseWidget;
    captureWidget = new CaptureWidget(0, "/home/paol/wboard");
    connect(captureWidget, SIGNAL(stopCapture()), this, SLOT(onStopCapture()));
    setCentralWidget(captureWidget);
}

void MainWindow::onStopCapture() {
    delete captureWidget;
    chooseWidget = new ChooseCameraWidget(this);
    connect(chooseWidget, SIGNAL(startCapture()), this, SLOT(onStartCapture()));
    setCentralWidget(chooseWidget);
}


