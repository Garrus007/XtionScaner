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

public slots:
	//��������� ������ �� ���������� �������
	void HandleRequest(std::shared_ptr<AbstractPipelineData>);

private:

	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;				//������������
	std::shared_ptr<PipelineCloudData> cloud;								//������ ������� ���������
	bool is_cloud_changed;

	//boost::thread visualisation_thread;										//�����, � ������� �������� ����������� ���� �������������
	//std::mutex visualisation_mutex;											//�������, ��� ������������� �������
	//bool is_thread_closing;

	//static void visualisation_func_wrapper(Visualizer* context);
	//void visualisation_thread_func();
};