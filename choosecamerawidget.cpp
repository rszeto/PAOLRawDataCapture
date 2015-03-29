#include "choosecamerawidget.h"
#include "ui_choosecamerawidget.h"

ChooseCameraWidget::ChooseCameraWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseCameraWidget)
{
    ui->setupUi(this);

    connectedCamIndex = 0;
    connectedCamNums = findConnectedWebcams();
    cam = VideoCapture(getCurrentCamNum());

    // Set "loading" message (purely for fun)
    ui->feedLabel->setText(QtUtil::randomLoadMessage());

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateFeed()));
    timer.start();
}

ChooseCameraWidget::~ChooseCameraWidget()
{
    delete ui;
}

vector<int> ChooseCameraWidget::findConnectedWebcams() {
    vector<int> connectedCamNums;
    // Open pointer to output of "ls" command
    FILE* videoList;
    if ((videoList = popen("ls /dev/video*", "r")) != NULL) {
        int bufSize = 16;
        char buf[bufSize];
        // Read each line
        while(fgets(buf, bufSize, videoList)){
            // Get the device number from the line
            int videoNum;
            assert(sscanf(buf, "/dev/video%d", &videoNum) == 1);
            // Push device number to set of available device numbers
            connectedCamNums.push_back(videoNum);
        }
        fclose(videoList);
    }
    else {
        qWarning("Failed to read list of video devices.");
    }
    return connectedCamNums;
}

void ChooseCameraWidget::updateConnectedCamIndex(int diff) {
    int numCams = connectedCamNums.size();
    connectedCamIndex = (connectedCamIndex + diff + numCams) % numCams;
    cam.open(getCurrentCamNum());

    // Prevent capture only if feed is not available
    if(cam.isOpened()) {
        ui->captureButton->setDisabled(false);
    }
    else {
        ui->feedLabel->clear();
        ui->feedLabel->setText("Feed not available for this camera. Press left or right buttons for other cameras.");
        ui->captureButton->setDisabled(true);
    }
}

int ChooseCameraWidget::getCurrentCamNum() {
    return connectedCamNums[connectedCamIndex];
}

string ChooseCameraWidget::getSaveLocation() {
    return ui->savePathText->text().toStdString();
}

void ChooseCameraWidget::updateFeed() {
    if(cam.isOpened()) {
        Mat image;
        cam >> image;
        QtUtil::displayMat(image, *ui->feedLabel);
    }
}

void ChooseCameraWidget::on_leftButton_clicked()
{
    updateConnectedCamIndex(-1);
}

void ChooseCameraWidget::on_rightButton_clicked()
{
    updateConnectedCamIndex(1);
}

void ChooseCameraWidget::on_captureButton_clicked()
{
    emit startCapture();
}
