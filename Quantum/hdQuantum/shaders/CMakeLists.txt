file(GLOB hdQuantum_SHADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/*.hlsl
	${CMAKE_CURRENT_SOURCE_DIR}/*.hlsli
)

target_sources(hdQuantum PRIVATE  ${hdQuantum_SHADER_FILES})

SET(hdQuantum_SHADER_FILES
    ${hdQuantum_SHADER_FILES}
    PARENT_SCOPE
)