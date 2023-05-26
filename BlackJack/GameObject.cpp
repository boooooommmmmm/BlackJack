#include "GameObject.h"
#include <string>

using namespace std;

namespace Engine {
	GameObject::GameObject()
	{
		OnInit();
	}

	GameObject::GameObject(string name)
	{
		this->Name = name;
		GameObject();
	}

	GameObject::~GameObject()
	{
		OnDispose();
	}

	void GameObject::OnInit()
	{
		GameObject::Init();
	}

	void GameObject::OnDispose()
	{
		GameObject::Dispose();
	}

	void GameObject::OnUpdate(const float deltaTime)
	{
		GameObject::Update(deltaTime);
	}

	void  GameObject::Update(const float deltaTime) {}
	void  GameObject::Init() {}
	void  GameObject::Dispose() {}
}
