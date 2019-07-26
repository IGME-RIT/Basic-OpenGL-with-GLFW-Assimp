/*
Title: Object Loading
File Name: fpsController.cpp
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

#include "fpsController.h"

FPSController::FPSController()
{
    m_transform = Transform3D();
}

FPSController::~FPSController()
{
}

Transform3D FPSController::GetTransform()
{
    return m_transform;
}

void FPSController::Update(GLFWwindow* window, glm::vec2 viewportDimensions, glm::vec2 mousePosition, float deltaTime)
{
    // Get the distance from the center of the screen that the mouse has moved
    glm::vec2 mouseMovement = mousePosition - (viewportDimensions / 2.0f);

    // Calculate the horizontal view angle
    float yaw = m_transform.Rotation().y;
    yaw += (int)mouseMovement.x * .001f;

    // Calculate the vertical view angle
    float pitch = m_transform.Rotation().x;
    pitch -= (int)mouseMovement.y * .001f;

    // Clamp the camera from looking up over 90 degrees.
    float halfpi = 3.1416f / 2.f;
    if (pitch < -halfpi) pitch = -halfpi;
    else if (pitch > halfpi) pitch = halfpi;

    // Set the new rotation of the camera.
    m_transform.SetRotation(glm::vec3(pitch, yaw, 0));


    // Move the cursor to the center of the screen
    glfwSetCursorPos(window, mousePosition.x - mouseMovement.x, mousePosition.y - mouseMovement.y);


    // Here we get some input, and use it to move the camera
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        m_transform.Translate(m_transform.GetForward() * 5.0f * deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        m_transform.Translate(m_transform.GetRight() * -5.0f * deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        m_transform.Translate(m_transform.GetForward() * -5.0f * deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        m_transform.Translate(m_transform.GetRight() * 5.0f * deltaTime);
    }
}
