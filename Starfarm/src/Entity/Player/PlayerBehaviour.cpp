//
// Created by Tiphaine on 19/04/2019.
//

#include <cmath>
#include <SFML/Graphics.hpp>
#include <EntityManager.hpp>
#include "PlayerBehaviour.hpp"
#include "../GameObject.hpp"
#include "../../Component/TransformComponent.hpp"
#include "../../Component/SpriteComponent.hpp"
#include "../Missile/Missile.hpp"


namespace game
{
  PlayerBehaviour::PlayerBehaviour(GameObject *gameObject)
          : MonoBehaviourComponent(gameObject)
  {
  }

  void PlayerBehaviour::update()
  {
          upFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
          downFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
          leftFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
          rightFlag = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

          if (leftFlag) {
                  _transform->move(-_speed, 0);
          }
          if (rightFlag) {
                  _transform->move(_speed, 0);
          }
          if (upFlag) {
                  _transform->move(0, -_speed);
          }
          if (downFlag) {
                  _transform->move(0, _speed);
          }
          _transform->setRotations(0, 0, getAngleMouse());

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                  auto &missile = ecs::EntityManager::createEntity<Missile>();
                  missile._transform->setPositions(_transform->getPositions());
                  missile._transform->setRotations(_transform->getRotations());
          }
  }

  float PlayerBehaviour::getAngleMouse()
  {
          auto mousePosition = sf::Mouse::getPosition();
          auto position = _transform->getPositions();
          auto angle = atan2(
                  mousePosition.y - position.y,
                  mousePosition.x - position.x
          );

          float dx = position.x - mousePosition.x;
          float dy = position.y - mousePosition.y;

          return atan2(dy, dx) * RAD_TO_DEG;
  }

  void PlayerBehaviour::awake()
  {
          _transform->linkToRenderer
                            (_gameObject->getComponent<SpriteComponent>());
          _transform->setPositions(250, 250);
  }
}
