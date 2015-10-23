#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/PolygonMesh.h>

#include <pcl/surface/organized_fast_mesh.h>

// TODO ����� ������ ���������� ������ �����, �������� ��� ����������������
class PolygonMeshBuilder
{
	//param{in} cloud - organized point cloud
	//param{out} mesh - PolygonMesh
	static void build(const pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, pcl::PolygonMesh & mesh);
};
