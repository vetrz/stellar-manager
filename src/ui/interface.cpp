#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <vector>
#include <string>
#include "models/constellation.hpp"
#include "core/vetor.hpp"
#include "ui/interface.hpp"

namespace stellar
{
    using namespace ftxui;

    Element _RenderTable(Vetor& vetor, int current_page)
    {
        std::vector<Element> rows;
        int items_per_page = 15;
        int start = current_page * items_per_page;
        int end = std::min(start + items_per_page, (int)vetor.size());
        
        rows.push_back(
            hbox({
                text(" ID ") | center | size(WIDTH, EQUAL, 5), separator(),
                text(" Nome ") | center | size(WIDTH, EQUAL, 18), separator(),
                text(" Ano ") | center | size(WIDTH, EQUAL, 6), separator(),
                text(" Distância ") | center | size(WIDTH, EQUAL, 12), separator(),
                text(" Hemisfério ") | center | size(WIDTH, EQUAL, 12), separator(),
                text(" Significado Mitológico ") | center | flex 
            }) | bold | color(Color::LightCyan1Bis)
        );
        
        rows.push_back(separator());
        
        for (int i = start; i < end; i++){
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
        int current_page, 
        Component& menu,
        Component& exit_menu, 
        Component& filter_radio, 
        std::vector<Component>& inputs,
        std::vector<Component>& inputs_filter,
        Vetor& filtered_constellation,
        ScreenInteractive& screen,
        int selected_filter)  
    {
        
        Element dynamic_content;
        switch (active_screen) {
            case 0: {
                int total_pages = (filtered_constellation.size() + 14) / 15;

                dynamic_content = vbox({
                    text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                    text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                    text(" Lista de Constelações ") | bold | hcenter | color(Color::Cyan),
                    text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                    text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                    text("Página " + std::to_string(current_page + 1) + " de " + std::to_string(total_pages)) | hcenter | dim | color(Color::LightGoldenrod1),
                    separator(),
                    _RenderTable(filtered_constellation, current_page) | flex,
                    separator(),
                    text(" [<-] Página Anterior | Próxima Página [->] ") | hcenter,
                    separator()
                });
                break;
            }
            case 1: {
                dynamic_content = vbox({
                    text(" Adicionar Nova Constelação ") | bold | color(Color::PaleGreen1),
                    separator(),
                    hbox(text(" Nome: "), inputs[0]->Render()),
                    hbox(text(" Ano:  "), inputs[1]->Render()),
                    hbox(text(" Distancia da Terra:  "), inputs[2]->Render()),
                    hbox(text(" hemisferio:  "), inputs[3]->Render()),
                    hbox(text(" Significado:  "), inputs[4]->Render()),
                    separator(),
                    text(" Pressione [Enter] para salvar | [ESC] para Voltar ") | border
                });
                break;
            }
            case 2: {
                Element dynamic_field = emptyElement();

                if (selected_filter == 1) {
                    dynamic_field = window(text("Digite o Hemisfério: "), inputs_filter[1]->Render());
                } 
                else if (selected_filter == 2) {
                    dynamic_field = window(text("Digite o ID exato: "), inputs_filter[2]->Render());
                } 
                else if (selected_filter == 3) {
                    dynamic_field = window(text("Digite o Nome: "), inputs_filter[0]->Render());
                } 
                else if (selected_filter == 4) {
                    dynamic_field = hbox({
                        window(text("Digite o ID inicial: "), inputs_filter[3]->Render()) | flex,
                        window(text("Digite o ID final: "),   inputs_filter[4]->Render()) | flex,
                    });
                }

                dynamic_content = vbox({
                    text(" Configurações de Filtro ") | bold | color(Color::PaleTurquoise1),
                    separator(),
                    text(" Selecione o método de filtragem:"),
                    separator(),
                    filter_radio->Render() | borderDouble,
                    separator(),
                    dynamic_field, 
                    separator(),
                    text(" A escolha será aplicada na aba 'Listar Tudo' ") | dim,
                    separator(),
                    text(" [ESC] para Voltar ") | border
                });
                break;
            }
            case 3: {
                dynamic_content = vbox({
                    text(" Editar uma Constelação ") | bold | color(Color::SkyBlue1),
                    separator(),
                    hbox(text(" Id da Constelação para Modificar: "), inputs[5]->Render()),
                    separator(),
                    hbox(text(" Nome: "), inputs[0]->Render()),
                    hbox(text(" Ano:  "), inputs[1]->Render()),
                    hbox(text(" Distancia da Terra:  "), inputs[2]->Render()),
                    hbox(text(" hemisferio:  "), inputs[3]->Render()),
                    hbox(text(" Significado:  "), inputs[4]->Render()),
                    separator(),
                    text(" Pressione [Enter] para salvar | [ESC] para Voltar ") | border
                });
                break;
            }
            case 4:{
                dynamic_content = vbox({
                    text(" Remover constelação ") | bold | color(Color::RedLight),
                    separator(),
                    hbox(text(" Id Para Remover: "), inputs[6]->Render()),
                    separator(),
                    text(" Pressione [Enter] para salvar | [ESC] para Voltar ") | border
                });
                break;
            }
            case 5: {
                dynamic_content = vbox({
                    text( "Configurações de Saída ") | bold | color(Color::PaleVioletRed1),
                    separator(),
                    exit_menu->Render() | color(Color::MistyRose3) | borderDouble,
                    separator(),
                    text(" [↑] [↓] Navegar | [Enter] Confirmar | [ESC] Voltar") | border
                });
                break;
            }
            default:
                dynamic_content = text("Em desenvolvimento...") | center;
                break;
        }
        return hbox({
            vbox({
                text(" OPÇÕES ") | bold | color(Color::LightGoldenrod1),
                separator(),
                menu->Render(),
            }) | size(WIDTH, LESS_THAN, 25) | border,
            
            vbox({
                text(" STELLAR MANAGER ") | bold | hcenter | color(Color::CyanLight),
                separator(),
                dynamic_content | flex | frame,
            }) | flex | border
        });
    }
}