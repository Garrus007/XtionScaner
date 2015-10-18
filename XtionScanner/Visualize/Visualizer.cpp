#include "Visualizer.h"

Visualizer::Visualizer():AbstractPipelineStage()
{
	//������� ���� �������������
	viewer = boost::make_shared<pcl::visualization::PCLVisualizer>();
	viewer->setBackgroundColor(0, 0, 0);
	viewer->addCube(-1, 1, -1, 1, -1, 1);

	//������� �����
	is_thread_closing = false;
	visualisation_thread = std::thread(visualisation_func_wrapper, this);
}


Visualizer::~Visualizer()
{
	is_thread_closing = true;
	visualisation_thread.join();
	viewer->close();
	int a = 2 + 4;
}

//������� ������ ������� ������������
void Visualizer::visualisation_func_wrapper(Visualizer* context)
{
	context->visualisation_thread_func();
}

//������� ������, � ������� �������� ����������� ���� �������������
void Visualizer::visualisation_thread_func()
{

	while (!viewer->wasStopped() && !is_thread_closing) 
	{
		visualisation_mutex.lock();
		//viewer->spinOnce(100);
		visualisation_mutex.unlock();
	}
}

//��������� ������ �� ���������� �������
void Visualizer::HandleRequest(AbstractPipelineData *)
{
}