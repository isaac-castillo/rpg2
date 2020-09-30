#include "entity.hpp"
#include "component_input_player.hpp"
#include <utility>
namespace ecs {
    
    std::unique_ptr<entity> entity::create_from_json(std::string filename){


    }

    void entity::update(world::map_manager &map_manager, ui::window &window, float delta){

        if (m_input != nullptr)
            m_input->update(*this, delta);
        m_physics->update(*this, map_manager, delta);
        m_graphics->update(*this, window, delta);
    }

    std::unique_ptr<entity> entity::create_default_player(){

        std::unique_ptr<entity> player = std::make_unique<entity>();


        std::vector<sf::IntRect> left_frames;
        left_frames.push_back(sf::IntRect(12 * 16, 0, 16, 24));
        left_frames.push_back(sf::IntRect(13 * 16, 0, 16, 24));
        left_frames.push_back(sf::IntRect(14 * 16, 0, 16, 24));
        left_frames.push_back(sf::IntRect(15 * 16, 0, 16, 24));

        std::vector<sf::IntRect> right_frames;
        right_frames.push_back(sf::IntRect(4 * 16, 0, 16, 24));
        right_frames.push_back(sf::IntRect(5 * 16, 0, 16, 24));
        right_frames.push_back(sf::IntRect(6 * 16, 0, 16, 24));
        right_frames.push_back(sf::IntRect(7 * 16, 0, 16, 24));

        std::vector<sf::IntRect> up_frames;
        up_frames.push_back(sf::IntRect(0 * 16, 0, 16, 24));
        up_frames.push_back(sf::IntRect(1 * 16, 0, 16, 24));
        up_frames.push_back(sf::IntRect(2 * 16, 0, 16, 24));
        up_frames.push_back(sf::IntRect(3 * 16, 0, 16, 24));

        std::vector<sf::IntRect> down_frames;
        down_frames.push_back(sf::IntRect(8 * 16, 0, 16, 24));
        down_frames.push_back(sf::IntRect(9 * 16, 0, 16, 24));
        down_frames.push_back(sf::IntRect(10 * 16, 0, 16, 24));
        down_frames.push_back(sf::IntRect(11 * 16, 0, 16, 24));


        std::unique_ptr<component_animation> left_animation = std::make_unique<component_animation>(left_frames, std::vector<float>(4, 0.25));
        std::unique_ptr<component_animation> right_animation = std::make_unique<component_animation>(right_frames, std::vector<float>(4, 0.25));
        std::unique_ptr<component_animation> up_animation = std::make_unique<component_animation>(up_frames, std::vector<float>(4, 0.25));
        std::unique_ptr<component_animation> down_animation = std::make_unique<component_animation>(down_frames, std::vector<float>(4, 0.25));

        left_animation->set_texture_file("src/assets/walk_cycle.png");
        right_animation->set_texture_file("src/assets/walk_cycle.png");
        up_animation->set_texture_file("src/assets/walk_cycle.png");
        down_animation->set_texture_file("src/assets/walk_cycle.png");

        auto graphics = std::make_unique<component_graphics>();
        graphics->add_direction_animation(util::direction::LEFT, left_animation);
        graphics->add_direction_animation(util::direction::DOWN, down_animation);
        graphics->add_direction_animation(util::direction::RIGHT, right_animation);
        graphics->add_direction_animation(util::direction::UP, up_animation);



        player->set_graphics(graphics);

        std::unique_ptr<component_input> input = std::make_unique<component_input_player>();
        player->set_input(input);

        auto physics = std::make_unique<component_physics>(16);

        player->set_physics(physics);

        return player;
    }

    std::unique_ptr<entity> entity::create_default_test_npc()
    {

        std::unique_ptr<entity> player = std::make_unique<entity>();

        std::vector<sf::IntRect> idle_frames;
        idle_frames.push_back(sf::IntRect(12 * 16, 0, 16, 24));

        std::unique_ptr<component_animation> idle_animation = std::make_unique<component_animation>(idle_frames, std::vector<float>(1, 1));

        idle_animation->set_texture_file("src/assets/walk_cycle.png");

        auto graphics = std::make_unique<component_graphics>();
        graphics->add_direction_animation(util::direction::DOWN, idle_animation);


        player->set_graphics(graphics);

        std::unique_ptr<component_input> input = nullptr;
        player->set_input(input);

        auto physics = std::make_unique<component_physics>(16);
        physics->set_position(sf::Vector2f(128, 128));
        player->set_physics(physics);

        player->set_moving(util::moving::IMMOBILE);

        return player;
    }

    void entity::set_input(std::unique_ptr<component_input> &input){
        m_input = std::move(input);
    }
    void entity::set_physics(std::unique_ptr<component_physics> &physics){
        m_physics = std::move(physics);
    }

    void entity::set_graphics(std::unique_ptr<component_graphics> &graphics)
    {
        m_graphics = std::move(graphics);
    }

    entity::entity() : m_id(0), m_direction(util::direction::DOWN) {

    }

    util::direction entity::get_direction(){
        return m_direction;
    }

    util::moving entity::get_moving(){
        return m_moving;
    }

    void entity::set_direction(util::direction direction){
        m_direction = direction;
    }

    void entity::set_moving(util::moving moving)
    {
        m_moving = moving;
    }

    sf::Vector2f entity::position(){
        return m_physics->get_position();
    }


}