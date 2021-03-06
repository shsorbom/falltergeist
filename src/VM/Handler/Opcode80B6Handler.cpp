/*
 * Copyright 2012-2018 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

// Related headers
#include "../../VM/Handler/Opcode80B6Handler.h"

// C++ standard includes

// Falltergeist includes
#include "../../Game/Game.h"
#include "../../Game/DudeObject.h"
#include "../../Logger.h"
#include "../../PathFinding/Hexagon.h"
#include "../../PathFinding/HexagonGrid.h"
#include "../../State/Location.h"
#include "../../VM/Script.h"

// Third party includes

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode80B6::Opcode80B6(VM::Script* script) : OpcodeHandler(script)
            {
            }

            void Opcode80B6::_run()
            {
                Logger::debug("SCRIPT") << "[80B6] [+] int move_to(GameObject* object, int position, int elevation)" << std::endl;
                auto elevation = _script->dataStack()->popInteger();
                auto position = _script->dataStack()->popInteger();
                auto object = _script->dataStack()->popObject();
                if (!object)
                {
                    _error("move_to: object is NULL");
                }
                auto hexagon = Game::getInstance()->locationState()->hexagonGrid()->at(position);
                Game::getInstance()->locationState()->moveObjectToHexagon(object, hexagon);
                object->setElevation(elevation);
                if (object == Game::getInstance()->player().get()) {
                    Game::getInstance()->locationState()->centerCameraAtHexagon(object->hexagon());
                }
                _script->dataStack()->push(0);
            }
        }
    }
}
