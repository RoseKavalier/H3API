target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CustomHeroData.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Hero.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HeroInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HeroPlaceholder.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HeroSpecialty.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ScenarioHeroInfo.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SetupHero.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CustomHeroData.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Hero.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HeroInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HeroPlaceholder.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3HeroSpecialty.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ScenarioHeroInfo.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3SetupHero.hpp"
)