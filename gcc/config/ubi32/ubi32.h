/* Definitions of target machine for Ubi32

   Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008,
   2009 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#define TARGET_DEFAULT (MASK_SOFT_FLOAT)

/* Names to predefine in the preprocessor for this target machine.  */
#define TARGET_CPU_CPP_BUILTINS() ubi32_cpu_cpp_builtins (pfile)

extern int ubi32_case_values_threshold;

/* Nonzero if this chip supports the Ubi32 v3 ISA.  */
extern int ubi32_v3;

/* Nonzero if this chip supports the Ubi32 v4 ISA.  */
extern int ubi32_v4;

/* Nonzero if this chip supports the Ubi32 v5 ISA.  */
extern int ubi32_v5;

/* Nonzero if this chip supports the Ubi32 v6 ISA.  */
extern int ubi32_v6;

/* Nonzero if this chip supports the Ubi32 v61 ISA.  */
extern int ubi32_v61;

/* Nonzero if the chip is big-endian.  */
extern int ubi32_big_endian;

/* ACC hi and low register numbers.  */
extern unsigned int ubi32_acc0_lo_regnum;
extern unsigned int ubi32_acc0_hi_regnum;
extern unsigned int ubi32_acc1_lo_regnum;
extern unsigned int ubi32_acc1_hi_regnum;

/* Which processor to generate code or schedule for. The cpu attribute
   defines a list that mirrors this list, so changes to ubi32.md must be
   made at the same time.  */

enum ubi32_processor_type
{
  UBI32_V2,
  UBI32_V3,
  UBI32_V4,
  UBI32_V5,
  UBI32_V6,
  UBI32_V61
};

extern enum ubi32_processor_type ubi32_arch;

/* Recast the cpu class to be the cpu attribute.  */
#define ubi32_arch_attr ((enum attr_arch) ubi32_arch)

/* For Ubi32 the least significant bit has the lowest bit number
   so we define this to be 0.  */
#define BITS_BIG_ENDIAN 0

/* Most ubi32 variants are big-endian but v6 switched to
   little-endian.  */
#define BYTES_BIG_ENDIAN (ubi32_big_endian != 0)
#define WORDS_BIG_ENDIAN BYTES_BIG_ENDIAN

/* Ubi32 has 32 bits per word.  */
#define BITS_PER_WORD 32

/* Width of a word, in units (bytes).  */
#define UNITS_PER_WORD 4

/* Width of a pointer, in bits.  */
#define POINTER_SIZE 32

/* Alias for pointers.  Ubi32 is a 32-bit architecture so we use
   SImode.  */
#define Pmode SImode

/* Normal alignment required for function parameters on the stack, in
   bits.  */
#define PARM_BOUNDARY 32

/* We need to maintain the stack on a 32-bit boundary.  */
#define STACK_BOUNDARY 32

/* Alignment required for a function entry point, in bits.  */
#define FUNCTION_BOUNDARY 32

/* Alias for the machine mode used for memory references to functions being
   called, in `call' RTL expressions.  We use byte-oriented addresses
   here.  */
#define FUNCTION_MODE QImode

/* Biggest alignment that any data type can require on this machine,
   in bits.  */
#define BIGGEST_ALIGNMENT 32

/* Alignment in bits to be given to a structure bit field that follows an empty
   field such as `int : 0;'.  */
#define EMPTY_FIELD_BOUNDARY 32

/* All structures must be a multiple of 8 bits in size.  This means that we
   have optimal packing based on the natural alignment of the largest field
   of the structure.  */
#define STRUCTURE_SIZE_BOUNDARY 8

/* For Ubi32 we absolutely require that data be aligned with nominal
   alignment.  */
#define STRICT_ALIGNMENT 1

/* Define this macro as an expression for the alignment of a structure
   (given by STRUCT as a tree node) if the alignment computed in the
   usual way is COMPUTED and the alignment explicitly specified was
   SPECIFIED. */
#define DATA_ALIGNMENT(TYPE, ALIGN)					\
  ((((ALIGN) < BITS_PER_WORD)						\
    && (! TARGET_MIN_DATA_ALIGN)					\
    && (TREE_CODE (TYPE) == ARRAY_TYPE					\
	|| TREE_CODE (TYPE) == UNION_TYPE				\
	|| TREE_CODE (TYPE) == RECORD_TYPE)) ? BITS_PER_WORD : (ALIGN))

#define LOCAL_ALIGNMENT(TYPE, ALIGN) DATA_ALIGNMENT(TYPE, ALIGN)

/* For Ubi32 we default to unsigned chars.  */
#define DEFAULT_SIGNED_CHAR 0

/* Register numbers used for passing a function's static chain pointer.  If
   register windows are used, the register number as seen by the called
   function is `STATIC_CHAIN_INCOMING_REGNUM', while the register number as
   seen by the calling function is `STATIC_CHAIN_REGNUM'.  If these registers
   are the same, `STATIC_CHAIN_INCOMING_REGNUM' need not be defined.

   The static chain register need not be a fixed register.

   If the static chain is passed in memory, these macros should not be defined;
   instead, the next two macros should be defined.  */
#define STATIC_CHAIN_REGNUM (FIRST_ADDRESS_REGNUM + 1)

/* The register number of the frame pointer register, which is used to access
   automatic variables in the stack frame.  We generally eliminate this anyway
   for Ubi32 but we make it A6 by default.  */
#define HARD_FRAME_POINTER_REGNUM (A6_REGNUM)

/* Soft base register for access to local variables of the function.  */
#define FRAME_POINTER_REGNUM 39

/* The register number of the stack pointer register, which is also be a
   fixed register according to `FIXED_REGISTERS'.  For Ubi32 we don't
   have a hardware requirement about which register this is, but by convention
   we use A7.  */
#define STACK_POINTER_REGNUM (SP_REGNUM)

/* The register number of the arg pointer register, which is used to access the
   function's argument list.  On some machines, this is the same as the frame
   pointer register.  On some machines, the hardware determines which register
   this is.  On other machines, you can choose any register you wish for this
   purpose.  If this is not the same register as the frame pointer register,
   then you must mark it as a fixed register according to `FIXED_REGISTERS', or
   arrange to be able to eliminate it.  */
#define ARG_POINTER_REGNUM 29

/* Interrupt set/clear registers.  */
#define INT_SET0_REGNUM 31
#define INT_SET1_REGNUM 32
#define INT_CLR0_REGNUM 33
#define INT_CLR1_REGNUM 34

/* Scratchpad registers.  */
#define SCRATCHPAD0_REGNUM 35
#define SCRATCHPAD1_REGNUM 36
#define SCRATCHPAD2_REGNUM 37
#define SCRATCHPAD3_REGNUM 38

/* Number of hardware registers known to the compiler.  They receive numbers 0
   through `FIRST_PSEUDO_REGISTER-1'; thus, the first pseudo register's number
   really is assigned the number `FIRST_PSEUDO_REGISTER'.  */
#define FIRST_PSEUDO_REGISTER 40

/* An initializer that says which registers are used for fixed purposes all
   throughout the compiled code and are therefore not available for general
   allocation.  These would include the stack pointer, the frame pointer
   (except on machines where that can be used as a general register when no
   frame pointer is needed), the program counter on machines where that is
   considered one of the addressable registers, and any other numbered register
   with a standard use.

   This information is expressed as a sequence of numbers, separated by commas
   and surrounded by braces.  The Nth number is 1 if register N is fixed, 0
   otherwise.

   The table initialized from this macro, and the table initialized by the
   following one, may be overridden at run time either automatically, by the
   actions of the macro `CONDITIONAL_REGISTER_USAGE', or by the user with the
   command options `-ffixed-REG', `-fcall-used-REG' and `-fcall-saved-REG'.  */
#define FIXED_REGISTERS					\
  {							\
    0, 0, 0, 0, 0, 0, 0, 0,	/* d0 - d7 */		\
    0, 0, 0, 0, 0, 0, 0, 1,	/* d8 - d15 */		\
    0, 0, 0, 0, 0, 0, 0, 1,	/* a0 - a7 */		\
    0, 0,			/* acc0 hi/lo */	\
    0, 0,			/* acc1 hi/lo */	\
    0,				/* source3 */		\
    1,				/* arg */		\
    1,				/* cc */		\
    1, 1,			/* int_set[01] */	\
    1, 1,			/* int_clr[01] */	\
    1, 1, 1, 1,			/* scratchpad[0123] */	\
    1				/* sfp */		\
  }

/* Like `FIXED_REGISTERS' but has 1 for each register that is clobbered (in
   general) by function calls as well as for fixed registers.  This macro
   therefore identifies the registers that are not available for general
   allocation of values that must live across function calls.

   If a register has 0 in `CALL_USED_REGISTERS', the compiler automatically
   saves it on function entry and restores it on function exit, if the register
   is used within the function.

   One interesting case here is A5.  Strictly it's not actually saved when
   we make a function call because we set it immediately before we make
   a function call!  */
#define CALL_USED_REGISTERS				\
  {							\
    1, 1, 1, 1, 1, 1, 1, 1,	/* d0 - d7 */		\
    1, 1, 0, 0, 0, 0, 1, 1,	/* d8 - d15 */		\
    1, 0, 0, 1, 1, 0, 0, 1,	/* a0 - a7 */		\
    1, 1,			/* acc0 hi/lo */	\
    1, 1,			/* acc1 hi/lo */	\
    1,				/* source3 */		\
    1,				/* arg */		\
    1,				/* cc */		\
    1, 1,			/* int_set[01] */	\
    1, 1,			/* int_clr[01] */	\
    1, 1, 1, 1,			/* scratchpad[0123] */	\
    1				/* sfp */		\
  }

/* How to refer to registers in assembler output.
   This sequence is indexed by compiler's hard-register-number (see above).  */

/* A C initializer containing the assembler's names for the machine registers,
   each one as a C string constant.  This is what translates register numbers
   in the compiler into assembler language.  */
#define REGISTER_NAMES						\
  {								\
    "d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",		\
    "d8", "d9", "d10", "d11", "d12", "d13", "d14", "d15",	\
    "a0", "a1", "a2", "a3", "a4", "a5", "a6", "sp",		\
    "acc0_hi", "acc0_lo",					\
    "acc1_hi", "acc1_lo",					\
    "source3",							\
    "arg",							\
    "cc",							\
    "int_set0", "int_set1",					\
    "int_clr0", "int_clr1",					\
    "scratchpad0", "scratchpad1", "scratchpad2", "scratchpad3",	\
    "sfp"							\
  }

/* Register aliases.  Only valid for Big Endian.  */
#define ADDITIONAL_REGISTER_NAMES				\
  {								\
    {"a7", 23},							\
    {"mac_hi", 24},						\
    {"mac_lo", 25}						\
  }

/* Order of allocation of registers.  */

/* If defined, an initializer for a vector of integers, containing the numbers
   of hard registers in the order in which GNU CC should prefer to use them
   (from most preferred to least).

   For Ubi32 we try using caller-clobbered data registers first, then
   callee-saved data registers, then caller-clobbered address registers,
   then callee-saved address registers and finally everything else.

   The caller-clobbered registers are usually slightly cheaper to use because
   there's no need to save/restore.
   
   Note that A5 is preferred of the callee-saved registers because we can
   often use a shorter sequence to return from functions where we use it.  */
#define REG_ALLOC_ORDER						\
  {								\
    0, 1, 2, 3, 4,		/* d0 - d4 */			\
    5, 6, 7, 8, 9,		/* d5 - d9 */			\
    14,				/* d14 */			\
    10, 11, 12, 13,		/* d10 - d13 */			\
    19, 20, 16,			/* a3, a4, a0 */		\
    21, 22, 17, 18,		/* a5, a6, a1, a2 */		\
    24, 25,			/* acc0 hi/lo */		\
    26, 27,			/* acc0 hi/lo */		\
    28,				/* source3 */			\
    39				/* sfp */			\
  }

/* We can't always rename all registers!  */
#define HARD_REGNO_RENAME_OK(FROM, TO) \
  ubi32_hard_regno_rename_ok (FROM, TO)

/* An enumeral type that must be defined with all the register class names as
   enumeral values.  `NO_REGS' must be first.  `ALL_REGS' must be the last
   register class, followed by one more enumeral value, `LIM_REG_CLASSES',
   which is not a register class but rather tells how many classes there are.

   Each register class has a number, which is the value of casting the class
   name to type `int'.  The number serves as an index in many of the tables
   described below.  */

enum reg_class
{
  NO_REGS,
  DATA_REGS,
  LINK_REG,
  SIBCALL_ADDRESS_REGS,
  ADDRESS_REGS,
  FDPIC_REG,
  ALL_ADDRESS_REGS,
  ACC_LO_REGS,
  ACC_REGS,
  CC_REG,
  DATA_ACC_REGS,
  SOURCE3_REG,
  SPECIAL_REGS,
  GENERAL_REGS,
  ALL_REGS,
  LIM_REG_CLASSES
};

/* The number of distinct register classes.  */
#define N_REG_CLASSES (int) LIM_REG_CLASSES

/* An initializer containing the names of the register classes as C string
   constants.  These names are used in writing some of the debugging dumps.  */

#define REG_CLASS_NAMES		\
{				\
  "NO_REGS",			\
  "DATA_REGS",			\
  "LINK_REG",			\
  "SIBCALL_ADDRESS_REGS",	\
  "ADDRESS_REGS",		\
  "FDPIC_REG",			\
  "ALL_ADDRESS_REGS",		\
  "ACC_LO_REGS",		\
  "ACC_REGS",			\
  "CC_REG",			\
  "DATA_ACC_REGS",		\
  "SOURCE3_REG",		\
  "SPECIAL_REGS",		\
  "GENERAL_REGS",		\
  "ALL_REGS",			\
  "LIM_REGS"			\
}

/* An initializer containing the contents of the register classes, as integers
   which are bit masks.  The Nth integer specifies the contents of class N.
   The way the integer MASK is interpreted is that register R is in the class
   if `MASK & (1 << R)' is 1.

   When the machine has more than 32 registers, an integer does not suffice.
   Then the integers are replaced by sub-initializers, braced groupings
   containing several integers.  Each sub-initializer must be suitable as an
   initializer for the type `HARD_REG_SET' which is defined in
   `hard-reg-set.h'.  */
#define REG_CLASS_CONTENTS					\
{								\
  {0x00000000, 0x00000000},	/* No regs */			\
  {0x0000ffff, 0x00000000},	/* DATA_REGS */			\
  {0x00200000, 0x00000000},	/* LINK_REG */			\
  {0x00180000, 0x00000000},	/* SIBCALL_ADDRESS_REGS */	\
  {0x20fe0000, 0x00000080},	/* ADDRESS_REGS */		\
  {0x00010000, 0x00000000},	/* FDPIC_REG */			\
  {0x20ff0000, 0x00000080},	/* ALL_ADDRESS_REGS */		\
  {0x0a000000, 0x00000000},	/* ACC_LO_REGS */		\
  {0x0f000000, 0x00000000},	/* ACC_REGS */			\
  {0x40000000, 0x00000000},	/* CC_REG */			\
  {0x0f00ffff, 0x00000000},	/* DATA_ACC_REGS */		\
  {0x10000000, 0x00000000},	/* SOURGE3_REG */		\
  {0x80000000, 0x0000007f},	/* SPECIAL_REGS */		\
  {0xbfffffff, 0x000000ff},	/* GENERAL_REGS */		\
  {0xbfffffff, 0x000000ff}	/* ALL_REGS	*/		\
}

extern enum reg_class const ubi32_regclass_map[FIRST_PSEUDO_REGISTER];

/* A C expression whose value is a register class containing hard register
   REGNO.  In general there is more than one such class; choose a class which
   is "minimal", meaning that no smaller class also contains the register.  */
#define REGNO_REG_CLASS(REGNO) (ubi32_regclass_map[REGNO])

/* Ubi32 base registers must be address registers since addresses can
   only be reached via address registers.  */
#define BASE_REG_CLASS ALL_ADDRESS_REGS

/* Ubi32 index registers must be data registers since we cannot add
   two address registers together to form an address.  */
#define INDEX_REG_CLASS DATA_REGS

/* A C expression which is nonzero if register number NUM is suitable for use
   as a base register in operand addresses.  It may be either a suitable hard
   register or a pseudo register that has been allocated such a hard register.  */

#ifndef REG_OK_STRICT
#define REGNO_OK_FOR_BASE_P(regno) \
  ubi32_regno_ok_for_base_p (regno, 0)
#else
#define REGNO_OK_FOR_BASE_P(regno) \
  ubi32_regno_ok_for_base_p (regno, 1)
#endif

/* A C expression which is nonzero if register number NUM is suitable for use
   as an index register in operand addresses.  It may be either a suitable hard
   register or a pseudo register that has been allocated such a hard register.

   The difference between an index register and a base register is that the
   index register may be scaled.  If an address involves the sum of two
   registers, neither one of them scaled, then either one may be labeled the
   "base" and the other the "index"; but whichever labeling is used must fit
   the machine's constraints of which registers may serve in each capacity.
   The compiler will try both labelings, looking for one that is valid, and
   will reload one or both registers only if neither labeling works.  */
#ifndef REG_OK_STRICT
#define REGNO_OK_FOR_INDEX_P(regno) \
  ubi32_regno_ok_for_index_p (regno, 0)
#else
#define REGNO_OK_FOR_INDEX_P(regno) \
  ubi32_regno_ok_for_index_p (regno, 1)
#endif

/* Attempt to restrict the register class we need to copy value X intoto the
   would-be register class CLASS.  Most things are fine for Ubi32 but we
   have to restrict certain types of address loads.  */
#define PREFERRED_RELOAD_CLASS(X, CLASS) \
  ubi32_preferred_reload_class (X, CLASS)

/* For Ubi32 the stack grows downwards when we push a word onto the stack
   - i.e. it moves to a smaller address.  */
#define STACK_GROWS_DOWNWARD 1

/* Offset from the argument pointer register to the first argument's
   address.  */
#define FIRST_PARM_OFFSET(FNDECL) 0

/* A C expression whose value is RTL representing the value of the return
   address for the frame COUNT steps up from the current frame, after the
   prologue.  FRAMEADDR is the frame pointer of the COUNT frame, or the frame
   pointer of the COUNT - 1 frame if `RETURN_ADDR_IN_PREVIOUS_FRAME' is
   defined.

   The value of the expression must always be the correct address when COUNT is
   zero, but may be `NULL_RTX' if there is not way to determine the return
   address of other frames.  */
#define RETURN_ADDR_RTX(COUNT, FRAME) \
  ubi32_return_addr_rtx (COUNT, FRAME)

/* Register That Address the Stack Frame.  */

/* Macro that defines a table of register pairs used to eliminate unecessary
   registers that point into the stack frame.

   For Ubi32 we don't generally need an arg pointer of a frame pointer
   so we allow the arg pointer to be replaced by either the frame pointer or
   the stack pointer.  We also allow the frame pointer to be replaced by
   the stack pointer.  */
#define ELIMINABLE_REGS					\
{							\
  {HARD_FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},	\
  {FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},		\
  {FRAME_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM},	\
  {ARG_POINTER_REGNUM,	 STACK_POINTER_REGNUM},		\
  {ARG_POINTER_REGNUM,	 HARD_FRAME_POINTER_REGNUM},	\
}

/* This macro is similar to `INITIAL_FRAME_POINTER_OFFSET'.  It specifies the
   initial difference between the specified pair of registers.  This macro must
   be defined if `ELIMINABLE_REGS' is defined.  */
#define INITIAL_ELIMINATION_OFFSET(FROM, TO, OFFSET) \
  (OFFSET) = ubi32_initial_elimination_offset (FROM, TO)

/* If defined, the maximum amount of space required for outgoing arguments will
   be computed and placed into the variable
   `current_function_outgoing_args_size'.  No space will be pushed onto the
   stack for each call; instead, the function prologue should increase the
   stack frame size by this amount.

   Defining both `PUSH_ROUNDING' and `ACCUMULATE_OUTGOING_ARGS' is not
   proper.  */
#define ACCUMULATE_OUTGOING_ARGS 1

/* Define this macro if functions should assume that stack space has been
   allocated for arguments even when their values are passed in registers.

   The value of this macro is the size, in bytes, of the area reserved for
   arguments passed in registers for the function represented by FNDECL.

   This space can be allocated by the caller, or be a part of the
   machine-dependent stack frame: `OUTGOING_REG_PARM_STACK_SPACE' says
   which.  */
#define REG_PARM_STACK_SPACE(FNDECL) 0

/* A C expression that controls whether a function argument is passed in a
   register, and which register.

   The arguments are CUM, of type CUMULATIVE_ARGS, which summarizes (in a way
   defined by INIT_CUMULATIVE_ARGS and FUNCTION_ARG_ADVANCE) all of the previous
   arguments so far passed in registers; MODE, the machine mode of the argument;
   TYPE, the data type of the argument as a tree node or 0 if that is not known
   (which happens for C support library functions); and NAMED, which is 1 for an
   ordinary argument and 0 for nameless arguments that correspond to `...' in the
   called function's prototype.

   The value of the expression should either be a `reg' RTX for the hard
   register in which to pass the argument, or zero to pass the argument on the
   stack.

   For machines like the Vax and 68000, where normally all arguments are
   pushed, zero suffices as a definition.

   The usual way to make the ANSI library `stdarg.h' work on a machine where
   some arguments are usually passed in registers, is to cause nameless
   arguments to be passed on the stack instead.  This is done by making
   `FUNCTION_ARG' return 0 whenever NAMED is 0.

   You may use the macro `MUST_PASS_IN_STACK (MODE, TYPE)' in the definition of
   this macro to determine if this argument is of a type that must be passed in
   the stack.  If `REG_PARM_STACK_SPACE' is not defined and `FUNCTION_ARG'
   returns non-zero for such an argument, the compiler will abort.  If
   `REG_PARM_STACK_SPACE' is defined, the argument will be computed in the
   stack and then loaded into a register.  */
/* Define a data type for recording info about an argument list
   during the scan of that argument list.  This data type should
   hold all necessary information about the function itself
   and about the args processed so far, enough to enable macros
   such as FUNCTION_ARG to determine where the next arg should go.  */
typedef struct ubi32_args
{
  int nbytes;
} CUMULATIVE_ARGS;

/* Initialize a variable CUM of type CUMULATIVE_ARGS
   for a call to a function whose data type is FNTYPE.
   For a library call, FNTYPE is 0.  */
#define INIT_CUMULATIVE_ARGS(CUM, FNTYPE, LIBNAME, FNDECL, N_NAMED_ARGS) \
  ubi32_init_cumulative_args (&(CUM), (FNTYPE), (LIBNAME));

/* For the Ubi32 we define the upper function argument register here.  */
#define UBI32_FUNCTION_ARG_REGS 10

/* A C expression that is nonzero if REGNO is the number of a hard register in
   which function arguments are sometimes passed.  This does *not* include
   implicit arguments such as the static chain and the structure-value address.
   On many machines, no registers can be used for this purpose since all
   function arguments are pushed on the stack.  */
#define FUNCTION_ARG_REGNO_P(N)				\
   (((N) < UBI32_FUNCTION_ARG_REGS)			\
    || (TARGET_FDPIC && (N) == FDPIC_REGNUM))

/* How Scalar Function Values are Returned.  */

/* The number of the hard register that is used to return a scalar value from a
   function call.  */
#define RETURN_VALUE_REGNUM 0

/* A C expression to create an RTX representing the place where a function
   returns a value of data type VALTYPE.  VALTYPE is a tree node representing a
   data type.  Write `TYPE_MODE (VALTYPE)' to get the machine mode used to
   represent that type.  On many machines, only the mode is relevant.
   (Actually, on most machines, scalar values are returned in the same place
   regardless of mode).

   If `PROMOTE_FUNCTION_RETURN' is defined, you must apply the same promotion
   rules specified in `PROMOTE_MODE' if VALTYPE is a scalar type.

   If the precise function being called is known, FUNC is a tree node
   (`FUNCTION_DECL') for it; otherwise, FUNC is a null pointer.  This makes it
   possible to use a different value-returning convention for specific
   functions when all their calls are known.

   `FUNCTION_VALUE' is not used for return vales with aggregate data types,
   because these are returned in another way.  See `STRUCT_VALUE_REGNUM' and
   related macros, below.  */
#define FUNCTION_VALUE(VALTYPE, FUNC) \
  gen_rtx_REG (TYPE_MODE (VALTYPE), FIRST_DATA_REGNUM)

/* A C expression to create an RTX representing the place where a library
   function returns a value of mode MODE.

   Note that "library function" in this context means a compiler support
   routine, used to perform arithmetic, whose name is known specially by the
   compiler and was not mentioned in the C code being compiled.

   The definition of `LIBRARY_VALUE' need not be concerned aggregate data
   types, because none of the library functions returns such types.  */
#define LIBCALL_VALUE(MODE) gen_rtx_REG (MODE, FIRST_DATA_REGNUM)

/* A C expression that is nonzero if REGNO is the number of a hard register in
   which the values of called function may come back.

   A register whose use for returning values is limited to serving as the
   second of a pair (for a value of type `double', say) need not be recognized
   by this macro.  So for most machines, this definition suffices:

	#define FUNCTION_VALUE_REGNO_P(N) ((N) == RETURN)

   If the machine has register windows, so that the caller and the called
   function use different registers for the return value, this macro should
   recognize only the caller's register numbers.  */
#define FUNCTION_VALUE_REGNO_P(N) ((N) == FIRST_DATA_REGNUM)


/* How Large Values are Returned.  */

/* A C expression which can inhibit the returning of certain function values in
   registers, based on the type of value.  A nonzero value says to return the
   function value in memory, just as large structures are always returned.
   Here TYPE will be a C expression of type `tree', representing the data type
   of the value.

   Note that values of mode `BLKmode' must be explicitly handled by this macro.
   Also, the option `-fpcc-struct-return' takes effect regardless of this
   macro.  On most systems, it is possible to leave the macro undefined; this
   causes a default definition to be used, whose value is the constant 1 for
   `BLKmode' values, and 0 otherwise.

   Do not use this macro to indicate that structures and unions should always
   be returned in memory.  You should instead use `DEFAULT_PCC_STRUCT_RETURN'
   to indicate this.  */
#define RETURN_IN_MEMORY(TYPE)  \
  (int_size_in_bytes (TYPE) > 8 || TYPE_MODE (TYPE) == BLKmode)

/* Define this macro to be 1 if all structure and union return values must be
   in memory.  Since this results in slower code, this should be defined only
   if needed for compatibility with other compilers or with an ABI.  If you
   define this macro to be 0, then the conventions used for structure and union
   return values are decided by the `RETURN_IN_MEMORY' macro.

   If not defined, this defaults to the value 1.  */
#define DEFAULT_PCC_STRUCT_RETURN 0

#ifdef FIXME_DELETED
/*   If the structure value address is not passed in a register, define
     `STRUCT_VALUE' as an expression returning an RTX for the place
     where the address is passed.  If it returns 0, the address is
     passed as an "invisible" first argument.  */
#define STRUCT_VALUE 0
#endif

/* Define this macro as a C expression that is nonzero if the return
   instruction or the function epilogue ignores the value of the stack pointer;
   in other words, if it is safe to delete an instruction to adjust the stack
   pointer before a return from the function.

   Note that this macro's value is relevant only for functions for which frame
   pointers are maintained.  It is never safe to delete a final stack
   adjustment in a function that has no frame pointer, and the compiler knows
   this regardless of `EXIT_IGNORE_STACK'.  */
#define EXIT_IGNORE_STACK 1

/* A C statement or compound statement to output to FILE some assembler code to
   call the profiling subroutine `mcount'.  Before calling, the assembler code
   must load the address of a counter variable into a register where `mcount'
   expects to find the address.  The name of this variable is `LP' followed by
   the number LABELNO, so you would generate the name using `LP%d' in a
   `fprintf'.

   The details of how the address should be passed to `mcount' are determined
   by your operating system environment, not by GNU CC.  To figure them out,
   compile a small program for profiling using the system's installed C
   compiler and look at the assembler code that results.

   This declaration must be present, but it can be an abort if profiling is
   not implemented.  */

#define FUNCTION_PROFILER(FILE, LABELNO) do { } while (0)

/* We don't currently support trampolines.  */
#define TRAMPOLINE_SIZE 0

/* Ubi32 supports pre and post increment/decrement addressing.  */
#define HAVE_POST_INCREMENT 1
#define HAVE_PRE_INCREMENT 1
#define HAVE_POST_DECREMENT 1
#define HAVE_PRE_DECREMENT 1

/* Ubi32 supports pre and post address side-effects with constants
   other than the size of the memory operand.  */
#define HAVE_PRE_MODIFY_DISP 1
#define HAVE_POST_MODIFY_DISP 1

/* Even though we do support a full set of pre/post inc/dec addressing
   we really don't want to use these when we do memcpy() or memset()
   operations since they cause problems with fwprop1 and offset-based
   addressing works fine in the vast majority of cases.  */
#define USE_LOAD_POST_INCREMENT(mode) 0
#define USE_LOAD_POST_DECREMENT(mode) 0
#define USE_LOAD_PRE_INCREMENT(mode) 0
#define USE_LOAD_PRE_DECREMENT(mode) 0
#define USE_STORE_POST_INCREMENT(mode) 0
#define USE_STORE_POST_DECREMENT(mode) 0
#define USE_STORE_PRE_INCREMENT(mode) 0
#define USE_STORE_PRE_DECREMENT(mode) 0

/* A C expression that is 1 if the RTX X is a constant which is a valid
   address.  On most machines, this can be defined as `CONSTANT_P (X)',
   but a few machines are more restrictive in which constant addresses
   are supported.

   `CONSTANT_P' accepts integer-values expressions whose values are not
   explicitly known, such as `symbol_ref', `label_ref', and `high'
   expressions and `const' arithmetic expressions, in addition to
   `const_int' and `const_double' expressions.  */
#define CONSTANT_ADDRESS_P(X)						\
  (GET_CODE (X) == LABEL_REF						\
   || (GET_CODE (X) == CONST						\
       && GET_CODE (XEXP (X, 0)) == PLUS				\
       && GET_CODE (XEXP (XEXP (X, 0), 0)) == LABEL_REF))

/* Ubi32 supports a maximum of 2 registers in a valid memory address.
   One is always an address register while a second, optional, one may be a
   data register.  */
#define MAX_REGS_PER_ADDRESS 2

/* A C compound statement with a conditional `goto LABEL;' executed if X (an
   RTX) is a legitimate memory address on the target machine for a memory
   operand of mode MODE.

   It usually pays to define several simpler macros to serve as subroutines for
   this one.  Otherwise it may be too complicated to understand.

   This macro must exist in two variants: a strict variant and a non-strict
   one.  The strict variant is used in the reload pass.  It must be defined so
   that any pseudo-register that has not been allocated a hard register is
   considered a memory reference.  In contexts where some kind of register is
   required, a pseudo-register with no hard register must be rejected.

   The non-strict variant is used in other passes.  It must be defined to
   accept all pseudo-registers in every context where some kind of register is
   required.

   Compiler source files that want to use the strict variant of this macro
   define the macro `REG_OK_STRICT'.  You should use an `#ifdef REG_OK_STRICT'
   conditional to define the strict variant in that case and the non-strict
   variant otherwise.

   Subroutines to check for acceptable registers for various purposes (one for
   base registers, one for index registers, and so on) are typically among the
   subroutines used to define `GO_IF_LEGITIMATE_ADDRESS'.  Then only these
   subroutine macros need have two variants; the higher levels of macros may be
   the same whether strict or not.

   Normally, constant addresses which are the sum of a `symbol_ref' and an
   integer are stored inside a `const' RTX to mark them as constant.
   Therefore, there is no need to recognize such sums specifically as
   legitimate addresses.  Normally you would simply recognize any `const' as
   legitimate.

   Usually `PRINT_OPERAND_ADDRESS' is not prepared to handle constant sums that
   are not marked with `const'.  It assumes that a naked `plus' indicates
   indexing.  If so, then you *must* reject such naked constant sums as
   illegitimate addresses, so that none of them will be given to
   `PRINT_OPERAND_ADDRESS'.

   On some machines, whether a symbolic address is legitimate depends on the
   section that the address refers to.  On these machines, define the macro
   `ENCODE_SECTION_INFO' to store the information into the `symbol_ref', and
   then check for it here.  When you see a `const', you will have to look
   inside it to find the `symbol_ref' in order to determine the section.

   The best way to modify the name string is by adding text to the beginning,
   with suitable punctuation to prevent any ambiguity.  Allocate the new name
   in `saveable_obstack'.  You will have to modify `ASM_OUTPUT_LABELREF' to
   remove and decode the added text and output the name accordingly, and define
   `STRIP_NAME_ENCODING' to access the original name string.

   You can check the information stored here into the `symbol_ref' in the
   definitions of the macros `GO_IF_LEGITIMATE_ADDRESS' and
   `PRINT_OPERAND_ADDRESS'.

   On the ubi32, the value in the address register must be
   in the same memory space/segment as the effective address.

   This is problematical for reload since it does not understand
   that base+index != index+base in a memory reference.  */
#ifdef REG_OK_STRICT
#define GO_IF_LEGITIMATE_ADDRESS(MODE, X, ADDR)	\
  if (ubi32_legitimate_address_p (MODE, X, 1)) goto ADDR;
#else
#define GO_IF_LEGITIMATE_ADDRESS(MODE, X, ADDR)	\
  if (ubi32_legitimate_address_p (MODE, X, 0)) goto ADDR;
#endif

/* Try a machine-dependent way of reloading an illegitimate address
   operand.  If we find one, push the reload and jump to WIN.  This
   macro is used in only one place: `find_reloads_address' in reload.c.  */
#define LEGITIMIZE_RELOAD_ADDRESS(AD, MODE, OPNUM, TYPE, IND, WIN)	\
{									\
  rtx new_rtx = ubi32_legitimize_reload_address ((AD), (MODE), (OPNUM), (int)(TYPE));	\
  if (new_rtx)								\
    {									\
      (AD) = new_rtx;							\
      goto WIN;								\
    }									\
}

/* A C expression that is nonzero if X is a legitimate constant for an
   immediate operand on the target machine.  You can assume that X
   satisfies `CONSTANT_P', so you need not check this.  In fact, `1' is
   a suitable definition for this macro on machines where anything
   `CONSTANT_P' is valid.  */
#define TARGET_LEGITIMATE_CONSTANT_P(X) \
  ubi32_legitimate_constant_p ((X))

/* Moves between registers are pretty-much single instructions for
   Ubi32 but moves into address regs can be expensive if they
   trigger hazards.  */
#define REGISTER_MOVE_COST(MODE, CLASS1, CLASS2) \
  ubi32_register_move_cost ((MODE), (CLASS1), (CLASS2))

/* This is a little bit of magic from the S390 port that wins 2% on code
   size when building the Linux kernel!  Unfortunately while it wins on
   size, the performance can be lower because we put more pressure on any
   D-caches.  We enable for -Os and the IP3k where these don't matter.  */
#define IRA_HARD_REGNO_ADD_COST_MULTIPLIER(regno) \
  (((! ubi32_v3) || optimize_size) ? 0.5 : 0.0)

/* Moves between registers and memory are more expensive than between
   registers because we have caches and write buffers that slow things
   down!  */
#define MEMORY_MOVE_COST(MODE, CLASS, IN) \
  ubi32_memory_move_cost ((MODE), (CLASS), (IN))

/* A fall-through branch is very low but a predicted taken branch takes 4
   clocks and any mispredict costs 7 clocks!  */
#define BRANCH_COST(SPEED_P, PREDICTABLE_P) \
  ((PREDICTABLE_P) ? 1 : 3)

/* Define this macro as a C expression which is nonzero if accessing less than
   a word of memory (i.e. a `char' or a `short') is no faster than accessing a
   word of memory, i.e., if such access require more than one instruction or if
   there is no difference in cost between byte and (aligned) word loads.

   When this macro is not defined, the compiler will access a field by finding
   the smallest containing object; when it is defined, a fullword load will be
   used if alignment permits.  Unless bytes accesses are faster than word
   accesses, using word accesses is preferable since it may eliminate
   subsequent memory access if subsequent accesses occur to other fields in the
   same word of the structure, but to different bytes.  */
#define SLOW_BYTE_ACCESS 0

/* These 2 ratios determine how many move instructions can be used before
   we resort to calling library functions.  The idea is to avoid too much
   code bloat!
   
   Conventional wisdom is that when optimizing for speed we might make this
   higher than optimizing for size but with the Ubi32 ISA we can do
   memory-to-memory and constant-to-memory moves very effectively so we
   go for a reasonably high value in all circumstances.

   One thing to bear in mind, especially for things like optimized memcpy()
   and strcpy() behaviour is that it's not just the cost of the code that
   we'd call that has to be taken into account, but also the spill costs
   that are incurred and also the costs of any constant tables.  */
#define MOVE_RATIO(SPEED) 16
#define CLEAR_RATIO(SPEED) 16

/* We're much better off calling a constant function address with the
   Ubi32 architecture because we have an opcode for doing so.  Don't
   let the compiler extract function addresses as common subexpressions
   into an address register.  */
#define NO_FUNCTION_CSE 1

#define SELECT_CC_MODE(OP, X, Y) \
  ubi32_select_cc_mode (OP, X, Y)

#define REVERSIBLE_CC_MODE(MODE) 1

/* Canonicalize a comparison from one we don't have to one we do have.  */
#define CANONICALIZE_COMPARISON(CODE, OP0, OP1) \
  ubi32_canonicalize_comparison (&(CODE), &(OP0), &(OP1))

/* Dividing the output into sections.  */

/* A C expression whose value is a string containing the assembler operation
   that should precede instructions and read-only data.  Normally `".text"' is
   right.  */
#define TEXT_SECTION_ASM_OP "\t.section\t.text"

/* A C expression whose value is a string containing the assembler operation to
   identify the following data as writable initialized data.  Normally
   `".data"' is right.  */
#define DATA_SECTION_ASM_OP "\t.section\t.data"

/* If defined, a C expression whose value is a string containing the
   assembler operation to identify the following data as
   uninitialized global data.  If not defined, and neither
   `ASM_OUTPUT_BSS' nor `ASM_OUTPUT_ALIGNED_BSS' are defined,
   uninitialized global data will be output in the data section if
   `-fno-common' is passed, otherwise `ASM_OUTPUT_COMMON' will be
   used.  */
#define BSS_SECTION_ASM_OP "\t.section\t.bss"

/* A C string constant describing how to begin a comment in the target
   assembler language.  The compiler assumes that the comment will end at the
   end of the line.  */
#define ASM_COMMENT_START ";"

/* A C string constant for text to be output before each `asm' statement or
   group of consecutive ones.  Normally this is `"#APP"', which is a comment
   that has no effect on most assemblers but tells the GNU assembler that it
   must check the lines that follow for all valid assembler constructs.  */
#define ASM_APP_ON "#APP\n"

/* A C string constant for text to be output after each `asm' statement or
   group of consecutive ones.  Normally this is `"#NO_APP"', which tells the
   GNU assembler to resume making the time-saving assumptions that are valid
   for ordinary compiler output.  */
#define ASM_APP_OFF "#NO_APP\n"

/* Like `ASM_OUTPUT_BSS' except takes the required alignment as a separate,
   explicit argument.  If you define this macro, it is used in place of
   `ASM_OUTPUT_BSS', and gives you more flexibility in handling the required
   alignment of the variable.  The alignment is specified as the number of
   bits.

   Try to use function `asm_output_aligned_bss' defined in file `varasm.c' when
   defining this macro.  */
#define ASM_OUTPUT_ALIGNED_BSS(FILE, DECL, NAME, SIZE, ALIGN) \
  asm_output_aligned_bss ((FILE), (DECL), (NAME), (SIZE), (ALIGN))

/* A C expression to assign to OUTVAR (which is a variable of type `char *') a
   newly allocated string made from the string NAME and the number NUMBER, with
   some suitable punctuation added.  Use `alloca' to get space for the string.

   The string will be used as an argument to `ASM_OUTPUT_LABELREF' to produce
   an assembler label for an internal static variable whose name is NAME.
   Therefore, the string must be such as to result in valid assembler code.
   The argument NUMBER is different each time this macro is executed; it
   prevents conflicts between similarly-named internal static variables in
   different scopes.

   Ideally this string should not be a valid C identifier, to prevent any
   conflict with the user's own symbols.  Most assemblers allow periods or
   percent signs in assembler symbols; putting at least one of these between
   the name and the number will suffice.  */
#define ASM_FORMAT_PRIVATE_NAME(OUTPUT, NAME, LABELNO)	\
  ((OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\
   sprintf ((OUTPUT), "%s___%d", (NAME), (LABELNO)))

/* Globalizing directive for a label.  */
#define GLOBAL_ASM_OP "\t.global\t"

/* Output the operand of an instruction.  */
#define PRINT_OPERAND(FILE, X, CODE) \
  ubi32_print_operand(FILE, X, CODE)

/* Output the address of an operand.  */
#define PRINT_OPERAND_ADDRESS(FILE, ADDR) \
  ubi32_print_operand_address (FILE, ADDR)

/* A C expression to output to STREAM some assembler code which will push hard
   register number REGNO onto the stack.  The code need not be optimal, since
   this macro is used only when profiling.  */
#define ASM_OUTPUT_REG_PUSH(FILE, REGNO)

/* A C expression to output to STREAM some assembler code which will pop hard
   register number REGNO off of the stack.  The code need not be optimal, since
   this macro is used only when profiling.  */
#define ASM_OUTPUT_REG_POP(FILE, REGNO)

/* This macro should be provided on machines where the addresses in a dispatch
   table are relative to the table's own address.

   The definition should be a C statement to output to the stdio stream STREAM
   an assembler pseudo-instruction to generate a difference between two labels.
   VALUE and REL are the numbers of two internal labels.  The definitions of
   these labels are output using `ASM_OUTPUT_INTERNAL_LABEL', and they must be
   printed in the same way here.  For example,

	fprintf (STREAM, "\t.word L%d-L%d\n", VALUE, REL)  */
#define ASM_OUTPUT_ADDR_DIFF_ELT(FILE, BODY, VALUE, REL) \
  fprintf (FILE, "\t%s .L%d-.L%d\n", ".long", VALUE, REL)

/* This macro should be provided on machines where the addresses in a dispatch
   table are absolute.

   The definition should be a C statement to output to the stdio stream STREAM
   an assembler pseudo-instruction to generate a reference to a label.  VALUE
   is the number of an internal label whose definition is output using
   `ASM_OUTPUT_INTERNAL_LABEL'.  For example,

	fprintf (STREAM, "\t.word L%d\n", VALUE)  */
#define ASM_OUTPUT_ADDR_VEC_ELT(STREAM, VALUE) \
  fprintf (STREAM, "\t.word .L%d\n", VALUE)

/* Assembler Commands for Alignment.  */

/* A C statement to output to the stdio stream STREAM an assembler command to
   advance the location counter to a multiple of 2 to the POWER bytes.  POWER
   will be a C expression of type `int'.  */
#define ASM_OUTPUT_ALIGN(FILE, LOG)	\
  if ((LOG) != 0)			\
    fprintf (FILE, "\t.align %d\n", (LOG))

/* A C expression that returns the DBX register number for the compiler
   register number REGNO.  In simple cases, the value of this expression may be
   REGNO itself.  But sometimes there are some registers that the compiler
   knows about and DBX does not, or vice versa.  In such cases, some register
   may need to have one number in the compiler and another for DBX.

   If two registers have consecutive numbers inside GNU CC, and they can be
   used as a pair to hold a multiword value, then they *must* have consecutive
   numbers after renumbering with `DBX_REGISTER_NUMBER'.  Otherwise, debuggers
   will be unable to access such a pair, because they expect register pairs to
   be consecutive in their own numbering scheme.

   If you find yourself defining `DBX_REGISTER_NUMBER' in way that does not
   preserve register pairs, then what you must do instead is redefine the
   actual register numbering scheme.

   This declaration is required.  */
#define DBX_REGISTER_NUMBER(REGNO) REGNO

/* A C expression that returns the integer offset value for an automatic
   variable having address X (an RTL expression).  The default computation
   assumes that X is based on the frame-pointer and gives the offset from the
   frame-pointer.  This is required for targets that produce debugging output
   for DBX or COFF-style debugging output for SDB and allow the frame-pointer
   to be eliminated when the `-g' options is used.  */
#define DEBUGGER_AUTO_OFFSET(X)						\
  ((GET_CODE (X) == PLUS ? INTVAL (XEXP (X, 1)) : 0)			\
    + (frame_pointer_needed						\
       ? 0 : -ubi32_initial_elimination_offset (HARD_FRAME_POINTER_REGNUM,\
					  STACK_POINTER_REGNUM)))

/* A C expression that returns the integer offset value for an argument having
   address X (an RTL expression).  The nominal offset is OFFSET.  */
#define DEBUGGER_ARG_OFFSET(OFFSET, X)					\
  ((GET_CODE (X) == PLUS ? OFFSET : 0)					\
    + (frame_pointer_needed						\
       ? 0 : -ubi32_initial_elimination_offset (ARG_POINTER_REGNUM,	\
					  STACK_POINTER_REGNUM)))

/* Define this macro if GNU CC should produce dwarf version 2 format debugging
   output in response to the `-g' option.

   To support optional call frame debugging information, you must also define
   `INCOMING_RETURN_ADDR_RTX' and either set `RTX_FRAME_RELATED_P' on the
   prologue insns if you use RTL for the prologue, or call `dwarf2out_def_cfa'
   and `dwarf2out_reg_save' as appropriate from `FUNCTION_PROLOGUE' if you
   don't.

   Defined in svr4.h.  */

/*#define DWARF2_UNWIND_INFO 1*/
#define DWARF2_UNWIND_INFO 0
#define INCOMING_RETURN_ADDR_RTX gen_rtx_REG (Pmode, LINK_REGNUM)
#define INCOMING_FRAME_SP_OFFSET 0
#define DWARF_FRAME_RETURN_COLUMN DWARF_FRAME_REGNUM (LINK_REGNUM)
#define EH_RETURN_FIRST 9
#define EH_RETURN_DATA_REGNO(N) ((N) < 2 ? (N) + EH_RETURN_FIRST : INVALID_REGNUM)

/* The EH_RETURN_STACKADJ_RTX macro returns RTL which describes the
   location used to store the amount to ajdust the stack.  This is
   usually a registers that is available from end of the function's body
   to the end of the epilogue. Thus, this cannot be a register used as a
   temporary by the epilogue.

   This must be an integer register.  */
#define EH_RETURN_STACKADJ_REGNO 11
#define EH_RETURN_STACKADJ_RTX \
  gen_rtx_REG (Pmode, EH_RETURN_STACKADJ_REGNO)

/* The EH_RETURN_HANDLER_RTX macro returns RTL which describes the
   location used to store the address the processor should jump to
   catch exception.  This is usually a registers that is available from
   end of the function's body to the end of the epilogue. Thus, this
   cannot be a register used as a temporary by the epilogue.

   This must be an address register.  */
#define EH_RETURN_HANDLER_REGNO 18
#define EH_RETURN_HANDLER_RTX \
  gen_rtx_REG (Pmode, EH_RETURN_HANDLER_REGNO)

/* #define DWARF2_DEBUGGING_INFO */

/* Define this macro if GNU CC should produce dwarf version 2-style
   line numbers.  This usually requires extending the assembler to
   support them, and #defining DWARF2_LINE_MIN_INSN_LENGTH in the
   assembler configuration header files.  */
/* #define DWARF2_ASM_LINE_DEBUG_INFO 1 */


/* An alias for a machine mode name.  This is the machine mode that elements
   of a jump-table have.  */
#define CASE_VECTOR_MODE Pmode

/* Smallest number of different values for which it is best to use a
   jump-table instead of a tree of conditional branches.  For Ubi32
   targets this is quite small since any mispredicted jumps are as
   expensive as table lookups and a long sequnce of instructions
   isn't a good idea either.  The Ubi32 ISA also lets us do most
   bounds checks quite cheaply too.  */
#define CASE_VALUES_THRESHOLD 4

/* Register operations within the Ubi32 architecture always operate on
   the whole register word and not just the sub-bits required for the opcode
   mode size.  */
#define WORD_REGISTER_OPERATIONS 1

/* The maximum number of bytes that a single instruction can move quickly from
   memory to memory.  */
#define MOVE_MAX 4

/* A C expression that is nonzero if on this machine the number of bits
   actually used for the count of a shift operation is equal to the number of
   bits needed to represent the size of the object being shifted.  When this
   macro is non-zero, the compiler will assume that it is safe to omit a
   sign-extend, zero-extend, and certain bitwise `and' instructions that
   truncates the count of a shift operation.  On machines that have
   instructions that act on bitfields at variable positions, which may include
   `bit test' instructions, a nonzero `SHIFT_COUNT_TRUNCATED' also enables
   deletion of truncations of the values that serve as arguments to bitfield
   instructions.

   If both types of instructions truncate the count (for shifts) and position
   (for bitfield operations), or if no variable-position bitfield instructions
   exist, you should define this macro.

   However, on some machines, such as the 80386 and the 680x0, truncation only
   applies to shift operations and not the (real or pretended) bitfield
   operations.  Define `SHIFT_COUNT_TRUNCATED' to be zero on such machines.
   Instead, add patterns to the `md' file that include the implied truncation
   of the shift instructions.

   You need not define this macro if it would always have the value of zero.  */
#define SHIFT_COUNT_TRUNCATED 1

/* A C string constant that tells the GNU CC driver program options to pass
   to the assembler.  It can also specify how to translate options you give
   to GNU CC into options for GNU CC to pass to the assembler.  See the
   file `sun3.h' for an example of this.

   Defined in svr4.h.  */

#define ENDIAN_SPEC \
  "%{!mbig-endian: %{!mlittle-endian: %{!march=*:-EL}}} \
  %{!mbig-endian: %{!mlittle-endian: %{march=ubicom32v6:-EL}}} \
  %{!mbig-endian: %{!mlittle-endian: %{march=ubicom32v61:-EL}}} \
  %{mbig-endian:-EB} \
  %{mlittle-endian:-EL} "

#undef ASM_SPEC
#define ASM_SPEC "\
  %{march=*:-m%*} \
  %{!march=*:-mubicom32v61} \
  %{mfdpic:-mfdpic} \
  %{mcpu=*:-mcpu=%*} "\
  ENDIAN_SPEC

#undef LINK_SPEC
#define LINK_SPEC "\
  %{h*} \
  %{v:-V} \
  %{b} \
  %{mfdpic:-melf32ubicom32fdpic -z text} \
  %{static:-dn -Bstatic} \
  %{shared:-G -Bdynamic} \
  %{symbolic:-Bsymbolic} \
  %{G*} \
  %{YP,*} \
  %{Qy:} \
  %{!Qn:-Qy} "\
  ENDIAN_SPEC

#undef STARTFILE_SPEC
#undef ENDFILE_SPEC

#undef LIB_SPEC
#define LIB_SPEC "--start-group %{msemihosting:-lhost} -lc -lgcc --end-group"

#undef HAVE_GAS_SHF_MERGE
#define HAVE_GAS_SHF_MERGE 0

#undef MULTILIB_DEFAULTS
#define MULTILIB_DEFAULTS { "march=ubicom32v61" }


/* Define builtins for selected special-purpose instructions. */
enum ubi32_builtins
{
  UBI32_BUILTIN_UBI32_PREFETCH,
  UBI32_BUILTIN_UBI32_SWAPB_2,
  UBI32_BUILTIN_UBI32_SWAPB_4,
  UBI32_BUILTIN_THREAD_POINTER,
  UBI32_BUILTIN_SET_THREAD_POINTER,
  UBI32_BUILTIN_SPINLOCK_LOCK,
  UBI32_BUILTIN_SPINLOCK_UNLOCK,
  UBI32_BUILTIN_SPINLOCK_TRY_LOCK,
  UBI32_BUILTIN_SPINLOCK_IS_LOCKED
};

extern rtx ubi32_compare_op0;
extern rtx ubi32_compare_op1;

#define FRAME_GROWS_DOWNWARD flag_stack_protect
