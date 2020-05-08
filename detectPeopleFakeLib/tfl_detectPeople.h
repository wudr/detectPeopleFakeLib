/* (C) 2020 by Brycen Group in international.
 */
#pragma once
/*------------------------------------------------------------------------------------
				 include files
 ------------------------------------------------------------------------------------*/
#include <stdint.h>
#include <vector>

typedef unsigned short UINT_16;
typedef uint32_t UINT_32;
using namespace std;

namespace TFL {
	/*------------------------------------------------------------------------------------
				Don't define "TFLIB_EXPORTS " in case of this Dll use.
	------------------------------------------------------------------------------------*/
	#ifdef DETECTPEOPLEFAKELIB_EXPORTS
	#define TFL_DLL __declspec(dllexport)
	#else
	#define TFL_DLL __declspec(dllimport)
	#endif

	/*------------------------------------------------------------------------------------
				definitions
	------------------------------------------------------------------------------------*/
	#define	TFL_FRAME_W_TB_TOF_SQ930PU_IV		640
	#define	TFL_FRAME_H_TB_TOF_SQ930PU_IV		480
	#define	TFL_FRAME_SIZE_TB_TOF_SQ930PU_IV	(TFL_FRAME_W_TB_TOF_SQ930PU_IV * TFL_FRAME_H_TB_TOF_SQ930PU_IV)

	#define TFL_FRAME_WIDTH						TFL_FRAME_W_TB_TOF_SQ930PU_IV
	#define TFL_FRAME_HEIGHT					TFL_FRAME_H_TB_TOF_SQ930PU_IV
	#define TFL_FRAME_SIZE						TFL_FRAME_SIZE_TB_TOF_SQ930PU_IV

	/*------------------------------------------------------------------------------------
			enum, struct and class
	------------------------------------------------------------------------------------*/
	///This is used as execution result from Library API.
	enum class TFL_DLL TFL_RESULT
	{
		TFL_OK = 0,
		//Related to ExpiryDate
		TFL_ERROR = 1,
		TFL_EXPIRED = 2,
		TFL_CHANGED = 3,
		TFL_ZERODAY = 4,		//This number doesn't be returned usually. 

		//Related to Basic Function			(10-)

		//Related to Measure Cube			(100-)
		TFL_NOT_ENOUGH_POINTS_IN_CLOUD = 100,
		TFL_NO_ESTIMATE_PLANAR_MODEL = 101,
		TFL_NO_SEPERATED_CLUSTERS = 102,
		TFL_NO_OBJECT_IN_CENTER = 103,
		TFL_INDEX_OUT_OF_RANGE = 104,
		TFL_NO_CLEAR_FACE = 105,
		TFL_NOT_ALLOWED_ZERO_DISTANCE = 106,
		TLF_NEED_TO_EXCUTE = 107,
		TLF_OUTPUT_PARAMETER_IS_NULL = 108,
		TFL_EXCUTE_ERR = 109,

		//Related to Detect People			(150-)
		TFL_GET_GROUND_CLOUD_ERR = 150,
		TFL_GET_PEOPLE_DATA_ERR = 151,
		TFL_NO_OBJECT = 152,
		TFL_NOT_ENOUGH_INIT_DEPTH_DATA = 153,
		TFL_NOT_ENOUGH_DEPTH_DATA = 154,
		TFL_SET_CAMERA_ANGLE_ERR = 155,
		TFL_PEOPLE_NUM_MAX_OVER = 156,
		TFL_GET_GROUND_PLANE_CLOUD_ERR = 157,
		TFL_NEED_TO_SET_BIGGER_THAN_ZERO = 158
	};

	struct TFL_DLL TFL_PointXYZ
	{
	public:
		float x;
		float y;
		float z;
		//Base - Constructor
		TFL_PointXYZ::TFL_PointXYZ();
		//Set XYZ - Constructor (float, float, float)
		TFL_PointXYZ::TFL_PointXYZ(float x, float y, float z);
	};

	typedef	std::vector<TFL_PointXYZ> TFL_PointCloud;

	namespace PLD {

		//This is Class For treat People Data
		struct TFL_DLL TFL_Human
		{
			TFL_PointCloud mPeoplePointCloud;
			TFL_PointXYZ mHeadPoint;
			float mHeight;
			TFL_Human::TFL_Human();
		};

		class TFL_DLL DetectPeole {
		public:
			//Base - Constructor (void)
			DetectPeole();

			TFL_RESULT Execute(UINT16* inputInitDepthData, UINT16 inputCameraAngle, UINT16 inputPeopleNumberMax, UINT16* inputDepthData);

			//Get ground plane point cloud
			TFL_RESULT GetGroundCloud(TFL_PointCloud& outputGetGroundPlaneCloud);

			//Get people point cloud
			TFL_RESULT GetPeopleData(vector<TFL_Human>& outputGetPeopleData);
		};

	}
}