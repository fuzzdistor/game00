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
		NPCharacter         = 1 << 2,
		Object				= 1 << 3,
		TextBox         	= 1 << 4,
		EnemyProjectile		= 1 << 5,
		SoundEffect			= 1 << 6,

		//Aircraft = PlayerAircraft | AlliedAircraft | EnemyAircraft,
		//Projectile = AlliedProjectile | EnemyProjectile,
	};
}

#endif //Category.hpp
