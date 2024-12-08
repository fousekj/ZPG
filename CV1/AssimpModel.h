#pragma once
#include "BaseModel.h"
#include "Texture.h"
#include <string>

#include <SOIL.h>

#include<assimp/Importer.hpp>// C++ importerinterface
#include<assimp/scene.h>// aiSceneoutputdata structure
#include<assimp/postprocess.h>// Post processingflags

using namespace std;

struct Vertex
{
    float Position[3];
    float Normal[3];
    float Texture[2];
    float Tangent[3];
};

class AssimpModel : public BaseModel
{
private:
    GLuint ibo;
    Texture* texture;
    int indicesCount;
    void load(string fileName);

public:
	AssimpModel(string fileName, string textureFile, GLuint textureID);
	~AssimpModel();
	void drawModel();

};

