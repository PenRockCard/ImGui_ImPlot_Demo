# CMakeList.txt : CMake project for Imgui Demo, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Imgui_Demo "Imgui_Demo.cpp" "Imgui_Demo.h" "imgui/imgui_impl_win32.cpp" "imgui/imgui_impl_win32.h" "imgui/imgui.cpp" "imgui/imgui_demo.cpp" "imgui/imgui_draw.cpp" "imgui/imgui_impl_dx11.cpp" "imgui/imgui_tables.cpp" "imgui/imgui_widgets.cpp" "imgui/imconfig.h" "imgui/imgui.h" "imgui/imgui_impl_dx11.h" "imgui/imgui_internal.h" "imgui/imstb_rectpack.h" "imgui/imstb_textedit.h" "imgui/imstb_truetype.h" implot_demo.cpp implot_items.cpp implot_internal.h implot.h implot.cpp Graphing_Demo.cpp Graphing_Demo.h Ellipse.cpp Ellipse.h)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Imgui_Demo PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

target_link_libraries(${PROJECT_NAME} d3d11.lib)