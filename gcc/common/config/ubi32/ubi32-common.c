/* Copyright (C) 2018 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "common/common-target.h"
#include "common/common-target-def.h"
#include "opts.h"
#include "flags.h"
#include "diagnostic-core.h"

enum ubi32_processor 
{
  UBI32_NONE,
  UBI32_IPQ806X,
  UBI32_FSMV4,
  UBI32_FSM90XX,
  UBI32_IPQ807X
};

struct ubi32_processor_t
{
  const char *name;			/* Processor name.  */
  enum ubi32_processor processor;	/* Processor code.  */
};

enum ubi32_processor selected_processor = UBI32_NONE;

static struct ubi32_processor_t ubi32_processor_names[] =
{
  {"ipq806x", UBI32_IPQ806X},
  {"fsm90xx", UBI32_FSM90XX},
  {"ipq807x", UBI32_IPQ807X},
  {NULL,      UBI32_NONE }
};

/* Implement TARGET_HANDLE_OPTION.  */
static bool
ubi32_handle_option (struct gcc_options *opts ATTRIBUTE_UNUSED,
		     struct gcc_options *opts_set ATTRIBUTE_UNUSED,
		     const struct cl_decoded_option *decoded,
		     location_t loc)
{
  size_t code = decoded->opt_index;
  const char *arg = decoded->arg;
  struct ubi32_processor_t *proc;

  switch (code)
    {
/* FIXME:  Is -mcpu used? */
      case OPT_mcpu_:
	for (proc = ubi32_processor_names; proc->name; proc++)
	  if (strcasecmp (proc->name, arg) == 0)
	    {
	      selected_processor = proc->processor;
	      break;
	    }
	if (selected_processor == UBI32_NONE)
	  {
	    warning (0, "-mcpu=%s unrecognized processor", arg);
	    return false;
	  }
    }

  return true;
}

#undef TARGET_DEFAULT_TARGET_FLAGS 
#define TARGET_DEFAULT_TARGET_FLAGS TARGET_DEFAULT

#undef TARGET_HANDLE_OPTION
#define TARGET_HANDLE_OPTION ubi32_handle_option

struct gcc_targetm_common targetm_common = TARGETM_COMMON_INITIALIZER;
