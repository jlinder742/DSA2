#include "AppClass.h"
void Application::InitVariables(void)
{
	//Make MyMesh object
	m_pMesh = new MyMesh();
	m_pMesh->GenerateCube(2.0f, C_BROWN);

	//Make MyMesh object
	m_pMesh1 = new MyMesh();
	m_pMesh1->GenerateCube(1.0f, C_BLACK);
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
}

void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//Calculate the model, view and projection matrix
	matrix4 m4Projection = m_pCameraMngr->GetProjectionMatrix();
	matrix4 m4View = m_pCameraMngr->GetViewMatrix();

	//Get a timer
	static float fTimer = 0;	//store the new timer
	static uint uClock = m_pSystem->GenClock(); //generate a new clock for that timer
	fTimer += static_cast<float>(m_pSystem->GetDeltaTime(uClock)); //get the delta time for that timer
	static vector3 v3Position(-25.0f , 00.0f, 0.0f);

	v3Position.x += fTimer/16;
	matrix4 m4Position = glm::translate(vector3(-15.0f, -5.0f, -15.0f)) * glm::translate(v3Position);

	//The alien
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 0.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 0.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 0.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 0.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(0.0f, 1.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 1.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 1.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 1.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(0.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 2.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(10.0f, 2.0f, 0.0f)));
	for (int i = 0; i < 11; ++i)
	{
		m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(i, 3.0f, 0.0f)));
	}
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(1.0f, 4.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2.0f, 4.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(4.0f, 4.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(5.0f, 4.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(6.0f, 4.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8.0f, 4.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(9.0f, 4.0f, 0.0f)));
	for (int i = 2; i < 9; ++i)
	{
		m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(i, 5.0f, 0.0f)));
	}
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(3, 6.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(7, 6.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(2, 7.0f, 0.0f)));
	m_pMesh1->Render(m4Projection, m4View, glm::translate(m4Position, vector3(8, 7.0f, 0.0f)));
	m_pMeshMngr->AddSkyboxToRenderList();
	m_uRenderCallCount = m_pMeshMngr->Render();
	m_pMeshMngr->ClearRenderList();

	//draw gui
	DrawGUI();

	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	if (m_pMesh != nullptr)
	{
		delete m_pMesh;
		m_pMesh = nullptr;
	}
	SafeDelete(m_pMesh1);
	//release GUI
	ShutdownGUI();
}