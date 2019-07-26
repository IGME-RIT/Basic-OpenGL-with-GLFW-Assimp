/*
Title: Object Loading
File Name: transform2d.h
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


#include "glm/gtc/matrix_transform.hpp"

class Transform2D {

private:
	float m_scale;
	float m_rotation;
	glm::vec2 m_position;

	// m_matrix is only calculated if matrixDirty is true.
	bool m_matrixDirty;
	glm::mat3 m_matrix;

public:
	Transform2D();
	
	// returns the scale
	float Scale();
	// returns the rotation in radians
	float Rotation();
	// returns the position as a vec2
	glm::vec2 Position();

	// sets the scale
	void SetScale(float s);
	// sets the rotation (radians)
	void SetRotation(float r);
	// sets the position vector
	void SetPosition(glm::vec2 v);

	// increments the rotation (radians)
	void Rotate(float r);
	// increments the position vector
	void Translate(glm::vec2 v);

	glm::mat3 GetMatrix();




};