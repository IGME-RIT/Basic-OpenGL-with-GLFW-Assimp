/*
Title: Object Loading
File Name: shaderProgram.h
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
#include "shader.h"
#include <iostream>

// Wraps opengl shader program functionality
class ShaderProgram
{

private:
    // These shader objects wrap the functionality of loading and compiling shaders from files.
    Shader* m_vertexShader = nullptr;
    Shader* m_fragmentShader = nullptr;

    // GL index for shader program
    GLuint m_shaderProgram;

    // Keep track of if the program has been built and only build when needed
    bool m_programBuilt = false;

    // Reference Counter
    unsigned int m_refCount = 0;

public:
    ShaderProgram();
    ~ShaderProgram();
    GLuint GetGLShaderProgram();
    void AttachShader(Shader* shader);
    void Bind();
    void Unbind();
    void IncRefCount();
    void DecRefCount();
};