#include "capturewidget.h"
#include "ui_capturewidget.h"

CaptureWidget::CaptureWidget(int devNo, string path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaptureWidget)
{
    ui->setupUi(this);

    savePath = path;
    devNum = devNo;
    cam = VideoCapture(devNo);

    connect(&timer, SIGNAL(timeout()), this, SLOT(saveCurrentFrame()));
    timer.start(1000);
}

CaptureWidget::~CaptureWidget()
{
    delete ui;
}

void CaptureWidget::on_stopButton_clicked()
{
    emit stopCapture();
}

void CaptureWidget::saveCurrentFrame() {
    Mat currentFrame;
    cam >> currentFrame;
    MatToQImageUtil::displayMat(currentFrame, *ui->camFeedLabel);
}
