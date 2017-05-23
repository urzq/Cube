#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <GL/glew.h>
#include <glfw3.h>

#include <vector>

#include <glm/glm.hpp>

#include "Light.h"

class Renderable;
class VertexBuffer;
class ShaderProgram;

class Renderer
{
public:
	Renderer();
	~Renderer();

	void Init(const char* windowName, glm::uvec2 windowSize);

	void SetClearColor(glm::vec3 clearColor);

	void NewFrame();
	void Render(const glm::mat4& projection, const glm::mat4& view);
	
	bool IsRunning() const;

	void ToggleImGuiEnabled();
	bool IsImGuiEnabled() const;

	Renderable* CreateRenderable(VertexBuffer* refVertexBuffer, ShaderProgram* refShaderProgram);
	void DestroyRenderable(Renderable* renderable);

	GLFWwindow* GetGLFWwindow() const;

	Light& GetLight();

private:
	void RefreshShader(ShaderProgram* newShader, const glm::mat4& projection, const glm::mat4& view);
	void RefreshVertexBuffer(VertexBuffer* newVertexBuffer);

private:
	GLFWwindow* m_Window;
	glm::vec2 m_WindowSize;

	bool m_ImGuiEnabled;

	std::vector<Renderable*> m_Renderables;
	
	VertexBuffer* m_CurrentVertexBuffer;
	ShaderProgram* m_CurrentShaderProgram;
	Light m_Light;
};

#endif