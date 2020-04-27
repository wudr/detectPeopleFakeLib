#include "tfl_detectPeople.h"

using namespace TFL;
using namespace PLD;

extern "C" TFL_DLL DetectPeole* CreateInstance();
extern "C" TFL_DLL void DisposeInstance(DetectPeole * pInstance);
extern "C" TFL_DLL TFL_RESULT ExcuteWrapper(DetectPeole* pInstance, UINT_16* inputInitDepthData, UINT_16 inputCameraAngle, UINT_16 inputPeopleNumberMax, UINT_16* inputDepthData);
extern "C" TFL_DLL TFL_RESULT GetGroundCloudWrapper(DetectPeole* pInstance, TFL_PointXYZ** outputGetGroundPlaneCloud, size_t* size);
extern "C" TFL_DLL TFL_RESULT GetPeopleDataWrapper(DetectPeole* pInstance, TFL_PointXYZ*** outputGetPeopleData, TFL_PointXYZ** outputheadPoints, float** outputheights, size_t* humanNum, size_t** pointNum);