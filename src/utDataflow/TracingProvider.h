//
// Created by Ulrich Eck on 18/08/2015.
//

#ifndef UBITACK_TRACINGPROVIDER_H
#define UBITACK_TRACINGPROVIDER_H

#if defined(HAVE_DTRACE) && !defined(DISABLE_DTRACE)
#include "utDataflow/probes_ubitrack_dtrace.h"
#else
#include "utDataflow/probes_ubitrack_nodtrace.h"
#endif

#endif //UBITACK_TRACINGPROVIDER_H
