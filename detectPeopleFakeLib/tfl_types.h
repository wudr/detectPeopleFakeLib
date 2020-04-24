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

	//This is Class For treat PointsCloud With XYZ
	//Field has Points by std::vector
	struct TFL_DLL TFL_PointCloud
	{
	private:
		//Variable to save Points
		vector<TFL_PointXYZ> mPoints;
	public:
		//Base - Constructor (void)
		TFL_PointCloud();

		//Copy from others - Constructor (TFL_PointCloud&)
		TFL_PointCloud(TFL_PointCloud* pointCloud);

		//Destructor
		//virtual ~TFL_PointCloud();


		//Push Back at vector
		void PushBack(TFL_PointXYZ* point);

		//Return point at index
		TFL_PointXYZ At(int idx);

		//Return size of points
		int Size();

		//Return Points by vector
		std::vector<TFL_PointXYZ>* Points();
	};

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
}

