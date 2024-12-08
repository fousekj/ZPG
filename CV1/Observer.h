#pragma once

class Camera;
class PointLight;
class SpotLight;
class DirectionalLight;

#define POINT_LIGHT 0
#define SPOT_LIGHT 1
#define DIRECTIONAL_LIGHT 2

/**
* @brief Observer class
 *
 * Observer class is an abstract class that is used to update the objects in the scene
 * when the camera or light is moved.
 *
 * @author Jiøí Fousek FOU0027
*/

class Observer {
public:
    virtual void update(Camera& camera) = 0;
    virtual void update(PointLight& light, int light_id = 0) = 0;
	virtual void update(SpotLight& light, int light_id = 0) = 0;
	virtual void update(DirectionalLight& light, int light_id = 0) = 0;
};