// C++
#include <iostream>
// Imgui
#include <imgui/imgui.h>
#include <imgui/imgui-SFML.h>
// Glad
#include <glad/glad.h>
// Sfml
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // Initialize and load GLAD
    if (!gladLoadGL()) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    sf::Clock deltaClock;
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        static float speed;
        static bool someBoolean;

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hello, world!");
        ImGui::Checkbox("Boolean property", &someBoolean);
        ImGui::Button("Look at this pretty button");
        ImGui::SliderFloat("Speed", &speed, 0.0f, 10.0f);
        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return EXIT_SUCCESS;
}