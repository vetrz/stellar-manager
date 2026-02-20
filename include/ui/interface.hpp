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
        Component& filter_radio, // renderizar o rádio
        std::vector<ftxui::Component>& inputs,
        std::vector<ftxui::Component>& inputs_filtro, // adição dos inputs dos filtros
        stellar::Vetor& filtered_constellation, //adição do vetor filtrado para exibição
        Vetor& df, 
        ScreenInteractive& screen,
        int selected_filter);
}

#endif // INTERFACE_HPP