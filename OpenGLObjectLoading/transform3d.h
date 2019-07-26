/*
Title: Object Loading
File Name: transform3d.h
Copyright ? 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include "glm/gtc/matrix_transform.hpp"

class Transform3D {

private:
    float m_scale;
    glm::vec3 m_rotation;
    glm::vec3 m_position;

    // m_matrix is only calculated if matrixDirty is true.
    bool m_matrixDirty;
    bool m_inverseDirty;

    glm::mat4 m_rotationMatrix;
    glm::mat4 m_matrix;
    glm::mat4 m_inverseMatrix;

public:
    Transform3D();

    // returns the scale
    float Scale();
    // returns the rotation in radians
    glm::vec3 Rotation();
    // returns the position as a vec2
    glm::vec3 Position();

    // sets the scale
    void SetScale(float s);
    // sets the rotation (radians)
    void SetRotation(glm::vec3 r);
    // sets the position vector
    void SetPosition(glm::vec3 v);

    // increments the rotation (radians)
    void RotateX(float r);
    void RotateY(float r);
    void RotateZ(float r);

    // increments the position vector
    void Translate(glm::vec3 v);

    glm::mat4 GetMatrix();
    glm::mat4 GetInverseMatrix();
    glm::vec3 GetUp();
    glm::vec3 GetForward();
    glm::vec3 GetRight();
};