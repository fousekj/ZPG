#pragma once

class Camera;
class Light;

class Observer {
public:
    virtual void update(Camera& camera) = 0;
    virtual void update(Light& light, int light_id = 0) = 0;
};