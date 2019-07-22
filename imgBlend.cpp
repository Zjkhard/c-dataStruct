#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<highgui.h>
#include<cv.h>
using namespace cv;

#define WINDOW_NAME "���Ի��ʾ��"   //"Ϊ���ڱ��ⶨ��ĺ�"


const int g_nMaxAlphaValue = 100;  //Alpha ֵ�����ֵ
int g_nAlphaValueSlider;           //��������Ӧ�ñ���
double g_dAlphaValue;
double g_dBetaValue;

//��������ͼ��ı���
Mat g_srcImage1;
Mat g_srcImage2;
Mat g_dstImage;


//��Ӧ�������Ļص�����

void on_Trackbar(int, void*)
{
	//�����ǰalphaֵ��������ֵ�ı���
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;

	//betaֵΪ1 ��ȥalpha ��ֵ
	g_dBetaValue = (1.0 - g_dAlphaValue);
	//����alpha �� beta ֵ�������Ի��
	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
	//��ʾЧ��ͼ
	imshow(WINDOW_NAME,g_dstImage);
}




void example()
{

	//����ͼ����
	Mat  image = imread("3.jpg", 199);
	Mat  logo = imread("2.jpg");
	Mat dst;

	namedWindow("[3]ԭʼͼ");
	imshow("[3]ԭʼͼ", image);

	namedWindow("[2]logoͼ");
	imshow("[2]logoͼ", logo);


	//����һ��Mat���� ���ڴ��ͼ���ROI
	Mat imageROI;
	//����һ
	//imageROI = image(Rect(800, 350, logo.cols, logo.rows));

	//������
	//imageROI = image(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));

	//��logo�ӵ�ԭͼ
	addWeighted(logo, 0.8, image, 0.4, 0.0, dst);

	//��ʾ���
	//namedWindow("ԭ��+logoͼ",1);
	imshow("ԭ��+logoͼ", dst);

	//imwrite("��imwrite���ɵ�ͼƬ.jpg", image);
}


int main()
{
	//��һ����Ƭ��ڶ�����Ƭ��СӦһ��
	g_srcImage1 = imread("2.jpg");
	g_srcImage2 = imread("3.jpg");

	if (!g_srcImage1.data)
	{
		printf("��һ����Ƭ��ȡ����");
		return -1;
	}
	if (!g_srcImage2.data)
	{
		printf("�ڶ�����Ƭ��ȡ����");
		return -1;
	}

	//���û�������ֵΪ70
	g_nAlphaValueSlider = 70;

	//��������
	namedWindow(WINDOW_NAME, 1);

	//�ڴ����Ĵ����д���һ���������ؼ�
	char TrackbarName[50];
	sprintf(TrackbarName, "͸��ֵ%d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);

	//����ڻص���������ʾ
	on_Trackbar(g_nAlphaValueSlider, 0);

	
	//example();
	waitKey(10000);
	return 0;
}