#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <vector>
#include <string>
#include "models/constellation.hpp"
#include "core/vetor.hpp"

using namespace ftxui;

namespace stellar
{
    Element _RenderTable(Vetor& vetor, int current_page);

    Element DesignInterface(
        int active_screen,
        int current_page,
        Component& menu, 
        Component& filter,
        std::vector<ftxui::Component>& inputs,
        std::vector<ftxui::Component>& inputs_filter,
        stellar::Vetor& filtered_constellation,
        Vetor& df, 
        ScreenInteractive& screen,
        int selected_filter);
}

#endif // INTERFACE_HPP