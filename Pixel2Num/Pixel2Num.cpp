// Pixel2Num.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
   cv::Mat m = cv::imread("./helloworld64.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    for (int row = m.rows - 1;row >= 0;row--)
    {
        unsigned __int64 num = 0;
        for (int col = 0;col < m.cols;col++)
        {
            if (m.at<uchar>(row,col)>128)
            {
                num *=2;
            }
            else
            {
                num =num*2 +1;
            }
            std::cout<<num<<std::endl;
        }

        std::cout<<"---------------------------";
//        std::cout<<num<<",";
    }
	return 0;
}

