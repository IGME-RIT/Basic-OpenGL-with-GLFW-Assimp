/*
Title: Object Loading
File Name: shaderProgram.cpp
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
#include "shaderProgram.h"

ShaderProgram::ShaderProgram()
{
    m_shaderProgram = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_shaderProgram);

    // Decrement ref counts on shaders if this object is deleted.
    if (m_vertexShader != nullptr)
        m_vertexShader->DecRefCount();

    if (m_fragmentShader != nullptr)
        m_fragmentShader->DecRefCount();
}

GLuint ShaderProgram::GetGLShaderProgram()
{
    return m_shaderProgram;
}

void ShaderProgram::AttachShader(Shader* shader)
{
    // This will point to the pointer in this shaderprogram that is the type of our passed in shader.
    Shader** currentShader;
    switch (shader->GetGLShaderType())
    {
        case GL_VERTEX_SHADER:
            currentShader = &m_vertexShader;
            break;
        case GL_FRAGMENT_SHADER:
            currentShader = &m_fragmentShader;
            break;
        default:
            return;
    }
    // Increment the new shader ref count.
    shader->IncRefCount();

    // Check if a different shader already lives there if it does, decrement it.
    if (*currentShader != nullptr)
        (*currentShader)->DecRefCount();

    // Replace it with the new shader
    *currentShader = shader;

    // Attach the gl shader to the shader program.
    if (shader->GetGLShader() != 0)
    {
        glAttachShader(m_shaderProgram, shader->GetGLShader());
        // ShaderProgram must be rebuilt
        m_programBuilt = false;
    }
    else
    {
        // Print an error if trying to attach an uninitialized shader.
        std::cout << "Failed to attach shader: Shader not initialized." << std::endl;
    }
}

void ShaderProgram::Bind()
{
    if (!m_programBuilt)
    {
        // if the program hasn't been built, build it and get uniform data
        glLinkProgram(m_shaderProgram);
        m_programBuilt = true;
    }

    glUseProgram(m_shaderProgram);
}

void ShaderProgram::Unbind()
{
    glUseProgram(0);
}

void ShaderProgram::IncRefCount()
{
    m_refCount++;
}

void ShaderProgram::DecRefCount()
{
    m_refCount--;
    if (m_refCount == 0)
    {
        delete this;
    }
}