//Category.hpp
#ifndef CATEGORY_HPP
#define CATEGORY_HPP


// Entity/scene node category, used to dispatch commands
namespace Category
{
	enum Type
	{
		None				= 0,
		Room        		= 1 << 0,
		PlayerCharacter		= 1 << 1,
		NPCharacter         = 1 << 3,
		Object				= 1 << 4,
		TextBox         	= 1 << 5,
		EnemyProjectile		= 1 << 6,
		ParticleSystem		= 1 << 7,
		SoundEffect			= 1 << 8,

		//Aircraft = PlayerAircraft | AlliedAircraft | EnemyAircraft,
		//Projectile = AlliedProjectile | EnemyProjectile,
	};
}

#endif