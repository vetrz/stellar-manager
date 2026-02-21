#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include "ui/interface.hpp"
#include "models/constellation.hpp"
#include "services/constellationFilters.hpp"
#include "core/vetor.hpp"
#include "infra/dataLoader.hpp"

int main() 
{
    stellar::Vetor df;
    
    stellar::readFromFile(df, "../data/constellation.csv");

    auto screen = ftxui::ScreenInteractive::TerminalOutput();

    int active_screen = 0;
    int current_page = 0;

    std::vector<std::string> options_menu = {
        "Listar Tudo",
        "Adicionar Nova",
        "Buscar ou Filtrar",
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
        (ftxui::Input(&new_hemisphere, "hemisphere localizado")),
        (ftxui::Input(&new_meaning, "Significado")),
        (ftxui::Input(&id_to_modify, "Digite o id para modificar")),
        (ftxui::Input(&id_to_remove, "Digite o id para excluir"))
    };

    stellar::Vetor filtered_constellation = df;
    int selected_filter = 0; 

    std::vector<std::string> filter_options = {
        "Todos", 
        "Hemisfério", 
        "Id", 
        "Nome", 
        "Intervalo"
    };

    auto filter = ftxui::Radiobox(&filter_options, &selected_filter);

    std::string name, hemisphere, id, start_id, end_id;
    std::vector<ftxui::Component> inputs_filter = {
        ftxui::Input(&name, "Nome"),
        ftxui::Input(&hemisphere, "Hemisfério"),
        ftxui::Input(&id, "ID"),
        ftxui::Input(&start_id, "ID Mínimo"),
        ftxui::Input(&end_id, "ID Máximo")
    };

    auto main_container = ftxui::Container::Vertical({
        menu, 
        filter,
        inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6],
        inputs_filter[0],inputs_filter[1],inputs_filter[2],inputs_filter[3],inputs_filter[4]
    });

    auto interactive_component = ftxui::CatchEvent(main_container, [&](ftxui::Event event) -> bool{
        if (active_screen == 0) {
            int total_pages = (filtered_constellation.size() + 14) / 15;

            if (event == ftxui::Event::ArrowRight) {
                if (current_page < total_pages - 1) current_page++;
                return true;
            }
            if (event == ftxui::Event::ArrowLeft) {
                if (current_page > 0) current_page--;
                return true;
            }
        }

        if (event == ftxui::Event::Return){
            if (active_screen == 1) {
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
            if (active_screen == 3){
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
            if (active_screen == 4){
                int target = std::stoi(id_to_remove) - 1;

                df.remove(target);
                
                id_to_remove = "";
                active_screen = 0;

                return true;
            }
        }
        return false;
    });

    auto main_renderer = ftxui::Renderer(interactive_component, [&] {
        switch (selected_filter) {
            case 0:
                filtered_constellation = df.filter([](const stellar::Constellation& c) {return true;}); // Exibe todos
                break;
            case 1:
                filtered_constellation = df.filter([&](const stellar::Constellation& c) {
                    if (hemisphere.empty()) return true;
                    return stellar::byHemisphere(c, std::toupper(hemisphere[0]));
                    });
                break;
            case 2: 
                filtered_constellation = df.filter([&] (const stellar::Constellation& c) {
                    if (id.empty()) return true;
                    return stellar::byId(c, std::stoi(id));
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
                    if (start_id.empty() || end_id.empty()) return true;
                    return stellar::byInterval(c,std::stoi(start_id),std::stoi(end_id));
                    });
                break;
        }
        return stellar::DesignInterface(
            active_screen, 
            current_page,
            menu,
            filter,
            inputs,
            inputs_filter,
            filtered_constellation,
            screen,
            selected_filter);
        });

    screen.Loop(main_renderer);

    return 0;
}