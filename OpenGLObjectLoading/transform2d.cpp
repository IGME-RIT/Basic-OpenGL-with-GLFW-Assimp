/*
Title: Object Loading
File Name: transform2d.cpp
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

#include "transform2d.h"

Transform2D::Transform2D()
{
	m_scale = 1;
	m_rotation = 0;
	m_position = glm::vec2();
	m_matrix = glm::mat3();
}

float Transform2D::Scale()
{
	return m_scale;
}

float Transform2D::Rotation()
{
	return m_rotation;
}

glm::vec2 Transform2D::Position()
{
	return m_position;
}

void Transform2D::SetScale(float s)
{
	m_scale = s;
	m_matrixDirty = true;
}

void Transform2D::SetRotation(float r)
{
	m_rotation = r;
	m_matrixDirty = true;
}

void Transform2D::SetPosition(glm::vec2 v)
{
	m_position = v;
	m_matrixDirty = true;
}

void Transform2D::Rotate(float r)
{
	m_rotation += r;
	m_matrixDirty = true;
}

void Transform2D::Translate(glm::vec2 v)
{
	m_position += v;
	m_matrixDirty = true;
}

glm::mat3 Transform2D::GetMatrix()
{
	// If anything has changed, recalculate the matrix
	if (m_matrixDirty) {
		// scale
		glm::mat3 s = glm::mat3(
			m_scale, 0, 0,
			0, m_scale, 0,
			0, 0, 1
			);
		// rotation
		glm::mat3 r = glm::mat3(
			cos(m_rotation), sin(m_rotation), 0,
			-sin(m_rotation), cos(m_rotation), 0,
			0, 0, 1
			);
		// translation
		glm::mat3 t = glm::mat3(
			1, 0, 0,
			0, 1, 0,
			m_position.x, m_position.y, 1
			);

		// calculate world matrix
		m_matrix = t * r * s;

		// Alternatively, it can be calculated like this:
		/*
		m_matrix = glm::mat3(
			m_scale * cos(m_rotation), m_scale * sin(m_rotation), 0,
			m_scale * -sin(m_rotation), m_scale * cos(m_rotation), 0,
			m_position.x, m_position.y, 1
			
			);
		*/

		m_matrixDirty = false;
	}

	//return the world matrix
	return m_matrix;
}
