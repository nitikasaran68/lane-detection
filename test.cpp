// #include <opencv2/core/core.hpp>
// #include <opencv2/highgui/highgui.hpp>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <fstream>
#include <iostream>
 
using namespace cv;
using namespace std;

int main( )
{    
  // Create black empty images
  //Mat image = Mat::zeros( 400, 400, CV_8UC3 );
	ifstream file;
	file.open("list.txt");

	cout << "heyy" << endl;

	string s;
	getline(file,s);
			cout << s << endl;


	cout << "heyy" << endl;

	while(!s.empty())
	{
		cout << "normal" << endl;
		cout << s << endl;
	  	Mat image;
	  	image = imread(s.c_str(), cv::IMREAD_COLOR);

	  	Point2f src_center(image.cols/2.0F, image.rows/2.0F);
		Mat rot_mat = getRotationMatrix2D(src_center, 90, 1.0);
		Mat dst;
		warpAffine(image, dst, rot_mat, image.size());
	   
	  	// Draw a circle 
	  	//cvCircle( image, Point( 200, 200 ), 32.0, Scalar( 0, 0, 255 ), 1, 8 );
	  	
	  	imwrite(s.c_str(),dst);

	  	getline(file,s);
 	}

  	return 0;
}