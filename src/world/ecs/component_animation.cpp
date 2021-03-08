#include "component_animation.hpp"
namespace ecs {

component_animation::component_animation(const Frames &frames, const TimePerFrame &time_in_frames) : frames(frames), time_per_frame(time_in_frames)
{
}

void component_animation::update(sf::Sprite &sprite, Second delta)
{
  time_elapsed += delta;

  if (time_elapsed >= time_per_frame[current_frame_index]) {
    time_elapsed = 0;
    current_frame_index++;

    if (current_frame_index >= frames.size()) {
      current_frame_index = 0;
    }
  }

  set_frame(sprite, current_frame_index);
}

void component_animation::set_frame(sf::Sprite &sprite, std::size_t frame)
{
  sprite.setTexture(texture);
  sprite.setTextureRect(frames[frame]);
}

void component_animation::receive()
{
}

void component_animation::set_texture_file(std::string filename)
{

  texture.loadFromFile(filename);
}

}// namespace ecs