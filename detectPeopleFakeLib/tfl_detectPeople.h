#pragma once
#include "tfl_types.h"

typedef unsigned short UINT_16;

namespace TFL {
	namespace PLD {

		//This is Class For treat People Data
		struct TFL_DLL TFL_Human
		{
			vector<TFL_PointXYZ> mPeoplePointCloud;
			TFL_PointXYZ mHeadPoint;
			float mHeight;
			TFL_Human::TFL_Human();
		};

		class TFL_DLL DetectPeole {
		public:
			//Base - Constructor (void)
			DetectPeole();

			TFL_RESULT Excute(UINT_16* inputInitDepthData, UINT_16 inputCameraAngle, UINT_16 inputPeopleNumberMax, UINT_16* inputDepthData);

			//Get ground plane point cloud
			TFL_RESULT GetGroundCloud(TFL_PointCloud& outputGetGroundPlaneCloud);

			//Get people point cloud
			TFL_RESULT GetPeopleData(vector<TFL_Human>& outputGetPeopleData);
		};

	}
}