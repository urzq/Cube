#include <vector>
#include <iostream>

#include "Graphics/Renderer.h"
#include "Graphics/Light.h"
#include "Graphics/Camera.h"

#include "Input/InputManager.h"
#include "Shader/ShaderProgram.h"

#include "Core/Clock.h"
#include "Core/Color.h"
#include "Core/ServiceLocator.h"

#include "Scene/Scene.h"

/* TODO LIST:
	Indexes.
	Add some movement to the pieces :)
	Remove par_shape, and load basic models from obj (cube, sphere etc.)
	Smarted handling of textures in renderer.cpp
	Easier binding between vertexbuffer and shader (based on name ?)
	Model loading
	Material system.
	Handle all the TODO left in the code.
	Less duplication between minecraftCube, WhiteCube and sceneNode.
	Create a templated ResourceCache (cf. Urho3D)
	Shader hot reload :)
	Implement more shaders -> Wireframe effect.
	Try to understand shadows.
	Dynamic number of lights.
	Have a clean separation between the engine and the game (lib).
	Apparently, the engine should not be aware of glfw. put glfw only in the main.
*/

int main()
{
	ServiceLocator::Init();

	auto renderer = ServiceLocator::Get<Renderer>();
	renderer->Init("NACRe", glm::uvec2(1024, 768));
	renderer->SetClearColor(Color(0x00071C));

	auto inputManager = ServiceLocator::Get<InputManager>();
	inputManager->Init();

	Clock clock;
	Camera camera;
	Scene scene;

	while (renderer->IsRunning() && ! inputManager->IsKeyDown(GLFW_KEY_ESCAPE) )
	{
		clock.Update();

		renderer->NewFrame();
		inputManager->Update();

		if ( inputManager->IsKeyPressed(GLFW_KEY_GRAVE_ACCENT) )
		{
			renderer->ToggleImGuiEnabled();
			camera.SetEnabled( ! renderer->IsImGuiEnabled());
		}

		camera.Update(clock.dT());
		scene.Update(clock.dT(), camera.GetPosition());

		renderer->Render(camera.GetProjectionMatrix(), camera.GetViewMatrix());
	}

	return EXIT_SUCCESS;
}
