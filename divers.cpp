#include "atlas.h"
#include "atlas_i.h"
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;



atlas thresh_callback(Mat &src,int nb,atlas *a, void* )
{int thresh = 100;
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
a->add_image(boundRect);
boundRect2=a->Get();
  //![zeroMat]
  /// Draw polygonal contour + bonding rects + circles
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  //![zeroMat]
Mat subb;
string s;
/*for(int ii=0;ii<boundRect2.size();ii++){
    Mat subb(src,boundRect2[ii]);
    imshow("ee",subb);waitKey(0);
}
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
  imshow( "Contours", drawing );*/
  //![showDrawings]
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
a->add_image(boundRect);
boundRect2=a->Get();
  //![zeroMat]
  /// Draw polygonal contour + bonding rects + circles
  Mat drawing = Mat::zeros( threshold_output.size(), CV_8UC3 );
  //![zeroMat]
Mat subb;
string s;
for(int ii=0;ii<boundRect2.size();ii++){
    Mat subb(src,boundRect2[ii]);
    imshow("ee",subb);waitKey(0);
}
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
  return *a;
}

