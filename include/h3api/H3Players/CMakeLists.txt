target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Player.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PlayerAttributes.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PlayersInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ScenarioPlayer.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Player.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PlayerAttributes.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PlayersInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ScenarioPlayer.hpp"
)