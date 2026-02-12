#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <vector>
#include <string>
#include "models/constellation.hpp"
#include "core/vetor.hpp"
#include "ui/interface.hpp"

using namespace ftxui;

namespace StellarUi
{
    Element _RenderTable(Vetor& vetor)
    {
        std::vector<std::vector<std::string>> matrix;
        matrix.push_back({
            "    ID    ",
            "    Nome    ",
            "    Ano de descobrimento    ",
            "    Distancia da Terra    ",
            "    Hemisferio    ",
            "    Significado Mitologico    "
            });

        for (int i = 0; i < vetor.size(); i++){
            Constellation& c = vetor[i];
            
            matrix.push_back({
                std::to_string(c.id),
                c.nome,
                std::to_string(c.anoDescobrimento),
                std::to_string(c.distanciaTerra),
                std::string(1, c.hemisferio),
                c.significado
            });
        }
        auto t = Table(matrix);
        
        t.SelectRow(0).Decorate(bold | color(Color::Cyan));
        t.SelectAll().Border(BorderStyle::LIGHT);
        t.SelectAll().DecorateCells(center);
        
        return t.Render();
    }

    Element DesignInterface(
        int active_screen, 
        Component& menu, 
        std::vector<ftxui::Component>& inputs,
        Vetor& df, 
        ScreenInteractive& screen) 
    {
        
        Element dynamic_content;
        switch (active_screen) {
            case 0: 
                dynamic_content = vbox({
                    text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                    text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                    text(" Lista de Constelações ") | bold | hcenter | color(Color::Cyan),
                    text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                    text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                    separator(),
                    _RenderTable(df) | frame | flex
                });
                break;
            case 1:
                dynamic_content = vbox({
                    text(" Adicionar Nova Constelação ") | bold,
                    separator(),
                    hbox(text(" Nome: "), inputs[0]->Render()),
                    hbox(text(" Ano:  "), inputs[1]->Render()),
                    hbox(text(" Distancia da Terra:  "), inputs[2]->Render()),
                    hbox(text(" hemisferio:  "), inputs[3]->Render()),
                    hbox(text(" Significado:  "), inputs[4]->Render()),
                    text("(Pressione ENTER para salvar)") | dim
                });
                break;
            case 4: 
                screen.ExitLoopClosure()();
                dynamic_content = text("Saindo...");
                break;
            default:
                dynamic_content = text("Em desenvolvimento...") | center;
                break;
        }
        return hbox({
            vbox({
                text(" OPÇÕES ") | bold | color(Color::Yellow),
                separator(),
                menu->Render(),
            }) | size(WIDTH, LESS_THAN, 25) | border,
            
            vbox({
                text(" STELLAR MANAGER ") | bold | hcenter | color(Color::Cyan),
                separator(),
                dynamic_content | flex | frame,
            }) | flex | border
        });
    }
}