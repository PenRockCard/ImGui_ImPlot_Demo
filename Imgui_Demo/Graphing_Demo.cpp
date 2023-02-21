#include "Graphing_Demo.h"
#include "imgui/imgui.h"
#include "implot.h"
#include <numbers>
#include "Ellipse.h"

bool Create_Ellipse_Window(bool openWindow) {
    auto plutoOrbit = new Ellipse(7.37593 * 1000000000,4.43682 * 1000000000,360,0.5*1000000000,0.5*1000000000, 315);
    auto neptuneOrbit = new Ellipse(4.54 * 1000000000,4.46 * 1000000000,360);
    auto xArrayPluto = plutoOrbit->GetXArray();
    auto yArrayPluto = plutoOrbit->GetYArray();
    auto xArrayNeptune = neptuneOrbit->GetXArray();
    auto yArrayNeptune = neptuneOrbit->GetYArray();

    if (openWindow) {
        ImGui::Begin("ImGraph", &openWindow);

        ImGui::Text("Pluto and Neptune Graph");
        ImGui::Text("*Not accurate");

        //The -1,-1 makes it fit to the frame (basically as big as possible)
        if (ImPlot::BeginPlot("##PlotTesting",ImVec2(-1,-1),ImPlotFlags_Equal|ImPlotFlags_NoFrame|ImPlotFlags_NoMouseText)) {
            ImPlot::PlotLine("Pluto", xArrayPluto, yArrayPluto, plutoOrbit->GetNumberPoints());
            ImPlot::PlotLine("Neptune", xArrayNeptune, yArrayNeptune, neptuneOrbit->GetNumberPoints());
            ImPlot::EndPlot();
        }
        ImGui::End();
    }
    return openWindow;
}


