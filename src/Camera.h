#ifndef CONTROLS_HPP
#define CONTROLS_HPP

#include <glm/glm.hpp>

class Camera
{
public:
	Camera(GLFWwindow* window);

	void Update(float dT);
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

private:
	GLFWwindow* m_Window;

	glm::mat4 m_ViewMatrix;
	glm::mat4 m_ProjectionMatrix;

	// Initial position : on +Z
	glm::vec3 m_Position = glm::vec3(0, 0, 5);

	// Initial horizontal angle : toward -Z
	float m_HorizontalAngle = 3.14f;
	// Initial vertical angle : none
	float m_VerticalAngle = 0.0f;
	// Initial Field of View
	float m_InitialFoV = 45.0f;

	float m_Speed = 3.0f; // 3 units / second
	float m_MouseSpeed = 0.005f;
};

#endif