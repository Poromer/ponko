/**
* @filename:	EntityFactory.cpp
* @author:		weijie
* @date:		14 Apr 2024
* @breif:		making certain entities easier
*/

#include "pch.h"
#include "EntityFactory.h"

namespace PonkoEnv
{
	Entity& MakeCollider(Entity& _entity, Vec3<float> _pos, Vec3<float> _widheight)
	{
		_entity.addComponent<TransformComp>(_pos);
		_entity.addComponent<ColliderComp>(AABB(_pos, _widheight));

		return _entity;
	}

	Entity& MakeButton(Entity& _entity, Vec3<float> _pos, Vec3<float> _widheight, const char* _filepathImg)
	{
		MakeCollider(_entity, _pos, _widheight);
		_entity.addComponent<RenderComp>(_filepathImg, _widheight);
		return _entity;
	}


}