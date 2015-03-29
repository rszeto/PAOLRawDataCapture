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
    // Get which camera to grab from
    int camNum = chooseWidget->getCurrentCamNum();
    string savePath = chooseWidget->getSaveLocation();
    // Strip terminating slash if it exists
    if(savePath[savePath.size()-1] == '/')
        savePath = savePath.substr(0, savePath.size()-1);

    // Clear memory used by widget
    delete chooseWidget;

    // Make save path directory if it does not exist
    string mkdirCmd = "mkdir -p \"" + savePath + "\"";
    qDebug("%s", mkdirCmd.c_str());
    system(mkdirCmd.c_str());

    // Initialize capture widget and set it as primary widget
    captureWidget = new CaptureWidget(camNum, savePath);
    connect(captureWidget, SIGNAL(stopCapture()), this, SLOT(onStopCapture()));
    setCentralWidget(captureWidget);
}

void MainWindow::onStopCapture() {
    // Clear memory used by widget
    delete captureWidget;

    // Initialize camera selection widget and set as primary widget
    chooseWidget = new ChooseCameraWidget(this);
    connect(chooseWidget, SIGNAL(startCapture()), this, SLOT(onStartCapture()));
    setCentralWidget(chooseWidget);
}


