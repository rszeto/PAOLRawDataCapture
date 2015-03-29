#ifndef CHOOSECAMERAWIDGET_H
#define CHOOSECAMERAWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <string>
#include <cstdio>
#include <vector>
#include <cassert>
#include <opencv2/highgui/highgui.hpp>
#include "qtutil.h"

using namespace std;
using namespace cv;

namespace Ui {
class ChooseCameraWidget;
}

class ChooseCameraWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseCameraWidget(QWidget *parent = 0);
    ~ChooseCameraWidget();

    int getCurrentCamNum();
    string getSaveLocation();

signals:
    void startCapture();

private slots:
    void updateFeed();
    void on_captureButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private:
    Ui::ChooseCameraWidget *ui;
    vector<int> connectedCamNums;
    int connectedCamIndex;
    VideoCapture cam;
    QTimer timer;

    vector<int> findConnectedWebcams();
    void updateConnectedCamIndex(int diff);
};

#endif // CHOOSECAMERAWIDGET_H
