#include "SmoothFilter.h"

//�����������
SmoothFilter::SmoothFilter(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud):AbstractPipelineStage()
{
	this->cloud = cloud;
}

//������ ��������� �����������
void SmoothFilter::SetSmooth(int neighbours, float smooth_param)
{
	
}