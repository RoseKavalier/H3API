target_sources(H3API PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Artifact.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ArtifactSetup.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombinationArtifacts.cpp"
)

target_sources(H3API PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/H3Artifact.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3ArtifactSetup.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/H3CombinationArtifacts.hpp"
)