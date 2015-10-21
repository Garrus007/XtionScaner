#pragma once

#include "Pipeline/AbstractPipelineStage.h"
#include "Pipeline/AbstractPipelineData.h"
#include "Pipeline/PipelineCloudData.h"

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

class PointSmoothMove:AbstractPipelineStage
{

public:
	
	// ������� ����� ������ ����� ���������, ������� ����� ��������
	void SetRadius(int links);

	//�������� �����
	void MovePoint(int column, int row, pcl::PointXYZ newPosition);

public slots:
	//��������� ������ �� ���������� �������
	void HandleRequest(std::shared_ptr<AbstractPipelineData>);

private:
	int links;
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
};