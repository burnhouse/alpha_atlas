#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QPushButton>
#include <QGraphicsView>
#include <QtGui>
#include <QString>
#include "atlas.h"
#include "atlas_i.h"
#include <divers.cpp>
#include <fstream>
using namespace cv;
using namespace std;
Mat src_gray;



atlas thresh_callback(Mat &src,int nb,atlas *a, void* )
{


    int thresh = 250;

  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  //![threshold]
  /// Detect edges using Threshold
  threshold( src, threshold_output, thresh, 255, THRESH_BINARY );
  //![threshold]
cout<<"ok";
  //![findContours]
  /// Find contours
  findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
  //![findContours]
cout<<"ok";
  /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly( contours.size() );
  vector<Rect> boundRect( contours.size() );
  vector<Point2f>center( contours.size() );
  vector<float>radius( contours.size() );
cout<<"ok";
  //![al lthework]
  for( size_t i = 0; i < contours.size(); i++ )
  {
    approxPolyDP( Mat(contours[i]), contours_poly[i], 5, true );
    boundRect[i] = boundingRect( Mat(contours_poly[i]) );
 minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
  }


cout<<"ok";
vector<Rect> boundRect2;
a->add_image(boundRect);
boundRect2=a->Get();

  return *a;
}

atlas thresh_callback_view(Mat &src,int nb,atlas *a2, void* )
{
    atlas a(*a2);
    int thresh = 100;
    int max_thresh = 255;
    RNG rng(12345);
  Mat threshold_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  //![threshold]
  /// Detect edges using Threshold
  threshold( src, threshold_output, thresh, 255, THRESH_BINARY );
  //![threshold]

  //![findContours]
  /// Find contours
  findContours( threshold_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );
  //![findContours]

  /// Approximate contours to polygons + get bounding rects and circles
  vector<vector<Point> > contours_poly( contours.size() );
  vector<Rect> boundRect( contours.size() );
  vector<Point2f>center( contours.size() );
  vector<float>radius( contours.size() );
cout<<"ok";
  //![al lthework]
  for( size_t i = 0; i < contours.size(); i++ )
  {
    approxPolyDP( Mat(contours[i]), contours_poly[i], 5, true );
    boundRect[i] = boundingRect( Mat(contours_poly[i]) );
 minEnclosingCircle( (Mat)contours_poly[i], center[i], radius[i] );
  }
  //![allthework]
int rows = src.rows;
int cols = src.cols;

cout<<"ok";
vector<Rect> boundRect2;
//atlas a(cols,rows,nb);
a.add_image(boundRect);
boundRect2=a.Get();
  //![zeroMat]
  /// Draw polygonal contour + bonding rects + circles
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  //![zeroMat]
Mat subb;
string s;
/*for(int ii=0;ii<boundRect2.size();ii++){
    Mat subb(src,boundRect2[ii]);
    imshow("ee",subb);waitKey(0);
}*/
  //![forContour]
  for( size_t i = 0; i< contours.size(); i++ )
  {
   Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
 //drawContours( drawing, contours_poly, (int)i, color, 1, 8, vector<Vec4i>(), 0, Point() );
    rectangle( drawing, boundRect2[i].tl(), boundRect2[i].br(), color, 2, 8, 0 );
 // circle( drawing, center[i], (int)radius[i], color, 2, 8, 0 );
  }
  //![forContour]

  //![showDrawings]
  /// Show in a window
  namedWindow( "Contours", WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
  //![showDrawings]
  return a;
}







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
        {

        }

void MainWindow::vue(){
    int index_image=atlas_->Get_image(index);
    cvtColor( src[index_image-1], src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    thresh_callback_view(src_gray,nbl,atlas_,0);


}

void MainWindow::init(bool b){
    //open the image file
    QString ll=QFileDialog::getOpenFileName( );
        src2=Mat(imread(ll.toStdString(), IMREAD_COLOR ));
    //set to a opencv mat
    src.push_back( src2);
    nb_image=1;
cout<<src[0].rows;
    //create a empty atlas
    if(b){
        atlas_=new atlas(src[0].rows,src[0].cols,nbl);//if the tickbox is on create a alphabet atlas
    }
    else{
       atlas_=new atlas_i(src[0].rows,src[0].cols,nbl);//else regular, just bounding the pictures by rectangles
    }

    //get the boundings rect with the thesk call function
    cvtColor( (src2), src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    thresh_callback(src_gray, nbl,atlas_, 0 );

            //connect the slots to buttons
            index=1;
            ui->setupUi(this);
            QObject::connect(ui->view, SIGNAL(clicked()), this,  SLOT(vue()));
            QObject::connect(ui->previous, SIGNAL(clicked()), this,  SLOT(im_prev()));
            QObject::connect(ui->save, SIGNAL(clicked()), this,  SLOT(save()));
            QObject::connect(ui->next, SIGNAL(clicked()), this,  SLOT(im_suiv()));
            QObject::connect(ui->new_2, SIGNAL(clicked()), this,  SLOT(new_img()));
            set_image_contour(src[0]);
}
/************************************************************
 * New image added
 * */

void MainWindow::new_img(){
    //open the image file
    QString ll=QFileDialog::getOpenFileName( );

    //set to a opencv mat
    src.push_back(Mat(imread(ll.toStdString(), IMREAD_COLOR )));
    nb_image+=1;

    //get the boundings rect with the thesk call function
    cvtColor( src[nb_image-1], src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    thresh_callback(src_gray, nbl,atlas_, 0 );
}


/************************************
 * Save the atlas
 *
*/
void MainWindow::save(){
       QString filename = QFileDialog::getSaveFileName();
       ofstream fichier(filename.toStdString().c_str(), ios::out);  // on ouvre le fichier en lecture
              if(fichier)
              {

              }
              else  {
                      cerr << "Impossible d'ouvrir le fichier !" << endl;}
         fichier<<atlas_->get_text();
         fichier.close();
}





/************************************
 * go to next texture
 *
*/
 void MainWindow::im_suiv(){
     if(!ui->texture_name->toPlainText().isEmpty()){
            atlas_->set_nom((ui->texture_name->toPlainText().toStdString()),index);
            ui->texture_name->clear();
     }

    index+=1;
    if(index==atlas_->Get().size()){
        index-=1;
    }

    //show the name of the texture if already set
    ui->save_name->setText(QString::fromStdString(atlas_->get_nom(index)));

    //make a subimage according to the bounding
    int index_image=atlas_->Get_image(index);
    Mat subb(src[index_image-1],atlas_->Get()[index]);

     //convert cv image to qimage
    cv::Mat temp(subb.cols,subb.rows,subb.type()); // make the same cv::Mat
    cvtColor(subb, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage image= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);


    //set image to the graphic view
    QGraphicsScene *scene=new QGraphicsScene();
    QGraphicsPixmapItem *item= new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
}



 /************************************
  * go to previous texture
  *
 */

 void MainWindow::im_prev(){
     if(!ui->texture_name->toPlainText().isEmpty()){
     atlas_->set_nom((ui->texture_name->toPlainText().toStdString()),index);
     ui->texture_name->clear();
     }

    index-=1;
    if(index==0){
        index+=1;
    }

    //show the name of the texture if already set
    ui->save_name->setText(QString::fromStdString(atlas_->get_nom(index)));

    //make a subimage according to the bounding
    int index_image=atlas_->Get_image(index);
    Mat subb(src[index_image-1],atlas_->Get()[index]);

     //convert cv image to qimage
    cv::Mat temp(subb.cols,subb.rows,subb.type()); // make the same cv::Mat
    cvtColor(subb, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    QImage image= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);


    //set image to the graphic view
    QGraphicsScene *scene=new QGraphicsScene();
    QGraphicsPixmapItem *item= new QGraphicsPixmapItem(QPixmap::fromImage(image));
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
}



 /************************************
  * show the texture image in the windows
  *
 */
void MainWindow::set_image_contour(Mat sr)
    {
    //src=sr;
    //atlas_=b2;
    //make a subimage according to the bounding
    int index_image=atlas_->Get_image(index);
    Mat subb(src[index_image-1],atlas_->Get()[index]);

    //show the name of the texture if already set
    ui->save_name->setText(QString::fromStdString(atlas_->get_nom(index)));


        //convert cv image to qimage
        cv::Mat temp(subb.cols,subb.rows,subb.type()); // make the same cv::Mat
        cvtColor(subb, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
        QImage image= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);

        //set image to the graphic view
        QGraphicsScene *scene=new QGraphicsScene();
        QGraphicsPixmapItem *item= new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        ui->graphicsView->setScene(scene);

}





/************************************
 * convert opencv image to Qimage
 *
*/
QImage  MainWindow::Mat2QImage(cv::Mat const& ss)
{
     cv::Mat temp(ss.cols,ss.rows,ss.type()); // make the same cv::Mat
     cvtColor(ss, temp,CV_BGR2RGB); // cvtColor Makes a copt, that what i need
     QImage dest= QImage((uchar*) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
     return dest;
}





MainWindow::~MainWindow()
{
    delete ui;delete atlas_;
}

