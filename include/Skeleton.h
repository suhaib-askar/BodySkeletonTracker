#ifndef SKELETON_H
#define SKELETON_H

#include <opencv2/highgui.hpp>
#include <list>

class Skeleton {
    private:
        int subSample;
	int width, height;

	int wC; // w clear
	int hC; // w clear
	int centerW, centerH;
	cv::Point right, left, topCenter, topRight, topLeft, bottomCenter, bottomRight, bottomLeft;
	cv::Point maxRight, maxLeft;
	cv::Point maxTopCenter,    maxTopRight,    maxTopLeft;
	cv::Point maxBottomCenter, maxBottomRight, maxBottomLeft;
	cv::Point rightHand, rightElbow, rightShoulder;
	cv::Point leftHand,  leftElbow,  leftShoulder;
	cv::Point head;

	// afastamento
	int afa;

    public:
	Skeleton(int width, int height, int subSample);
	void initialize();
	void locateMaximus(cv::Mat * frame);
	void locateShoulders(cv::Mat * frame);
	void locateMainPoints(cv::Mat &frame);
	void zeraMaximus();
	void setMaximus();
	void drawMarkers(cv::Mat &frame);
	void removeLixo(cv::Mat *frame, int cc);
	void removeSmallsRegions(cv::Mat * frame);
	void drawOverFrame(cv::Mat * skelImg, cv::Mat * frame);
	void drawOverFrame(std::list<cv::Point> pontos, cv::Mat * frame);
	cv::Mat * skeletization(cv::Mat &binarized);
	void detectBiggerRegion(cv::Mat * frame);
	void clearRegion(unsigned char * frame, int x, int y);
	void getSizeRegion(unsigned char * frame, int x, int y, int *quant);
	cv::Point mediaPoint(cv::Mat * frame);
	std::vector<cv::Point> detectaRetas(cv::Mat * skeleton, bool right);
	std::list<cv::Point> getSkeletonBraco(cv::Mat * skeleton, bool right);
};


#endif // SKELETON_H
