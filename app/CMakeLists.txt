qt_standard_project_setup()

qt_add_executable(
    ${EXE_NAME} 
        main.cpp
)

target_link_libraries(
    ${EXE_NAME}
        PRIVATE
            Qt6::Core
            ${LIB_NAME}   
)