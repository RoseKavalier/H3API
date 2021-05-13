target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3BuildingCosts.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CastleEvent.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3OraclePuzzle.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SetupTown.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Town.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3TownCreatureTypes.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3TownDependencies.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3BuildingCosts.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CastleEvent.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3OraclePuzzle.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SetupTown.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Town.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3TownCreatureTypes.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3TownDependencies.hpp"
)