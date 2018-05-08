/* Function prototypes for Qualcomm Ubi32.

   Copyright (C) 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008,
   2009 Free Software Foundation, Inc.

   This file is part of GNU CC.

   GNU CC is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   GNU CC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License along
   with GNU CC; see the file COPYING.  If not, write to the Free Software
   Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */

#ifdef RTX_CODE
extern void ubi32_print_operand (FILE *, rtx, int);
extern void ubi32_print_operand_address (FILE *, rtx);
extern void ubi32_conditional_register_usage (void);
extern enum reg_class ubi32_preferred_reload_class (rtx, enum reg_class);
extern int ubi32_regno_ok_for_index_p (int, int);
extern void ubi32_expand_movsi (rtx *);
extern void ubi32_expand_addsi3 (rtx *);
extern bool ubi32_expand_scode (enum rtx_code, rtx, rtx, rtx *);
extern bool ubi32_expand_addcc (enum rtx_code, rtx, rtx, rtx, rtx, rtx);
extern bool ubi32_expand_mulsi3 (rtx *);
extern void ubi32_split_sne (rtx *);
extern void ubi32_split_seq (rtx *);
extern void ubi32_split_slt (rtx *);
extern void ubi32_split_sge (rtx *);
extern void ubi32_split_sltu (rtx *);
extern void ubi32_split_sgeu (rtx *);
extern void ubi32_emit_move_const_int (rtx, rtx);
extern bool ubi32_legitimate_address_p (enum machine_mode, rtx, int);
extern rtx ubi32_legitimize_address (rtx, rtx, enum machine_mode);
extern rtx ubi32_legitimize_reload_address (rtx, enum machine_mode, int, int);
extern void ubi32_canonicalize_comparison (enum rtx_code *code, rtx *op0, rtx *op1);
extern int ubi32_mode_dependent_address_p (rtx);
extern void ubi32_output_cond_jump (rtx, rtx, rtx);
extern void ubi32_expand_eh_return (rtx *);
extern enum machine_mode ubi32_select_cc_mode (RTX_CODE, rtx, rtx);
extern rtx ubi32_gen_compare (RTX_CODE, rtx, rtx);
extern int ubi32_shiftable_const_int (int);
extern rtx ubi32_expand_conditional_branch (rtx *);

#ifdef TREE_CODE
extern void ubi32_init_cumulative_args (CUMULATIVE_ARGS *, tree, rtx);
// extern rtx ubi32_function_arg_advance (cumulative_args_t, machine_mode,
//			   const_tree, bool);
extern rtx ubi32_function_incoming_arg (CUMULATIVE_ARGS *,
					   enum machine_mode,
					   tree, int);
#endif /* TREE_CODE */
#endif /* RTX_CODE */

extern void asm_file_start (FILE *);
extern void ubi32_split_operand_pair (rtx *);
extern void ubi32_expand_prologue (void);
extern void ubi32_expand_epilogue (bool);
extern int ubi32_initial_elimination_offset (int, int);
extern int ubi32_regno_ok_for_base_p (int, int);
extern bool ubi32_hard_regno_mode_ok (unsigned int, enum machine_mode);
extern rtx ubi32_return_addr_rtx (int, rtx);
extern void ubi32_optimization_options (int, int);
extern void ubi32_override_options (void);
extern bool ubi32_match_cc_mode (rtx, enum machine_mode);
extern int ubi32_register_move_cost (enum machine_mode, enum reg_class,
					enum reg_class);
extern int ubi32_memory_move_cost (enum machine_mode, enum reg_class, int);
extern int ubi32_address_dep_p (rtx_insn *, rtx_insn *);
extern alias_set_type ubi32_GOT_alias_set (void);
extern bool ubi32_hard_regno_rename_ok (unsigned int, unsigned int);
extern bool ubi32_expand_mulhisi3 (rtx *);
extern bool ubi32_expand_umulhisi3 (rtx *);
extern void ubi32_cpu_cpp_builtins (cpp_reader *);
