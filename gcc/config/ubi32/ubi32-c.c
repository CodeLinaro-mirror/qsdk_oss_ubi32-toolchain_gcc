/* Copyright (C) 2018 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.
*/

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "memmodel.h"
#include "tm_p.h"
#include "cpplib.h"
#include "c-family/c-common.h"
#include "target.h"

#define builtin_define(TXT) cpp_define (pfile, TXT)
#define builtin_assert(TXT) cpp_assert (pfile, TXT)

/* Define preprocessor symbos for Ubi32.  */

void
ubi32_cpu_cpp_builtins (cpp_reader *pfile)
{
  builtin_define_std ("__UBICOM32__");
  builtin_define_std ("__ubicom32__");
  builtin_define_std ("__UBI32__");
  builtin_define_std ("__ubi32__");

  if (ubi32_arch == UBI32_V61)
    {
      builtin_define ("__UBICOM32_V61__");
      builtin_define ("__UBI32_V61__");
    }
  else if (ubi32_arch == UBI32_V6)
    {
      builtin_define ("__UBICOM32_V6__");
      builtin_define ("__UBI32_V6__");
    }
  else if (ubi32_arch == UBI32_V5)
    {
      builtin_define ("__UBICOM32_V5__");
      builtin_define ("__UBI32_V5__");
    }
  else if (ubi32_arch == UBI32_V4)
    {
      builtin_define ("__UBICOM32_V4__");
      builtin_define ("__UBI32_V4__");
    }
  else if (ubi32_arch == UBI32_V3)
    {
      builtin_define ("__UBICOM32_V3__");
      builtin_define ("__UBI32_V3__");
    }
  else
    {
      builtin_define ("__UBICOM32_V2__");
      builtin_define ("__UBI32_V2__");
    }

  if (ubi32_big_endian)
    {
      builtin_define ("__UBICOM32_BIG_ENDIAN__");
      builtin_define ("__BIG_ENDIAN__");
      builtin_define ("__UBI32_BIG_ENDIAN__");
      builtin_define ("__BIG_ENDIAN__");
    }
  else
    {
      builtin_define ("__UBICOM32_LITTLE_ENDIAN__");
      builtin_define ("__LITTLE_ENDIAN__");
      builtin_define ("__UBI32_LITTLE_ENDIAN__");
      builtin_define ("__LITTLE_ENDIAN__");
    }

  if (TARGET_FDPIC)
    {
      builtin_define ("__UBICOM32_FDPIC__");
      builtin_define ("__FDPIC__");
      builtin_define ("__UBI32_FDPIC__");
      builtin_define ("__FDPIC__");
    }

  builtin_define ("NO_TRAMPOLINES");
}
