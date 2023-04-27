
add_library(hdQuantum SHARED EXCLUDE_FROM_ALL)

target_link_libraries(hdQuantum donut_core donut_render donut_app donut_engine)

#find_library(USD_LIB tbb osdCPU osdGPU ${USD_LIB_DIR})
#MESSAGE(${USD_LIB})
#target_link_libraries(hdQuantum ${USD_LIB})

target_link_libraries(hdQuantum "${USD_LIB_DIR}/tbb.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/osdCPU.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/osdGPU.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_usd.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hdx.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_kind.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_pcp.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hdSt.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_glf.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hio.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hdsi.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hd.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hf.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_cameraUtil.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_pxOsd.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hgiGL.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_sdr.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_ndr.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_sdf.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_ar.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hgiInterop.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_vt.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_garch.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hgiVulkan.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_hgi.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_plug.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_work.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_trace.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_js.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_gf.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_tf.lib")
target_link_libraries(hdQuantum "${USD_LIB_DIR}/usd_arch.lib")


add_subdirectory(src)
add_subdirectory(shaders)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES 
        ${hdQuantum_SRC_FILES}
        ${hdQuantum_SHADER_FILES})

target_include_directories(hdQuantum PRIVATE
shaders/
src/
"${pxr_DIR}/"
"${boost_DIR}/"
"${tbb_DIR}/"
"${OpenSubdiv_DIR}/")

set_target_properties(hdQuantum PROPERTIES FOLDER ${QuantumFolder})

# Add default compile definitions (set in root CMakefile)
#target_compile_definitions(hdQuantum PRIVATE ${DEFAULT_COMPILE_DEFINITIONS})

add_compile_options(-Wno-4244 -Wno-4305 -Wno-4267 -Wno-4506 -Wno-4091 -Wno-4273 -Wno-4180 -Wno-4334)

add_custom_command(TARGET hdQuantum POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "$(TargetDir)$(TargetName)$(TargetExt)" "${UST_INSTALL_ROOT}/plugin/usd"
    COMMAND ${CMAKE_COMMAND} -E copy "$(TargetDir)$(TargetName).pdb" "${UST_INSTALL_ROOT}/plugin/usd"
	COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/resources" "${UST_INSTALL_ROOT}/plugin/usd/hdQuantum/resources"
)

