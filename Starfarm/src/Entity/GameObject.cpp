//
// Created by Tiphaine LAURENT on 29/04/2019.
//

#include "GameObject.hpp"
#include "../Component/TransformComponent.hpp"

namespace game
{
  GameObject::GameObject()
          : _transform(addComponent<TransformComponent>())
  {
  }
}
