#pragma once
#include "BaseModel.h"
#include "CubeTexture.h"
#include "skycube.h"

/**
* @file SkyboxModel.h
* 
* @brief SkyboxModel class
* 
* @author Jiøí Fousek FOU0027
*/

class SkyboxModel : public BaseModel
{
private:
	CubeTexture* texture;

public:
	SkyboxModel();
	void drawModel();

};

