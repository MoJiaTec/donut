file(GLOB hdQuantum_SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
	
target_sources(hdQuantum PRIVATE  ${hdQuantum_SRC_FILES})

SET(hdQuantum_SRC_FILES
    ${hdQuantum_SRC_FILES}
    PARENT_SCOPE
)
