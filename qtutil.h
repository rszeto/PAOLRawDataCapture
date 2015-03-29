#ifndef MATTOQIMAGEUTIL_H
#define MATTOQIMAGEUTIL_H

#include <QImage>
#include <QLabel>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
class QtUtil
{
public:
    static void displayMat(const Mat& mat, QLabel &location);
    static QString randomLoadMessage();

private:
    static QImage convertMatToQImage(const Mat& mat);

};

#endif // MATTOQIMAGEUTIL_H
