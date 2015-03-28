#ifndef CAPTUREWIDGET_H
#define CAPTUREWIDGET_H

#include <QWidget>
#include <QTimer>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include "mattoqimageutil.h"

namespace Ui {
class CaptureWidget;
}

using namespace std;
using namespace cv;
class CaptureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CaptureWidget(int devNo, string path, QWidget *parent = 0);
    ~CaptureWidget();

signals:
    void stopCapture();

private slots:
    void on_stopButton_clicked();
    void saveCurrentFrame();

private:
    Ui::CaptureWidget *ui;
    QTimer timer;
    int devNum;
    VideoCapture cam;
    string savePath;
};

#endif // CAPTUREWIDGET_H
