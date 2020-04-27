#include "pch.h"
#include "tfl_types.h"

using namespace TFL;

TFL_PointXYZ::TFL_PointXYZ() {

}

TFL_PointXYZ::TFL_PointXYZ(float pointX, float pointY, float pointZ) {
	x = pointX;
	y = pointY;
	z = pointZ;
}

TFL_RESULT CopyPointCloud(TFL_PointCloud* output, TFL_PointCloud* input){
	output->Points = input->Points;
	return TFL_RESULT::TFL_OK;
}

TFL_PointCloud::TFL_PointCloud() {
}