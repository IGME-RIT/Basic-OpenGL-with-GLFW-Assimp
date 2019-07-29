Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Assimp Loader Tutorial!
Prerequesites: OBJ Loader

This utilizes the Assimp library
documentation will be written later
Go to Mesh.cpp, its really simple

When to use Assimp:
Assimp has a crazy algorithm that loads OBJs thousands of times
faster than the previous OBJ Loader tutorial. You can test this by 
loading "kitten.obj"

When not use use Assimp:
Assimp can only be used if you have the header files (.h),
library files (.lib), and dynamic link (.dll). If you want to use
Assimp on Linux, PS4, Xbox, Switch, iOS, or Android, you might need
to download the Assimp source and compile it yourself. However, the 
old tutorial works just fine on all platforms.

Make your variables
	Assimp::Importer importer;
	const aiScene* scene = NULL;
Initialize the "scene" which is the model
	scene = importer.ReadFile(filePath, aiProcessPreset_TargetRealtime_Quality);
Set your mesh to the first mesh in the scene (there's only one)
	const struct aiMesh* mesh = scene->mMeshes[0];
Copy Vertex data from Mesh to each vertex, for all vertices in the
mesh (see the first 'for' loop), then copy Index data from Mesh 
to m_indices vector (see the second 'for' loop)

The rest is the same as the previous OBJ loader
