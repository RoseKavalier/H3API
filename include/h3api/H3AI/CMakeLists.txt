target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Pathfinder.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PathNode.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedCombat.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedCreature.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedHero.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedSpell.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SpellCastInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SpellData.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Pathfinder.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PathNode.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedCombat.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedCreature.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedHero.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SimulatedSpell.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SpellCastInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SpellData.hpp"
)