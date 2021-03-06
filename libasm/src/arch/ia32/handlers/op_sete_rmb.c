/**
* @file libasm/src/arch/ia32/handlers/op_sete_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction sete, opcode 0x0f 0x94
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble
 * @param proc Pointer to processor structure
 * @return Length of instruction
*/

int op_sete_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->instr = ASM_SET_EQUAL;
  new->len += 1;
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_CONTENT_ENCODEDBYTE, new);
  return (new->len);
}
