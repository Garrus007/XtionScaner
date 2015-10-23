#pragma once

/*
���� ������ ���������� ������ ����� ��� ��������� ����� �������������
���� � ����������.

*/

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "Pipeline/AbstractPipelineStage.h"
#include "Pipeline/AbstractPipelineData.h"
#include "Pipeline/PipelineCloudData.h"

class SmoothFilter:AbstractPipelineStage
{
public:



	//������� ������������ � �������� �������
	SmoothFilter(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);

	//������ ��������� �����������
	void SetSmooth(int neighbours, float smooth_param);

private:
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
	int neighbours;
	float smooth_param;
};