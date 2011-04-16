/*
 * scstudio - Sequence Chart Studio
 * http://scstudio.sourceforge.net
 *
 *      This library is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU Lesser General Public
 *      License version 2.1, as published by the Free Software Foundation.
 *
 *      This library is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *      Lesser General Public License for more details.
 *
 * Copyright (c) 2008 Petr Gotthard <petr.gotthard@centrum.cz>
 *
 * $Id: export.h 540 2010-01-04 08:11:28Z gotthardp $
 */

#ifndef _SCMEMBERSHIP_EXPORT_H
#define _SCMEMBERSHIP_EXPORT_H

#if defined(_MSC_VER)
#pragma warning(disable: 4251)

#if defined(scmembership_EXPORTS)
#define SCMEMBERSHIP_EXPORT __declspec(dllexport)
#else
#define SCMEMBERSHIP_EXPORT __declspec(dllimport)
#endif

#else
#define SCMEMBERSHIP_EXPORT
#endif

#endif /* _SCMEMBERSHIP_EXPORT_H */

// $Id: export.h 540 2010-01-04 08:11:28Z gotthardp $
