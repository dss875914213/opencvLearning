#include<iostream>
#include"opencv2/core.hpp"
#include"opencv2/imgproc.hpp"
#include"opencv2/highgui.hpp"

using namespace cv;

#define window_height 10
#define window_width 10
char window_name[] = "dss";
#define NUMBER 10
#define DELAY 2

RNG rng(0xFFFFFFFF);


static Scalar randomColor(RNG& rng);
int DisplayIng_Random_Text(Mat image, char* window_name,RNG rng);
int Displaying_Big_End(Mat iamge,char * window_name,RNG rng);
int Drawing_Random_Lines(Mat image, char * window_name,RNG rng);



int main(void)
{
    Mat image = Mat::zeros(window_height, window_width,CV_8UC3);
    imshow(window_name,image);
    c = Drawing_Random_Lines(image,window_name,rng);
    if(c!=0) return 0;
    //TODO

    c = Displaying_Big_End(image,window_name,rng);    

}

int Drawing_Random_Lines(Mat image, char * window_name,RNG rng)
{
    int lineType =8;
    Point pt1,pt2;
    for(int i=0;i<NUMBER;i++)
    {
        pt1.x = rng.uniform(x_1,x_2);
        pt1.y = rng.uniform(y_1,y_2);
        pt2.x = rng.uniform(x_1,x_2);
        pt2.y = rng.uniform(y_1,y_2);

        line(image,pt1,pt2,randomColor(rng),rng.uniform(1,10),8);
        imshow(window_name,image);
        if(waitKey(DELAY)>=0)
        {
            return -1;
        }
    }
    return 0;
}

static Scalar randomColor(RNG& rng)
{
    int icolor = (unsigned) rng;
    return Scalar(icolor&255,(icolor>>8)&255,(icolor>>16)&255);
}

int DisplayIng_Random_Text(Mat image, char* window_name,RNG rng)
{
    int lineType =8;
    for(int i;i<NUMBER;i++)
    {
        Point org;
        org.x = rng.uniform(x_1,x_2);
        org.y = rng.uniform(y_1,y_2);
        putText(image,"Testing test rendering",org,rng.uniform(0,8),
        rng.uniform(0,100)*0.05+0.1,randomColor(rng),rng.uniform(1,10),lineType);

        imshow(window_name,image);
        if(waitKey(DELAY)>=0)
        {
            return -1;
        }
    }
    return 0;
}

int Displaying_Big_End(Mat image,char * window_name,RNG rng)
{
    Size textsize = getTextSize("Opencv forerver!",FONT_HERSHEY_COMPLEX,3,5,0);
    Point org((window_width-textsize.width)/2,(window_height-textsize.height)/2);
    int lineType = 8;
    Mat image2;
    for(int i=0;i<255;i+=2)
    {
        image2 = image-Scalar::all(i);
        putText(image2,"opencv forever!",org,FONT_HERSHEY_COMPLEX,3,
        Scalar(i,i,255),5,lineType);
        imshow(window_name,image2);
        if(waitKey(DELAY)>=0)
        {return -1;}
    }
    return 0;
}
