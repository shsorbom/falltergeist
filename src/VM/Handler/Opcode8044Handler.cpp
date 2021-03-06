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
#include "../../VM/Handler/Opcode8044Handler.h"

// C++ standard includes

// Falltergeist includes
#include "../../Logger.h"
#include "../../VM/Script.h"
#include "../../VM/StackValue.h"

// Third party includes

namespace Falltergeist
{
    namespace VM
    {
        namespace Handler
        {
            Opcode8044::Opcode8044(VM::Script* script) : OpcodeHandler(script)
            {
            }

            void Opcode8044::_run()
            {
                Logger::debug("SCRIPT") << "[8044] [*] op_floor" << std::endl;
                auto value = _script->dataStack()->pop();
                int result = 0;
                if (value.type() == StackValue::Type::FLOAT)
                {
                    result = (int)value.floatValue(); // this is how "floor" originally worked..
                }
                else if (value.type() == StackValue::Type::INTEGER)
                {
                    result = value.integerValue();
                }
                else
                {
                    _error(std::string("op_floor: invalid argument type: ") + value.typeName());
                }
                _script->dataStack()->push(result);
            }
        }
    }
}
