#include "pch.h"
#include "tfl_detectPeople.h"

TFL::TFL_PointXYZ::TFL_PointXYZ() {
	x = 0;
}

TFL::TFL_PointXYZ::TFL_PointXYZ(float pointX, float pointY, float pointZ) {
	x = pointX;
	y = pointY;
	z = pointZ;
}

TFL::PLD::TFL_Human::TFL_Human()
{
}

TFL::PLD::DetectPeole::DetectPeole()
{
}

TFL::TFL_RESULT TFL::PLD::DetectPeole::Excute(UINT_16* inputInitDepthData, UINT_16 inputCameraAngle, UINT_16 inputPeopleNumberMax, UINT_16* inputDepthData){

	return TFL_RESULT::TFL_OK;
}

TFL::TFL_RESULT TFL::PLD::DetectPeole::GetGroundCloud(TFL_PointCloud& outputGetGroundCloud)
{
	auto testPC = new TFL_PointCloud();
	TFL_PointXYZ point_1(1, 2, 3); 
	TFL_PointXYZ point_2(4, 5, 6);
	testPC->push_back(point_1);
	testPC->push_back(point_2);
	outputGetGroundCloud = *testPC;
	return TFL_RESULT::TFL_OK;
}

//Get people point cloud
TFL::TFL_RESULT TFL::PLD::DetectPeole::GetPeopleData(vector<TFL_Human>& oPeopleData)
{
	TFL_Human human1;
	TFL_PointXYZ headPoint1(2, 4, 8);
	human1.mHeadPoint = headPoint1;
	human1.mHeight = 168;
	TFL_PointXYZ point1(10, 15, 20);
	TFL_PointXYZ point2(25, 30, 35);
	TFL_PointXYZ point3(100, 200, 300);
	human1.mPeoplePointCloud.push_back(point1);
	human1.mPeoplePointCloud.push_back(point2);
	human1.mPeoplePointCloud.push_back(point3);
	oPeopleData.push_back(human1);
	TFL_Human human2;
	TFL_PointXYZ headPoint2(3, 6, 9);
	human2.mHeadPoint = headPoint2;
	human2.mHeight = 180;
	TFL_PointXYZ point4(40, 45, 50);
	TFL_PointXYZ point5(55, 60, 65);
	human2.mPeoplePointCloud.push_back(point4);
	human2.mPeoplePointCloud.push_back(point5);
	oPeopleData.push_back(human2);
	return TFL_RESULT::TFL_OK;
}
