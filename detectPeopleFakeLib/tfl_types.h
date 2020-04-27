#pragma once

#ifdef DETECTPEOPLEFAKELIB_EXPORTS
#define TFL_DLL __declspec(dllexport)
#else
#define TFL_DLL __declspec(dllimport)
#endif

#include <vector>
typedef unsigned short UINT_16;
typedef unsigned char  UINT_8;

using namespace std;

namespace TFL {

	#define	TFL_FRAME_W_TB_TOF_SQ930PU_IV		640
	#define	TFL_FRAME_H_TB_TOF_SQ930PU_IV		480
	#define	TFL_FRAME_SIZE_TB_TOF_SQ930PU_IV	(TFL_FRAME_W_TB_TOF_SQ930PU_IV * TFL_FRAME_H_TB_TOF_SQ930PU_IV)

	#define TFL_FRAME_WIDTH						TFL_FRAME_W_TB_TOF_SQ930PU_IV
	#define TFL_FRAME_HEIGHT					TFL_FRAME_H_TB_TOF_SQ930PU_IV
	#define TFL_FRAME_SIZE						TFL_FRAME_SIZE_TB_TOF_SQ930PU_IV

	enum class TFL_DLL TFL_RESULT
	{
		TFL_OK = 0,
		TFL_NOT_ENOUGH_POINTS_IN_CLOUD = -1,
		TFL_NO_ESTIMATE_PLANAR_MODEL = -2,
		TFL_NO_SEPERATED_CLUSTERS = -3,
		TFL_NO_OBJECT_IN_CENTER = -4,
		TFL_INDEX_OUT_OF_RANGE = -5,
		TFL_NO_CLEAR_FACE = -6,
		TFL_NOT_ALLOWED_ZERO_DISTANCE = -7,
		TLF_NEED_TO_EXCUTE = -8,
		TLF_OUTPUT_PARAMETER_IS_NULL = -9,
		TFL_EXCUTE_ERR = -10,
		TFL_GET_GROUND_CLOUD_ERR = -11,
		TFL_GET_PEOPLE_DATA_ERR = -12,
		TFL_NO_OBJECT = -13,
		TFL_NOT_ENOUGH_INIT_DEPTH_DATA = -14,
		TFL_NOT_ENOUGH_DEPTH_DATA = -15,
		TFL_SET_CAMERA_ANGLE_ERR = -16,
		TFL_PEOPLE_NUM_MAX_OVER = -17,
		//TFL_GET_GROUND_PLANE_CLOUD_ERR = -18,
		TFL_NEED_TO_SET_BIGGER_THAN_ZERO = -19,
		TFL_DETECT_GROUND_ERR = -20,
		TFL_EXTRACT_OBJECT_ERR = -21,
		TFL_NO_PEOPLE = -22
	};

	struct TFL_DLL TFL_PointXYZ
	{
	public:
		float x;
		float y;
		float z;
		////Base - Constructor
		//TFL_PointXYZ::TFL_PointXYZ();
		////Set XYZ - Constructor (float, float, float)
		//TFL_PointXYZ::TFL_PointXYZ(float x, float y, float z);
	};

	typedef	std::vector<TFL_PointXYZ> TFL_PointCloud;

	//struct TFL_DLL TFL_PointCloud
	//{
	//	vector<TFL_PointXYZ> Points;
	//	TFL_PointCloud::TFL_PointCloud();
	//};

	//TFL_RESULT CopyPointCloud(TFL_PointCloud*, TFL_PointCloud*);


	
}

