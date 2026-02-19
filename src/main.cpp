#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "ui/interface.hpp"
#include "models/constellation.hpp"
#include "core/vetor.hpp"
#include "infra/dataLoader.hpp"

int main() 
{
    stellar::Vetor df;
    
    stellar::readFromFile(df, "../data/constellation.csv");

    auto screen = ftxui::ScreenInteractive::TerminalOutput();

    int active_screen = 0;
    std::vector<std::string> options_menu = {
        "Listar Tudo",
        "Adicionar Nova",
        "Editar Selecionada",
        "Excluir",
        "Sair"
    };

    auto menu = ftxui::Menu(&options_menu, &active_screen);

    std::string new_name, new_year, new_distance, new_hemisphere, new_meaning, id_to_modify, id_to_remove;

    std::vector<ftxui::Component> inputs = {
        (ftxui::Input(&new_name, "Nome da constelação")), 
        (ftxui::Input(&new_year, "Ano de descobrimento")),
        (ftxui::Input(&new_distance, "Distância da Terra")),
        (ftxui::Input(&new_hemisphere, "Hemisferio localizado")),
        (ftxui::Input(&new_meaning, "Significado")),
        (ftxui::Input(&id_to_modify, "Digite o id para modificar")),
        (ftxui::Input(&id_to_remove, "Digite o id para excluir"))
    };

    auto main_container = ftxui::Container::Vertical({
        menu, 
        inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6]
    });

    auto component_with_input = ftxui::CatchEvent(main_container, [&](ftxui::Event event) -> bool{
        if (event == ftxui::Event::Return){
            if(active_screen == 1) {
                stellar::Constellation c = stellar::addConstellation(
                    df[df.size()-1].id + 1,
                    new_name,
                    std::stoi(new_year),
                    std::stof(new_distance),
                    std::toupper(new_hemisphere[0]),
                    new_meaning
                );

                df.push(c);

                new_name = ""; new_year = ""; new_distance = ""; new_hemisphere = ""; new_meaning = "";

                active_screen = 0;

                return true;
            }
            if (active_screen == 2){
                int target = std::stoi(id_to_modify) - 1;

                df[target].nome = new_name;
                df[target].anoDescobrimento = std::stoi(new_year);
                df[target].distanciaTerra = std::stof(new_distance);
                df[target].hemisferio = std::toupper(new_hemisphere[0]);
                df[target].significado = new_meaning; 

                id_to_modify = ""; new_name = ""; new_year = ""; new_distance = ""; new_hemisphere = ""; new_meaning = "";

                active_screen = 0;

                return true;
            }

            if (active_screen == 3){
                int target = std::stoi(id_to_remove) - 1;

                df.remove(target);

                id_to_remove = "";
                active_screen = 0;

                return true;
            }
        }
        return false;
    });

    auto main_renderer = ftxui::Renderer(component_with_input, [&] {
        return stellar::DesignInterface(
            active_screen, 
            menu,
            inputs,
            df, 
            screen);
        });

    screen.Loop(main_renderer);

    return 0;
}