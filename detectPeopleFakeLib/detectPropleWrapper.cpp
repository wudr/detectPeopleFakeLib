#include "pch.h"
#include "detectPropleWrapper.h"

DetectPeole* CreateInstance() {
	return new DetectPeole();
}
 
void DisposeInstance(DetectPeole* pInstance)
{
    if (pInstance != NULL)
    {
        delete pInstance;
        pInstance = NULL;
    }
}

TFL_RESULT ExcuteWrapper(DetectPeole* pInstance, UINT_16* inputInitDepthData, UINT_16 inputCameraAngle, UINT_16 inputPeopleNumberMax, UINT_16* inputDepthData) {

    return pInstance->Excute(inputInitDepthData, inputCameraAngle, inputPeopleNumberMax, inputDepthData);
}

TFL_RESULT GetGroundCloudWrapper(DetectPeole* pInstance, TFL_PointXYZ** outputGetGroundPlaneCloud, size_t* size) {
    
    auto* items = new TFL_PointCloud();
    pInstance->GetGroundCloud(*items);
    auto GroundCloud = &items->Points;
    *outputGetGroundPlaneCloud = GroundCloud->data();
    *size = GroundCloud->size();
    return TFL_RESULT::TFL_OK;
}

TFL_RESULT GetPeopleDataWrapper(DetectPeole* pInstance, TFL_PointXYZ*** outputGetPeopleData, TFL_PointXYZ** outputheadPoints, float** outputheights, size_t* humanNum, size_t** pointNum) {

    auto humans = new vector<TFL_Human>();
    auto peoplePointClouds = new vector<TFL_PointXYZ*>();
    auto headPoints = new vector<TFL_PointXYZ>();
    auto heights = new vector<float>();
    auto pointNums = new vector<size_t>();

    pInstance->GetPeopleData(*humans);
    
    *humanNum = humans->size();
    for (size_t i = 0; i < *humanNum; ++i) {
        peoplePointClouds->push_back(humans->at(i).mPeoplePointCloud.data());
        pointNums->push_back(humans->at(i).mPeoplePointCloud.size());
        headPoints->push_back(humans->at(i).mHeadPoint);
        heights->push_back(humans->at(i).mHeight);
    }

    *outputGetPeopleData = peoplePointClouds->data();
    *outputheadPoints = headPoints->data();
    *outputheights = heights->data();
    *pointNum = pointNums->data();

    return TFL_RESULT::TFL_OK;
}