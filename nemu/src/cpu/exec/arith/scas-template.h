//
// Created by 浮生未休 on 2020/10/31.
//

//
// Created by 浮生未休 on 2020/10/31.
//

#include "cpu/exec/template-start.h"

#define instr scas

static void do_execute() {
    int result=swaddr_read(cpu.edi,DATA_BYTE);
    result=REG(0)-result;

    int len = (DATA_BYTE << 3) - 1;
    cpu.CF = op_dest->val < op_src->val;
    cpu.SF=result >> len;
    int s1,s2;
    s1=op_dest->val>>len;
    s2=op_src->val>>len;
    cpu.OF=(s1 != s2 && s2 == cpu.SF) ;
    cpu.ZF=!result;
    result ^= result >>4;
    result ^= result >>2;
    result ^= result >>1;
    cpu.PF=!(result & 1);
    print_asm_template2();
}

make_instr_helper(n)


#include "cpu/exec/template-end.h"