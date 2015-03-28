#include "capturewidget.h"
#include "ui_capturewidget.h"

CaptureWidget::CaptureWidget(int devNo, string path, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaptureWidget)
{
    ui->setupUi(this);

    numImagesSaved = 0;
    savePath = path;
    devNum = devNo;

    // Initialize webcam and set widght and height
    cam = VideoCapture(devNo);
    cam.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);

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
    // Clear camera buffer to get image at current time,
    // otherwise we get a lag in the captured images
    // http://answers.opencv.org/question/29957/highguivideocapture-buffer-introducing-lag/
    for(int i = 0; i < 5; i++)
        cam >> currentFrame;
    MatToQImageUtil::displayMat(currentFrame, *ui->camFeedLabel);

    // Get current time
    time_t currentTime;
    time(&currentTime);

    // Get path to save image to
    char buffer[256];
    sprintf(buffer, "%s/cameraIn%06d-%010ld-%d.png", savePath.c_str(),
            numImagesSaved, currentTime, devNum);
    qDebug(buffer);
    // Save the current frame
    imwrite(buffer, currentFrame);

    numImagesSaved++;
}
