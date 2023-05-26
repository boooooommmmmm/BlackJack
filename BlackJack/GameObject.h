#pragma once

#include <string>

using namespace std;
namespace Engine {
	class GameObject
	{
	public:
		GameObject();
		GameObject(string name);
		~GameObject();

		virtual void Update(const float deltaTime);
		virtual void Init();
		virtual void Dispose();

		string Name;
	private:

		void OnInit();
		void OnDispose();
		void OnUpdate(const float deltaTime);
	};
}