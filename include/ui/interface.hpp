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

namespace stellar
{
    using namespace ftxui;

    Element _RenderTable(Vetor& vetor, int current_page);

    Element DesignInterface(
        int active_screen,
        int current_page,
        Component& menu,
        Component& exit_menu,
        Component& filter,
        std::vector<Component>& inputs,
        std::vector<Component>& inputs_filter,
        Vetor& filtered_constellation,
        ScreenInteractive& screen,
        int selected_filter);
}

#endif // INTERFACE_HPP