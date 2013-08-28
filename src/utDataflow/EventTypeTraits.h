/*
 * Ubitrack - Library for Ubiquitous Tracking
 * Copyright 2006, Technische Universitaet Muenchen, and individual
 * contributors as indicated by the @authors tag. See the
 * copyright.txt in the distribution for a full listing of individual
 * contributors.
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA, or see the FSF site: http://www.fsf.org.
 */

/**
 * @ingroup dataflow_framework
 * @file
 * Traits for event types. Can be specialized for other event types.
 * The traits tell for each type
 * - how the get the event queue priority
 * - the maximum queue length for events of that type
 *
 * @author Daniel Pustka <daniel.pustka@in.tum.de>
 */

#ifndef __Ubitrack_Dataflow_EventTypeTraits_INCLUDED__
#define __Ubitrack_Dataflow_EventTypeTraits_INCLUDED__

#include <utMeasurement/Timestamp.h>

namespace Ubitrack { namespace Dataflow {

/** default maximum queue length for all data types */
static const int g_defaultMaxQueueLength = 
#ifdef MAXIMUM_EVENTQUEUE_LENGTH
	MAXIMUM_EVENTQUEUE_LENGTH;
#else
	7; // 7 is the default, if not overriden by compiler options
#endif

/**
 * \internal
 * Defines how to extract the priority out of a data type.
 * By default, take the current time.
 */
template< typename T >
struct EventTypeTraits
{
	unsigned long long getPriority( const T& m) const
	//{ return Measurement::now(); }
	{ return m.time(); }

	int getMaxQueueLength() const
	{ return g_defaultMaxQueueLength; }
};

} } // namespace Ubitrack::Dataflow

#endif
