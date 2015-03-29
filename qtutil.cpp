#include "qtutil.h"

QImage QtUtil::convertMatToQImage(const Mat& mat){
    Mat display;
    //copy mask Mat to display Mat and convert from BGR to RGB format
    cvtColor(mat,display,CV_BGR2RGB);

    //convert Mat to QImage
    QImage img=QImage((const unsigned char*)(display.data),display.cols,display.rows,display.step,QImage::Format_RGB888)
            .copy();
    return img;
}

void QtUtil::displayMat(const Mat& mat, QLabel &location){
    //call method to convert Mat to QImage
    QImage img=convertMatToQImage(mat);
    //push image to display location "location"
    location.setPixmap(QPixmap::fromImage(img));
}

QString QtUtil::randomLoadMessage() {
    int numMessages = 3;
    string messages[] = {
        "Please wait, loading photons...",
        "Please wait, pondering the future of AI...",
        "Please wait, scanning classroom for threats..."
    };
    return QString::fromStdString(messages[rand() % numMessages]);
}
