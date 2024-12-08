#include "Rotation.h"

/**
* @file Rotation.cpp
 *
 * @brief Rotation file with functions definitions
 *
 * This file contains functions definitions for Rotation class
 * which is used for rotation of objects
 *
 * @author Jiøí Fousek FOU0027
 *
*/

Rotation::Rotation(float angle, glm::vec3 axis)
{
    this->angle = angle;
    this->axis = axis;
}

glm::mat4 Rotation::getTransformMatrix()
{
    return glm::rotate(glm::mat4(1.0f), glm::radians(this->angle), this->axis);
}

void Rotation::updateRotation(float angle, glm::vec3 axis)
{
	this->angle = angle;
	this->axis = axis;
}
