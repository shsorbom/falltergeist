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
#include "../Game/SceneryObject.h"

// C++ standard includes

// Falltergeist includes

// Third party includes

namespace Falltergeist
{
    namespace Game
    {
        SceneryObject::SceneryObject() : Object()
        {
            _type = Type::SCENERY;
        }

        void SceneryObject::setSoundId(char soundId)
        {
            this->_soundId = soundId;
        }

        char SceneryObject::soundId() const
        {
            return _soundId;
        }
    }
}
