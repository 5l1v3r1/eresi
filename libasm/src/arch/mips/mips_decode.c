/**
 * $Id: mips_decode.c,v 1.1 2007-01-23 09:53:03 heroine Exp $
 *
 *
 *
 */

#include <libasm.h>

/**
 *
 *
 */
int	mips_extract_opcode(int opcode)
{
  return ((opcode >> 26) && 0x3F);
}

/**
 *
 * @param ins
 * @param buf
 * @param len
 * @param proc
 *
 */
int	mips_decode_jtype(asm_instr *ins, u_char *buf, u_int len, asm_processor *proc)
{
  struct s_mips_decode_jump	opcode;

  mips_convert_format_j(&opcode, buf);
  ins->instr = mips_root_table[opcode.op];
  puts("mips_decode_jtype");
  return (4);
}

/**
 *
 * @param ins
 * @param buf
 * @param len
 * @param proc
 *
 */
int	mips_decode_itype(asm_instr *ins, u_char *buf, u_int len, asm_processor *proc)
{
  struct s_mips_decode_imm	opcode;
  
  mips_convert_format_i(&opcode, buf);
  puts("mips_decode_itype");
  ins->instr = mips_func_table[opcode.op];
  return (4);
}

/**
 *
 * @param ins
 * @param buf
 * @param len
 * @param proc
 *
 */
int	mips_decode_rtype(asm_instr *ins, u_char *buf, u_int len, asm_processor *proc)
{
  struct s_mips_decode_reg	opcode;
  
  mips_convert_format_r(&opcode, buf);
  puts("mips_decode_rtype");
  if (opcode.op == 0)
    {
      ins->instr = mips_func_table[opcode.fn];
      ins->op1.type = 1;
      ins->op1.base_reg = opcode.rs;
      ins->op2.type = 1;
      ins->op2.base_reg = opcode.rt;
      ins->op3.type = 1;
      ins->op3.base_reg = opcode.rd;
    }
  return (4);
}

/**
 *
 * @param ins
 * @param buf
 * @param len
 * @param proc
 *
 */
int	mips_decode_ctype(asm_instr *ins, u_char *buf, u_int len, asm_processor *proc)
{
  printf("mips_decode_ctype unsupported\n");
  return (4);
}