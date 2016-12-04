#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPushButton>
#include <QMainWindow>
#include "atlas.h"
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
      explicit MainWindow(QWidget *parent = 0);
      void init(bool);

      QImage Mat2QImage(cv::Mat const& );
      int nbl;
      void set_image_contour(Mat*);
       ~MainWindow();

public slots:
    void new_img();
    void save();
    void im_suiv();
    void im_prev();
private:

    QPushButton suivant;
    Ui::MainWindow *ui;
    Mat *src;
    atlas *atlas_;
    int index;
};

#endif // MAINWINDOW_H
