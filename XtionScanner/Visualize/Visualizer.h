#pragma once

/*
�������� �� ������������
*/

#include "Pipeline/AbstractPipelineStage.h"
#include <pcl/visualization/pcl_visualizer.h>
#include <boost/make_shared.hpp>
#include <thread>
#include <mutex>
#include <Windows.h>

class Visualizer:AbstractPipelineStage
{
public:

	//�����������
	Visualizer();

	//����������
	~Visualizer();

	//��������� ������ �� ���������� �������
	void HandleRequest(AbstractPipelineData*);

private:

	boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;			//������������
	std::thread visualisation_thread;										//�����, � ������� �������� ����������� ���� �������������
	std::mutex visualisation_mutex;											//�������, ��� ������������� �������
	bool is_thread_closing;


	static void visualisation_func_wrapper(Visualizer* context);
	void visualisation_thread_func();
};