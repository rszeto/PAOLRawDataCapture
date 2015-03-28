#ifndef CHOOSECAMERAWIDGET_H
#define CHOOSECAMERAWIDGET_H

#include <QWidget>

namespace Ui {
class ChooseCameraWidget;
}

class ChooseCameraWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseCameraWidget(QWidget *parent = 0);
    ~ChooseCameraWidget();

signals:
    void startCapture();

private slots:
    void on_captureButton_clicked();

private:
    Ui::ChooseCameraWidget *ui;
};

#endif // CHOOSECAMERAWIDGET_H
