#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "ui/interface.hpp"
#include "models/constellation.hpp"
#include "core/vetor.hpp"

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

    auto screen = ftxui::ScreenInteractive::TerminalOutput();

    int tela_ativa = 0;
    std::vector<std::string> opcoes_menu = {
        "Listar Tudo",
        "Adicionar Nova",
        "Editar Selecionada",
        "Excluir",
        "Sair"
    };

    auto menu = ftxui::Menu(&opcoes_menu, &tela_ativa);

    std::string novo_nome, novo_ano, nova_distancia, novo_hemisferio, novo_significado;

    std::vector<ftxui::Component> inputs = {
        (ftxui::Input(&novo_nome, "Nome da constelação")), 
        (ftxui::Input(&novo_ano, "Ano de descobrimento")),
        (ftxui::Input(&nova_distancia, "Distância da Terra")),
        (ftxui::Input(&novo_hemisferio, "Hemisferio localizado")),
        (ftxui::Input(&novo_significado, "Significado")),
    };

    auto main_renderer = ftxui::Renderer(ftxui::Container::Vertical({
        menu, 
        inputs[0], 
        inputs[1],
        inputs[2],
        inputs[3],
        inputs[4]}), [&] {
        return StellarUi::DesenharInterface(
            tela_ativa, 
            menu,
            inputs,
            df, 
            screen);
    });

    screen.Loop(main_renderer);

    return 0;
}