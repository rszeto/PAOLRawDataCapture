#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "choosecamerawidget.h"
#include "capturewidget.h"

namespace Ui {
class MainWindow;
}

using namespace cv;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onStartCapture();
    void onStopCapture();

private:
    Ui::MainWindow *ui;
    ChooseCameraWidget* chooseWidget;
    CaptureWidget* captureWidget;
};

#endif // MAINWINDOW_H
