target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpHeader.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpPrologue.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpScenarioHeader.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpScenarioInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpStartingBonusDetails.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpStartingOptions.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpVideo.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpHeader.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpPrologue.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpScenarioHeader.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpScenarioInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpStartingBonusDetails.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpStartingOptions.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CmpVideo.hpp"
)