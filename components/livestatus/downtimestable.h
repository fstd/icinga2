/******************************************************************************
 * Icinga 2                                                                   *
 * Copyright (C) 2012 Icinga Development Team (http://www.icinga.org/)        *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software Foundation     *
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.             *
 ******************************************************************************/

#ifndef DOWNTIMESTABLE_H
#define DOWNTIMESTABLE_H

#include "livestatus/table.h"

using namespace icinga;

namespace livestatus
{

/**
 * @ingroup livestatus
 */
class DowntimesTable : public Table
{
public:
	DECLARE_PTR_TYPEDEFS(DowntimesTable);

	DowntimesTable(void);

	static void AddColumns(Table *table, const String& prefix = String(),
	    const Column::ObjectAccessor& objectAccessor = Column::ObjectAccessor());

	virtual String GetName(void) const;

protected:
	virtual void FetchRows(const AddRowFunction& addRowFn);

	static Value AuthorAccessor(const Object::Ptr& object);
	static Value CommentAccessor(const Object::Ptr& object);
	static Value IdAccessor(const Object::Ptr& object);
	static Value EntryTimeAccessor(const Object::Ptr& object);
	static Value TypeAccessor(const Object::Ptr& object);
	static Value IsServiceAccessor(const Object::Ptr& object);
	static Value StartTimeAccessor(const Object::Ptr& object);
	static Value EndTimeAccessor(const Object::Ptr& object);
	static Value FixedAccessor(const Object::Ptr& object);
	static Value DurationAccessor(const Object::Ptr& object);
	static Value TriggeredByAccessor(const Object::Ptr& object);
};

}

#endif /* DOWNTIMESTABLE_H */
