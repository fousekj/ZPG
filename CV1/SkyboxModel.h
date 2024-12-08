#pragma once
#include "BaseModel.h"
#include "CubeTexture.h"
#include "skycube.h"

class SkyboxModel : public BaseModel
{
private:
	CubeTexture* texture;

public:
	SkyboxModel();
	void drawModel();

};

