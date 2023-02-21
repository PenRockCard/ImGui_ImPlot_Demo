# ImGui_ImPlot_Demo
Just a project combining the [ImGui](https://github.com/ocornut/imgui) and (basic) [ImPlot](https://github.com/epezent/implot) demos into one project with a few minor modifications. 
Uses the DirectX11 backend. Not kept up to date with the latest versions of either of these projects.

Currently it opens fullscreen, and the various windows that'd normally appear in each demo must be manually selected from the top bar.

This was made to assist with [my other project](https://github.com/PenRockCard/Voyageur), so I can see and modify the demos live in my IDE, etc. 
I thought I'd share it so if I broke my setup completely I could easily recover a working demo. 
If people see it and happen to use it to quickly get a demo running, that's good too! Figuring out the target_link_libraries line in the CMake file was a pain for me. 

Added a class that creates a bunch of points for an ellipse, given it's max and min dimensions (and optionally angle and offset from origin). Also added a demo to show this off using the planets Neptune and Pluto.

Future Plans:
- Add [more complicated ImPlot demos](https://github.com/epezent/implot_demos) to this
- ~~Disable the main menu bar in the main ImGui demo window.~~
- Change backend to OpenGL3 (? or something besides DirectX11/12, they produce GPU coil whine when I have the program running and my screensaver starts) 
