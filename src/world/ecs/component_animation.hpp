#ifndef __component_animation__
#define __component_animation__
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "component.hpp"
#include "util/update.hpp"

namespace ecs {


class component_animation : public component
{

using Frames = std::vector<sf::IntRect>;
using TimePerFrame = std::vector<Second>;
private:
  sf::Texture texture;
  Frames frames;
  TimePerFrame time_per_frame;
  Second time_elapsed = 0;
  std::size_t current_frame_index = 0;

public:
  component_animation(const Frames &frames, const TimePerFrame &timeInFrame);
  void update(sf::Sprite &sprite, Second delta);
  void receive() override;
  void set_texture_file(std::string filename);
  void set_frame(sf::Sprite &sprite, std::size_t frame);
};

}// namespace ecs
#endif