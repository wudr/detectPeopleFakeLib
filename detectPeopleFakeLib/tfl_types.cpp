#include "pch.h"
#include "tfl_types.h"

using namespace TFL;

TFL_PointXYZ::TFL_PointXYZ() {

}

TFL_PointXYZ::TFL_PointXYZ(float a, float b, float c) {
	x = a;
	y = b;
	z = c;
}

TFL_PointCloud::TFL_PointCloud()
{
	TFL_PointXYZ point1(5, 10, 15);
	TFL_PointXYZ point2(11, 22, 33);
	TFL_PointXYZ point3(8, 14, 21);
	mPoints.push_back(point1);
	mPoints.push_back(point2);
	mPoints.push_back(point3);
}

void TFL_PointCloud::PushBack(TFL_PointXYZ* point)
{
	mPoints.push_back(*point);
}

TFL_PointXYZ TFL_PointCloud::At(int idx)
{
	if (mPoints.size() < (size_t)idx)
	{
		throw TFL_RESULT::TFL_INDEX_OUT_OF_RANGE;
	}
	return mPoints.at(idx);
}

int TFL_PointCloud::Size()
{
	return mPoints.size();
}

vector<TFL_PointXYZ>* TFL_PointCloud::Points()
{
	return &mPoints;
}
