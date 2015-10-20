#pragma once

/*
�������� �� ������������
*/

#include "Pipeline/AbstractPipelineStage.h"
#include "Pipeline/PipelineCloudData.h"

#include <pcl/visualization/pcl_visualizer.h>
#include <boost/make_shared.hpp>
//#include <thread>
//#include <mutex>
//#include <boost/thread.hpp>

#include <memory>

class Visualizer:public AbstractPipelineStage
{
public:

	//�����������
	Visualizer();

	//����������
	~Visualizer();

	void StartVisualizer();
	void setCutSize(float x_min, float x_max, float y_min, float y_max, float z_min, float z_max);

public slots:
	//��������� ������ �� ���������� �������
	void HandleRequest(std::shared_ptr<AbstractPipelineData>);

private:

	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;				//������������
	std::shared_ptr<PipelineCloudData> cloud;									//������ ������� ���������
	bool is_cloud_changed;

	float x_min, x_max, y_min, y_max, z_min, z_max;
	pcl::PointCloud < pcl::PointXYZRGB>::Ptr cube;
	bool is_cube_updated = false;
	void init_cube();

	//boost::thread visualisation_thread;										//�����, � ������� �������� ����������� ���� �������������
	//std::mutex visualisation_mutex;											//�������, ��� ������������� �������
	//bool is_thread_closing;

	//static void visualisation_func_wrapper(Visualizer* context);
	//void visualisation_thread_func();
};