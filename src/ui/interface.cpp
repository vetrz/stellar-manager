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

namespace stellar
{
    Element _RenderTable(Vetor& vetor)
    {
        std::vector<Element> rows;
        
        rows.push_back(
            hbox({
                text(" ID ") | center | size(WIDTH, EQUAL, 5), separator(),
                text(" Nome ") | center | size(WIDTH, EQUAL, 18), separator(),
                text(" Ano ") | center | size(WIDTH, EQUAL, 6), separator(),
                text(" Distância ") | center | size(WIDTH, EQUAL, 12), separator(),
                text(" Hemisfério ") | center | size(WIDTH, EQUAL, 12), separator(),
                text(" Significado Mitológico ") | center | flex 
            }) | bold | color(Color::Cyan)
        );
        
        rows.push_back(separator());
        
        for (int i = 0; i < vetor.size(); i++){
            Constellation& c = vetor[i];
            
            rows.push_back(
                hbox({
                    text(std::to_string(c.id)) | center | size(WIDTH, EQUAL, 5), separator(),
                    text(c.nome) | center | size(WIDTH, EQUAL, 18), separator(),
                    text(std::to_string(c.anoDescobrimento)) | center | size(WIDTH, EQUAL, 6), separator(),
                    text(std::to_string(c.distanciaTerra)) | center | size(WIDTH, EQUAL, 12), separator(),
                    text(std::string(1, c.hemisferio)) | center | size(WIDTH, EQUAL, 12), separator(),
                    paragraph(c.significado) | center | flex
                })
            );
        }

        return vbox(std::move(rows));
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
            case 0: {
                dynamic_content = vbox({
                    text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                    text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                    text(" Lista de Constelações ") | bold | hcenter | color(Color::Cyan),
                    text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                    text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                    separator(),
                    _RenderTable(df) | flex
                });
                break;
            }
            case 1: {
                dynamic_content = vbox({
                    text(" Adicionar Nova Constelação ") | bold | color(Color::Green),
                    separator(),
                    hbox(text(" Nome: "), inputs[0]->Render()),
                    hbox(text(" Ano:  "), inputs[1]->Render()),
                    hbox(text(" Distancia da Terra:  "), inputs[2]->Render()),
                    hbox(text(" hemisferio:  "), inputs[3]->Render()),
                    hbox(text(" Significado:  "), inputs[4]->Render()),
                    text("(Pressione ENTER para salvar)") | dim
                });
                break;
            }
            case 3:{
                dynamic_content = vbox({
                    text(" Remover constelação ") | bold | color(Color::Red),
                    separator(),
                    hbox(text(" Id Para Remover: "), inputs[5]->Render()),
                    text("(Pressione ENTER para salvar)") | dim
                });
                break;
            }
            case 4: {
                screen.ExitLoopClosure()();
                dynamic_content = text("Saindo...");
                break;
            }
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