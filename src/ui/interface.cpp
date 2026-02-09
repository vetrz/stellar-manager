#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <vector>
#include <string>
#include "models/constellation.h"
#include "core/vetor.h"
#include "ui/interface.h"

using namespace ftxui;

Element _RenderizarTabela(Vetor& vetor)
{
    std::vector<std::vector<std::string>> matriz;
    matriz.push_back({"ID", "Nome","Ano de descobrimento","Distancia da Terra","Hemisferio","Significado Mitologico"});
    for (int i = 0; i < vetor.size(); i++){
        Constellation& c = vetor[i];
        
        matriz.push_back({
            std::to_string(c.id),
            c.nome,
            std::to_string(c.anoDescobrimento),
            std::to_string(c.distanciaTerra),
            std::string(1, c.hemisferio),
            c.significado
        });
    }
    auto t = Table(matriz);
    
    t.SelectRow(0).Decorate(bold | color(Color::Cyan));
    t.SelectAll().Border(BorderStyle::LIGHT);
    
    return t.Render();
}

Element DesenharInterface(
    int tela_ativa, 
    Component& menu, 
    Component& input_nome, 
    Component& input_ano, 
    Vetor& df, 
    ScreenInteractive& screen) 
{
    
    Element conteudo_dinamico;
    switch (tela_ativa) {
        case 0: 
            conteudo_dinamico = vbox({
                text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                text(" Lista de Constelações ") | bold | hcenter | color(Color::Cyan),
                text("* .   .  * * .   .  * * .   .  *") | color(Color::YellowLight) | hcenter,
                text("  .  * .      .  * .      .  * .  ") | color(Color::Yellow) | hcenter,
                separator(),
                _RenderizarTabela(df) | frame | flex
            });
            break;
        case 1:
            conteudo_dinamico = vbox({
                text(" Adicionar Nova Constelação ") | bold,
                separator(),
                hbox(text(" Nome: "), input_nome->Render()),
                hbox(text(" Ano:  "), input_ano->Render()),
                text("(Pressione ENTER para salvar)") | dim
            });
            break;
        case 4: 
            screen.ExitLoopClosure()();
            conteudo_dinamico = text("Saindo...");
            break;
        default:
            conteudo_dinamico = text("Em desenvolvimento...") | center;
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
            conteudo_dinamico | flex | frame,
        }) | flex | border
    });
}