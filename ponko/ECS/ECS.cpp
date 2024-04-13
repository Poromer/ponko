/**
* @file:	ECS.cpp
* @author:	weijie
* @date:	13 Apr 2024
* @breif:	implementation of ECS
*/
#include "pch.h"
#include "ECS.h"

// Entity Class
void Entity::Update()
{
	for (auto& c : l_components) c->Update();
	for (auto& c : l_components) c->Draw();
}

void Entity::Draw()
{

}

void Entity::Destroy()
{
	b_active = false;
}

bool Entity::isActive() const
{
	return b_active;
}

// Manager Class
EntityManager& EntityManager::Get()
{
	static EntityManager s_Instance;
	return s_Instance;
}

void EntityManager::Update()
{
	for (auto& e : l_entities) e->Update();
}

void EntityManager::Draw()
{
	for (auto& e : l_entities) e->Draw();
}

void EntityManager::CleanUp()
{
	l_entities.erase(std::remove_if(std::begin(l_entities), std::end(l_entities),
		[](const std::unique_ptr<Entity>& _mEntity)
		{ return !_mEntity->isActive(); }),
		std::end(l_entities));

}

Entity& EntityManager::addEntity()
{
	Entity* e = new Entity();
	std::unique_ptr<Entity> uPtr{ e };
	l_entities.emplace_back(std::move(uPtr));
	return *e;
}