#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <vector>
#include <string>
#include "../include/constellation.h"
#include "../include/vetor.h"

using namespace ftxui;

Element RenderizarTabela(Vetor& vetor)
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

Element DesenharInterface(int tela_ativa, Component& menu, Component& input_nome, Component& input_ano, Vetor& df, ScreenInteractive& screen) {
    Element conteudo_dinamico;

    switch (tela_ativa) {
        case 0: 
            conteudo_dinamico = vbox({
                text(" Lista de Constelações ") | bold | hcenter,
                separator(),
                RenderizarTabela(df) | frame | flex
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
            text(" STELLAR MANAGER") | bold | color(Color::Yellow),
            separator(),
            menu->Render(),
        }) | size(WIDTH, LESS_THAN, 25) | border,
        
        vbox({
            text(" ÁREA DE TRABALHO ") | bold | hcenter,
            separator(),
            conteudo_dinamico | flex | frame,
        }) | flex | border
    });
}

int main() 
{
    Vetor df;
    Constellation c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
    c1 = addConstellation(1, "Cruzeiro do Sul", 1589, 321.0, 'S', "Guia de navegantes");
    c2 = addConstellation(2, "Ursa Maior", 150, 80.0, 'N', "Ninfa Calisto transformada");
    c3 = addConstellation(3, "Orion", 150, 773.0, 'N', "O Gigante Cacador");
    c4 = addConstellation(4, "Centauro", 150, 4.37, 'S', "Quiron o mestre sabio");
    c5 = addConstellation(5, "Cassiopeia", 150, 54.0, 'N', "Rainha vaidosa punida");
    c6 = addConstellation(6, "Escorpiao", 150, 550.0, 'S', "O algoz de Orion");
    c7 = addConstellation(7, "Andromeda", 150, 97.0, 'N', "Princesa acorrentada");
    c8 = addConstellation(8, "Leao", 150, 77.0, 'N', "O Leao de Nemeia");
    c9 = addConstellation(9, "Fenix", 1597, 77.0, 'S', "Passaro que renasce");
    c10 = addConstellation(10, "Pegaso", 150, 133.0, 'N', "O Cavalo Alado");

    df.push(c1);
    df.push(c2);
    df.push(c3);
    df.push(c4);
    df.push(c5);
    df.push(c6);
    df.push(c7);
    df.push(c8);
    df.push(c9);
    df.push(c10);


    auto screen = ScreenInteractive::TerminalOutput();

    int tela_ativa = 0;
    std::vector<std::string> opcoes_menu = {
        "Listar Tudo",
        "Adicionar Nova",
        "Editar Selecionada",
        "Excluir",
        "Sair"
    };

    auto menu = Menu(&opcoes_menu, &tela_ativa);

    std::string novo_nome, novo_ano;
    Component input_nome = Input(&novo_nome, "Nome da constelação");
    Component input_ano = Input(&novo_ano, "Ano de descobrimento");


    auto main_renderer = Renderer(Container::Vertical({menu, input_nome, input_ano}), [&] {
        return DesenharInterface(tela_ativa, menu, input_nome, input_ano, df, screen);
    });

    screen.Loop(main_renderer);

    return 0;
}
