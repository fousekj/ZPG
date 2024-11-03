#include "Rotation.h"

Rotation::Rotation(float angle, glm::vec3 axis)
{
    this->angle = angle;
    this->axis = axis;
}

glm::mat4 Rotation::getTransformMatrix() const
{
    return glm::rotate(glm::mat4(1.0f), glm::radians(this->angle), this->axis);
}
