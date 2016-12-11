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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
        {

        }

void MainWindow::init(bool b){
    //open the image file
    QString ll=QFileDialog::getOpenFileName( );
    //set to a opencv mat
    src = new Mat(imread(ll.toStdString(), IMREAD_COLOR ));
    //create a empty atlas
    if(b){
        atlas_=new atlas(src->cols,src->rows,nbl);//if the tickbox is on create a alphabet atlas
    }
    else{
       atlas_=new atlas_i(src->cols,src->rows,nbl);//else regular, just bounding the pictures by rectangles
    }

    //get the boundings rect with the thesk call function
    cvtColor( *src, src_gray, COLOR_BGR2GRAY );
    blur( src_gray, src_gray, Size(3,3) );
    thresh_callback(src_gray, nbl,atlas_, 0 );

            //connect the slots to buttons
            index=1;
            ui->setupUi(this);
            QObject::connect(ui->previous, SIGNAL(clicked()), this,  SLOT(im_prev()));
            QObject::connect(ui->save, SIGNAL(clicked()), this,  SLOT(save()));
            QObject::connect(ui->next, SIGNAL(clicked()), this,  SLOT(im_suiv()));
            QObject::connect(ui->new_2, SIGNAL(clicked()), this,  SLOT(new_img()));
            set_image_contour(src);
}


void MainWindow::new_img(){
    //open the image file
    QString ll=QFileDialog::getOpenFileName( );
    //set to a opencv mat
    src = new Mat(imread(ll.toStdString(), IMREAD_COLOR ));
    //get the boundings rect with the thesk call function
    cvtColor( *src, src_gray, COLOR_BGR2GRAY );
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



    Mat subb(*src,atlas_->Get()[index]);

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



    Mat subb(*src,atlas_->Get()[index]);

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
void MainWindow::set_image_contour(Mat *sr)
    {
    //src=sr;
    //atlas_=b2;
    Mat subb(*src,atlas_->Get()[index]);

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
