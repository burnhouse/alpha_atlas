#include "mainwindow.h"
#include <QApplication>
#include "dialog.h"
#include <opencv2/opencv.hpp>
#include "atlas.h"
using namespace cv;
Mat src;
int thresh2 = 100;
int max_thresh2 = 255;
RNG rng2(12345);

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);

    MainWindow w;
    w.show();
    Dialog d; d.show();
      d.set_mw(&w);

    return a.exec();
}


