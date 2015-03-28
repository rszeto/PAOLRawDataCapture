#ifndef MATTOQIMAGEUTIL_H
#define MATTOQIMAGEUTIL_H

#include <QImage>
#include <QLabel>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
class MatToQImageUtil
{
public:
    static QImage convertMatToQImage(const Mat& mat);
    static void displayMat(const Mat& mat, QLabel &location);
};

#endif // MATTOQIMAGEUTIL_H
