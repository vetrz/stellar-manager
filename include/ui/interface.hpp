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
    Element _RenderTable(Vetor& vetor);

    Element DesignInterface(
        int active_screen, 
        Component& menu, 
        std::vector<ftxui::Component>& inputs,
        Vetor& df, 
        ScreenInteractive& screen);
}

#endif // INTERFACE_HPP