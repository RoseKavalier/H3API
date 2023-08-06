target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3AdjacentSquares.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombatCreature.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombatSquare.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3MagicAnimation.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Obstacle.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ObstacleInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ValidCatapultTargets.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3WallSection.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3AdjacentSquares.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombatCreature.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombatSquare.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3MagicAnimation.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Obstacle.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ObstacleInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ValidCatapultTargets.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3WallSection.hpp"
)