target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Army.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Creature.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CreatureAnimation.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CreatureInformation.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Army.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Creature.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CreatureAnimation.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CreatureInformation.hpp"
)