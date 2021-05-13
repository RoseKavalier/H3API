target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3AdventureManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3BaseManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombatManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ExecutiveMgr.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HiScoreManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3InputManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3MouseManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3RecruitManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SoundManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SwapManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3TownManager.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3WindowManager.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3AdventureManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3BaseManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombatManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ExecutiveMgr.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HiScoreManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3InputManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3MouseManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3RecruitManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SoundManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SwapManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3TownManager.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3WindowManager.hpp"
)