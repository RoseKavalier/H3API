target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Diplomacy.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PrimarySkills.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SecondarySkill.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Diplomacy.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3PrimarySkills.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SecondarySkill.hpp"
)