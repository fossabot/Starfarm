//
// Project Starfarm
// Created by Tiphaine LAURENT on 30/04/2019.
//

#ifndef STARFARM_SPRITECOMPONENT_HPP
# define STARFARM_SPRITECOMPONENT_HPP

# include <SFML/Graphics/Sprite.hpp>
# include "BaseRendererComponent.hpp"


namespace game
{

  class SpriteComponent
          : public BaseRendererComponent, public sf::Sprite
  {
// ATTRIBUTES
  private:
  public:

// METHODS:
  public: // CONSTRUCTORS
          SpriteComponent();
          explicit SpriteComponent(
                  const sf::Texture &texture
          );
          SpriteComponent(
                  const sf::Texture &texture,
                  const sf::IntRect &rectangle
          );
          ~SpriteComponent() override = default;
          SpriteComponent(const SpriteComponent &copy) = default;
          SpriteComponent(SpriteComponent &&other) noexcept = default;

  public: // OPERATORS
          SpriteComponent &operator=(const SpriteComponent &other) = default;
          SpriteComponent &operator=(SpriteComponent &&other) = default;

          const sf::Vector2f &getOrigins() const override;
          void setOrigins(float x, float y) override;
          void setOriginCenter() override;

          const sf::Vector2f &getPositions() const override;
          void setPositions(float x, float y) override;

          float getRotations() const override;
          void setRotation(float angle) override;

          const sf::Vector2f &getScales() const override;
          void setScales(float x, float y) override;

  public:
  };

  std::ostream &operator<<(std::ostream &out, const SpriteComponent &);

}

#endif //STARFARM_SPRITECOMPONENT_HPP
