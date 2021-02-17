add_library( MyMath SHARED Matrix4.c++ )
add_library( GraphicEngines SHARED ShaderProgramLoader.c++ )
add_library( ImageConstructor SHARED SimpleCheckerboardGenerator.c++ )

target_include_directories( MyMath PUBLIC ../include  )
target_include_directories( GraphicEngines PUBLIC ../include ${OPENGL_INCLUDE_DIR} )
target_include_directories( ImageConstructor PUBLIC ../include  )

target_link_libraries( GraphicEngines ${OPENGL_LIBRARIES} )