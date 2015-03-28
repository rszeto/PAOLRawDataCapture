#include "choosecamerawidget.h"
#include "ui_choosecamerawidget.h"

ChooseCameraWidget::ChooseCameraWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseCameraWidget)
{
    ui->setupUi(this);
}

ChooseCameraWidget::~ChooseCameraWidget()
{
    delete ui;
}

void ChooseCameraWidget::on_captureButton_clicked()
{
    emit startCapture();
}
