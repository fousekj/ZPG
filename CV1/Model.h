#pragma once
#include "BaseModel.h"

/**
 * @file Model.h
 *
 * @brief Model.h file with functions implementations
 *
 * @author Jiøí Fousek
  **/


class Model : public BaseModel
{
public:
	Model(GLenum drawMode, const float* points, int pointsSize);
	void drawModel() override;
};

