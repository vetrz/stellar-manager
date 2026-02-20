#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "ui/interface.hpp"
#include "models/constellation.hpp"
#include "services/constellationFilters.hpp"
#include "core/vetor.hpp"

int main() 
{
    stellar::Vetor df;
    stellar::Constellation c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
    c1 = stellar::addConstellation(1, "Cruzeiro do Sul", 1589, 321.0, 'S', "Guia de navegantes");
    c2 = stellar::addConstellation(2, "Ursa Maior", 150, 80.0, 'N', "Ninfa Calisto transformada");
    c3 = stellar::addConstellation(3, "Orion", 150, 773.0, 'N', "O Gigante Cacador");
    c4 = stellar::addConstellation(4, "Centauro", 150, 4.37, 'S', "Quiron o mestre sabio");
    c5 = stellar::addConstellation(5, "Cassiopeia", 150, 54.0, 'N', "Rainha vaidosa punida");
    c6 = stellar::addConstellation(6, "Escorpiao", 150, 550.0, 'S', "O algoz de Orion");
    c7 = stellar::addConstellation(7, "Andromeda", 150, 97.0, 'N', "Princesa acorrentada");
    c8 = stellar::addConstellation(8, "Leao", 150, 77.0, 'N', "O Leao de Nemeia");
    c9 = stellar::addConstellation(9, "Fenix", 1597, 77.0, 'S', "Passaro que renasce");
    c10 = stellar::addConstellation(10, "Pegaso", 150, 133.0, 'N', "O Cavalo Alado");

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

    std::vector<std::string> filter_options = {
        "Todos", "Hemisfério", "Id", "Nome", "Intervalo"
    };
    

    int selected_filter = 0; 

      // componente de seleção
    auto filter_radio = ftxui::Radiobox(&filter_options, &selected_filter);



    int active_screen = 0;
    std::vector<std::string> options_menu = {
        "Listar Tudo",
        "Adicionar Nova",
        "Buscar ou Filtrar",
        "Editar Selecionada",
        "Excluir",
        "Sair"
    };

    auto menu = ftxui::Menu(&options_menu, &active_screen);

    std::string new_name, new_year, new_distance, new_hemisphere, new_meaning, id_for_remove;

    std::vector<ftxui::Component> inputs = {
        (ftxui::Input(&new_name, "Nome da constelação")), 
        (ftxui::Input(&new_year, "Ano de descobrimento")),
        (ftxui::Input(&new_distance, "Distância da Terra")),
        (ftxui::Input(&new_hemisphere, "Hemisferio localizado")),
        (ftxui::Input(&new_meaning, "Significado")),
        (ftxui::Input(&id_for_remove, "Digite o id para excluir"))
    };


    std::string name, hemisferio, Id, Id_inicio, Id_final;

    std::vector<ftxui::Component> inputs_filtro = {
        ftxui::Input(&name, "Nome"),
        ftxui::Input(&hemisferio, "Hemisfério"),
        ftxui::Input(&Id, "ID"),
        ftxui::Input(&Id_inicio, "ID Mínimo"),
        ftxui::Input(&Id_final, "ID Máximo")
    };


    auto main_container = ftxui::Container::Vertical({
        menu, 
        filter_radio,
        inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5],
        inputs_filtro[0],inputs_filtro[1],inputs_filtro[2],inputs_filtro[3],inputs_filtro[4]
    });

    auto component_with_input = ftxui::CatchEvent(main_container, [&](ftxui::Event event) -> bool{
        if (event == ftxui::Event::Return){

            if(active_screen == 1) {
                stellar::Constellation c = stellar::addConstellation(
                    df[df.size()-1].id + 1,
                    new_name,
                    std::stoi(new_year),
                    std::stof(new_distance),
                    new_hemisphere[0],
                    new_meaning
                );

                df.push(c);

                new_name = ""; new_year = ""; new_distance = ""; new_hemisphere = ""; new_meaning = "";

                active_screen = 0;

                return true;
            }

            if (active_screen == 4){
                int target = std::stoi(id_for_remove) - 1;

                df.remove(target);

                id_for_remove = "";
                active_screen = 0;

                return true;
            }
        }
        return false;
    });

    auto main_renderer = ftxui::Renderer(component_with_input, [&] {
        stellar::Vetor filtered_constellation;
        switch (selected_filter) {
                
            case 0:
                filtered_constellation = df.filter([](const stellar::Constellation& c) {return true;}); // Exibe todos
                break;
            case 1:
                filtered_constellation = df.filter([&](const stellar::Constellation& c) {
                    if (hemisferio.empty()) return true;
                    return stellar::byHemisferio(c, hemisferio[0]);
                    });
                break;
            case 2: 
                filtered_constellation = df.filter([&] (const stellar::Constellation& c) {
                    if (Id.empty()) return true;
                    return stellar::byId(c, std::stoi(Id));
                    });
                break;

            case 3: 
                filtered_constellation = df.filter([&] (const stellar::Constellation& c) {
                    if (name.empty()) return true;
                    return stellar::byName(c, name);
                    });
                break;
            case 4:
                filtered_constellation = df.filter([&] (const stellar::Constellation& c) {
                    if (Id_inicio.empty() || Id_final.empty()) return true;
                    return stellar::byInterval(c,std::stoi(Id_inicio),std::stoi(Id_final));
                    });
                break;
        }

        return stellar::DesignInterface(
            active_screen,
            menu,
            filter_radio,
            inputs,
            inputs_filtro,
            filtered_constellation,
            df, 
            screen,
            selected_filter);
        });

    screen.Loop(main_renderer);

    return 0;
}



