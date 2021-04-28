/*
 * cpu-z80a-priv.h - Copyright (c) 2001-2021 - Olivier Poncet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __XCPC_CPU_Z80A_PRIV_H__
#define __XCPC_CPU_Z80A_PRIV_H__

#include <xcpc/cpu-z80a/cpu-z80a.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef AVOID_UNUSED_WARNING
#define AVOID_UNUSED_WARNING(symbol) (void)(symbol)
#endif

#define CF 0x01 /* carry / borrow         */
#define NF 0x02 /* add / sub              */
#define VF 0x04 /* overflow               */
#define PF 0x04 /* parity                 */
#define XF 0x08 /* undocumented           */
#define HF 0x10 /* halfcarry / halfborrow */
#define YF 0x20 /* undocumented           */
#define ZF 0x40 /* zero                   */
#define SF 0x80 /* sign                   */

#define OP_ADD 0x00 /* ADD operation */
#define OP_ADC 0x00 /* ADC operation */
#define OP_SUB 0x02 /* SUB operation */
#define OP_SBC 0x02 /* SBC operation */
#define OP_AND 0x10 /* AND operation */
#define OP_XOR 0x00 /* XOR operation */
#define OP_IOR 0x00 /* IOR operation */
#define OP_CMP 0x02 /* CMP operation */

#define ST_IFF1 0x01 /* interrupt flip-flop #1 */
#define ST_IFF2 0x02 /* interrupt flip-flop #2 */
#define ST_IM1  0x04 /* interrupt mode #1      */
#define ST_IM2  0x08 /* interrupt mode #2      */
#define ST_XYZ  0x10 /* not used               */
#define ST_NMI  0x20 /* pending NMI            */
#define ST_INT  0x40 /* pending INT            */
#define ST_HLT  0x80 /* cpu is HALTed          */

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80

#define VECTOR_00H 0x0000
#define VECTOR_08H 0x0008
#define VECTOR_10H 0x0010
#define VECTOR_18H 0x0018
#define VECTOR_20H 0x0020
#define VECTOR_28H 0x0028
#define VECTOR_30H 0x0030
#define VECTOR_38H 0x0038
#define VECTOR_66H 0x0066

#define SELF self
#define IFACE SELF->iface
#define STATE SELF->state
#define REGS STATE.regs
#define CTRS STATE.ctrs

#define AF_R REGS.AF.l.r
#define AF_P REGS.AF.w.h
#define AF_W REGS.AF.w.l
#define AF_X REGS.AF.b.x
#define AF_Y REGS.AF.b.y
#define AF_H REGS.AF.b.h
#define AF_L REGS.AF.b.l

#define BC_R REGS.BC.l.r
#define BC_P REGS.BC.w.h
#define BC_W REGS.BC.w.l
#define BC_X REGS.BC.b.x
#define BC_Y REGS.BC.b.y
#define BC_H REGS.BC.b.h
#define BC_L REGS.BC.b.l

#define DE_R REGS.DE.l.r
#define DE_P REGS.DE.w.h
#define DE_W REGS.DE.w.l
#define DE_X REGS.DE.b.x
#define DE_Y REGS.DE.b.y
#define DE_H REGS.DE.b.h
#define DE_L REGS.DE.b.l

#define HL_R REGS.HL.l.r
#define HL_P REGS.HL.w.h
#define HL_W REGS.HL.w.l
#define HL_X REGS.HL.b.x
#define HL_Y REGS.HL.b.y
#define HL_H REGS.HL.b.h
#define HL_L REGS.HL.b.l

#define IX_R REGS.IX.l.r
#define IX_P REGS.IX.w.h
#define IX_W REGS.IX.w.l
#define IX_H REGS.IX.b.h
#define IX_L REGS.IX.b.l

#define IY_R REGS.IY.l.r
#define IY_P REGS.IY.w.h
#define IY_W REGS.IY.w.l
#define IY_H REGS.IY.b.h
#define IY_L REGS.IY.b.l

#define SP_R REGS.SP.l.r
#define SP_P REGS.SP.w.h
#define SP_W REGS.SP.w.l
#define SP_H REGS.SP.b.h
#define SP_L REGS.SP.b.l

#define PC_R REGS.PC.l.r
#define PC_P REGS.PC.w.h
#define PC_W REGS.PC.w.l
#define PC_H REGS.PC.b.h
#define PC_L REGS.PC.b.l

#define IR_R REGS.IR.l.r
#define IR_P REGS.IR.w.h
#define IR_W REGS.IR.w.l
#define IR_H REGS.IR.b.h
#define IR_L REGS.IR.b.l

#define ST_R REGS.ST.l.r
#define ST_P REGS.ST.w.h
#define ST_W REGS.ST.w.l
#define ST_H REGS.ST.b.h
#define ST_L REGS.ST.b.l

#define M_CYCLES CTRS.m_cycles
#define T_STATES CTRS.t_states
#define I_PERIOD CTRS.i_period

#define WZ_R WZ.l.r
#define WZ_P WZ.w.h
#define WZ_W WZ.w.l
#define WZ_H WZ.b.h
#define WZ_L WZ.b.l

#define T0_R T0.l.r
#define T0_P T0.w.h
#define T0_W T0.w.l
#define T0_H T0.b.h
#define T0_L T0.b.l

#define T1_R T1.l.r
#define T1_P T1.w.h
#define T1_W T1.w.l
#define T1_H T1.b.h
#define T1_L T1.b.l

#define T2_R T2.l.r
#define T2_P T2.w.h
#define T2_W T2.w.l
#define T2_H T2.b.h
#define T2_L T2.b.l

#define T3_R T3.l.r
#define T3_P T3.w.h
#define T3_W T3.w.l
#define T3_H T3.b.h
#define T3_L T3.b.l

#define PREV_PC prev_pc
#define LAST_OP last_op

#define MREQ_M1(addr, data) (void)(data=(*IFACE.mreq_m1)((self),(addr),(0x00)))
#define MREQ_RD(addr, data) (void)(data=(*IFACE.mreq_rd)((self),(addr),(0x00)))
#define MREQ_WR(addr, data) (void)((*IFACE.mreq_wr)((self),(addr),(data)))

#define IORQ_M1(port, data) (void)(data=(*IFACE.iorq_m1)((self),(port),(0x00)))
#define IORQ_RD(port, data) (void)(data=(*IFACE.iorq_rd)((self),(port),(0x00)))
#define IORQ_WR(port, data) (void)((*IFACE.iorq_wr)((self),(port),(data)))

#define SIGNED_BYTE(value) ((int8_t)(value))
#define UNSIGNED_BYTE(value) ((uint8_t)(value))

#define LO_NIBBLE(value) ((value) & 0x0f)
#define HI_NIBBLE(value) ((value) & 0xf0)

#define HAS_IFF1 ((ST_L & ST_IFF1) != 0)
#define HAS_IFF2 ((ST_L & ST_IFF2) != 0)
#define HAS_IM1  ((ST_L & ST_IM1) != 0)
#define HAS_IM2  ((ST_L & ST_IM2) != 0)
#define HAS_XYZ  ((ST_L & ST_XYZ) != 0)
#define HAS_NMI  ((ST_L & ST_NMI) != 0)
#define HAS_INT  ((ST_L & ST_INT) != 0)
#define HAS_HLT  ((ST_L & ST_HLT) != 0)

#define SET_IFF1() do { ST_L |= ST_IFF1; } while(0)
#define SET_IFF2() do { ST_L |= ST_IFF2; } while(0)
#define SET_IM1()  do { ST_L |= ST_IM1; } while(0)
#define SET_IM2()  do { ST_L |= ST_IM2; } while(0)
#define SET_XYZ()  do { ST_L |= ST_XYZ; } while(0)
#define SET_NMI()  do { ST_L |= ST_NMI; } while(0)
#define SET_INT()  do { ST_L |= ST_INT; } while(0)
#define SET_HLT()  do { ST_L |= ST_HLT; } while(0)

#define CLR_IFF1() do { ST_L &= ~ST_IFF1; } while(0)
#define CLR_IFF2() do { ST_L &= ~ST_IFF2; } while(0)
#define CLR_IM1()  do { ST_L &= ~ST_IM1; } while(0)
#define CLR_IM2()  do { ST_L &= ~ST_IM2; } while(0)
#define CLR_XYZ()  do { ST_L &= ~ST_XYZ; } while(0)
#define CLR_NMI()  do { ST_L &= ~ST_NMI; } while(0)
#define CLR_INT()  do { ST_L &= ~ST_INT; } while(0)
#define CLR_HLT()  do { ST_L &= ~ST_HLT; } while(0)

/*
 * fetch opcode
 */

#define m_fetch_opcode() \
    do { \
        last_op = (*IFACE.mreq_m1)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch CB opcode
 */

#define m_fetch_cb_opcode() \
    do { \
        last_op = (*IFACE.mreq_m1)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch DD opcode
 */

#define m_fetch_dd_opcode() \
    do { \
        last_op = (*IFACE.mreq_m1)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch ED opcode
 */

#define m_fetch_ed_opcode() \
    do { \
        last_op = (*IFACE.mreq_m1)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch FD opcode
 */

#define m_fetch_fd_opcode() \
    do { \
        last_op = (*IFACE.mreq_m1)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch DDCB opcode
 */

#define m_fetch_ddcb_opcode() \
    do { \
        last_op = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch FDCB opcode
 */

#define m_fetch_fdcb_opcode() \
    do { \
        last_op = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
    } while(0)

/*
 * fetch DDCB offset
 */

#define m_fetch_ddcb_offset() \
    do { \
        WZ_W = IX_W + SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W++, 0x00)); \
    } while(0)

/*
 * fetch FDCB offset
 */

#define m_fetch_fdcb_offset() \
    do { \
        WZ_W = IY_W + SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W++, 0x00)); \
    } while(0)

/*
 * illegal opcode
 */

#define m_illegal() \
    do { \
        xcpc_log_debug("illegal %02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * illegal CB opcode
 */

#define m_illegal_cb() \
    do { \
        xcpc_log_debug("illegal CB%02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * illegal DD opcode
 */

#define m_illegal_dd() \
    do { \
        xcpc_log_debug("illegal DD%02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * illegal ED opcode
 */

#define m_illegal_ed() \
    do { \
        xcpc_log_debug("illegal ED%02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * illegal FD opcode
 */

#define m_illegal_fd() \
    do { \
        xcpc_log_debug("illegal FD%02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * illegal DDCB opcode
 */

#define m_illegal_ddcb() \
    do { \
        xcpc_log_debug("illegal DDCBxx%02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * illegal FDCB opcode
 */

#define m_illegal_fdcb() \
    do { \
        xcpc_log_debug("illegal FDCByy%02X opcode at %04X", LAST_OP, PREV_PC); \
    } while(0)

/*
 * refresh dram
 */

#define m_refresh_dram() \
    do { \
        IR_L = ((IR_L + 0) & 0x80) \
             | ((IR_L + 1) & 0x7f) \
             ; \
    } while(0)

/*
 * consume m-cycles / t-states
 */

#define m_consume(cycles, states) \
    do { \
        M_CYCLES += cycles; \
        T_STATES += states; \
        I_PERIOD -= states; \
    } while(0)

/*
 * pending NMI
 */

#define m_pending_nmi() \
    ((ST_L & ST_NMI) != 0)

/*
 * pending INT
 */

#define m_pending_int() \
    ((ST_L & ST_INT) != 0)

/*
 * halted CPU
 */

#define m_halted() \
    ((ST_L & ST_HLT) != 0)

/*
 * aknowledge NMI
 */

#define m_acknowledge_nmi() \
    do { \
        ST_L &= ~(ST_HLT | ST_INT | ST_NMI | ST_IFF2); \
    } while(0)

/*
 * aknowledge INT
 */

#define m_acknowledge_int() \
    do { \
        ST_L &= ~(ST_HLT | ST_INT | ST_NMI | ST_IFF2 | ST_IFF1); \
        IORQ_M1(0x0000, T1_L); \
    } while(0)

/*
 * prefix
 */

#define m_prefix() \
    do { \
    } while(0)

/*
 * nop
 */

#define m_nop() \
    do { \
    } while(0)

/*
 * ld r08,r08
 */

#define m_ld_r08_r08(reg1, reg2) \
    do { \
        reg1 = reg2; \
    } while(0)

/*
 * ld r08,(r16)
 */

#define m_ld_r08_ind_r16(reg1, reg2) \
    do { \
        MREQ_RD(reg2, reg1); \
    } while(0)

/*
 * ld (r16),r08
 */

#define m_ld_ind_r16_r08(reg1, reg2) \
    do { \
        MREQ_WR(reg1, reg2); \
    } while(0)

/*
 * ld r08,i08
 */

#define m_ld_r08_i08(reg1) \
    do { \
        MREQ_RD(PC_W++, reg1); \
    } while(0)

/*
 * ld r16,r16
 */

#define m_ld_r16_r16(reg1, reg2) \
    do { \
        reg1 = reg2; \
    } while(0)

/*
 * ld r16,i16
 */

#define m_ld_r16_i16(reg1) \
    do { \
        MREQ_RD(PC_W++, T0_L); \
        MREQ_RD(PC_W++, T0_H); \
        reg1 = T0_W; \
    } while(0)

/*
 * halt
 */

#define m_halt() \
    do { \
        ST_L |= ST_HLT; \
    } while(0)

/*
 * daa
 */

#define m_daa() \
    do { \
        T0_W = AF_H; \
        if(AF_L & CF) T0_W |= 0x100; \
        if(AF_L & HF) T0_W |= 0x200; \
        if(AF_L & NF) T0_W |= 0x400; \
        AF_W = DAATable[T0_W]; \
    } while(0)

/*
 * rlca
 */

#define m_rlca() \
    do { \
        T1_L = AF_H; \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (UNSIGNED_BYTE(T1_L) >> 7); \
        AF_H = T0_L; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is not affected */ (PF & (AF_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
    } while(0)

/*
 * rrca
 */

#define m_rrca() \
    do { \
        T1_L = AF_H; \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) | (UNSIGNED_BYTE(T1_L) << 7); \
        AF_H = T0_L; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is not affected */ (PF & (AF_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
    } while(0)

/*
 * rla
 */

#define m_rla() \
    do { \
        T1_L = AF_H; \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (AF_L & CF ? BIT0 : 0x00); \
        AF_H = T0_L; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is not affected */ (PF & (AF_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
    } while(0)

/*
 * rra
 */

#define m_rra() \
    do { \
        T1_L = AF_H; \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) | (AF_L & CF ? BIT7 : 0x00); \
        AF_H = T0_L; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is not affected */ (PF & (AF_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
    } while(0)

/*
 * inc r08
 */

#define m_inc_r08(reg1) \
    do { \
        M_INC(reg1); \
    } while(0)

/*
 * dec r08
 */

#define m_dec_r08(reg1) \
    do { \
        M_DEC(reg1); \
    } while(0)

/*
 * inc r16
 */

#define m_inc_r16(reg1) \
    do { \
        ++reg1; \
    } while(0)

/*
 * dec r16
 */

#define m_dec_r16(reg1) \
    do { \
        --reg1; \
    } while(0)

/*
 * add r08,r08
 */

#define m_add_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_W = T1_L + T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & T2_L & ~T0_L) | (~T1_L & ~T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * add r08,(r16)
 */

#define m_add_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_W = T1_L + T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & T2_L & ~T0_L) | (~T1_L & ~T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * add r08,i08
 */

#define m_add_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_W = T1_L + T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & T2_L & ~T0_L) | (~T1_L & ~T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * adc r08,r08
 */

#define m_adc_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_W = T1_L + T2_L + ((AF_L & CF) != 0 ? 0x01 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & T2_L & ~T0_L) | (~T1_L & ~T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * adc reg08,(reg16)
 */

#define m_adc_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_W = T1_L + T2_L + ((AF_L & CF) != 0 ? 0x01 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & T2_L & ~T0_L) | (~T1_L & ~T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * adc r08,i08
 */

#define m_adc_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_W = T1_L + T2_L + ((AF_L & CF) != 0 ? 0x01 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & T2_L & ~T0_L) | (~T1_L & ~T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * sub r08,r08
 */

#define m_sub_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * sub r08,(r16)
 */

#define m_sub_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * sub r08,i08
 */

#define m_sub_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * sbc r08,r08
 */

#define m_sbc_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_W = T1_L - T2_L - ((AF_L & CF) != 0 ? 0x01 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * sbc r08,(r16)
 */

#define m_sbc_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_W = T1_L - T2_L - ((AF_L & CF) != 0 ? 0x01 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * sbc r08,i08
 */

#define m_sbc_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_W = T1_L - T2_L - ((AF_L & CF) != 0 ? 0x01 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * and r08,r08
 */

#define m_and_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_L = T1_L & T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0xff)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * and r08,(r16)
 */

#define m_and_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_L = T1_L & T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0xff)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * and r08,i08
 */

#define m_and_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_L = T1_L & T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0xff)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * xor r08,r08
 */

#define m_xor_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_L = T1_L ^ T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * xor r08,(r16)
 */

#define m_xor_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_L = T1_L ^ T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * xor r08,i08
 */

#define m_xor_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_L = T1_L ^ T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * or r08,r08
 */

#define m_or_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_L = T1_L | T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * or r08,(r16)
 */

#define m_or_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_L = T1_L | T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * or r08,i08
 */

#define m_or_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_L = T1_L | T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is reset        */ (CF & (0x00)) \
             ; \
    } while(0)

/*
 * cp r08,r08
 */

#define m_cp_r08_r08(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = reg2; \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is affected     */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is reset        */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * cp r08,(r16)
 */

#define m_cp_r08_ind_r16(reg1, reg2) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, reg2, 0x00); \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is affected     */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is reset        */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * cp r08,i08
 */

#define m_cp_r08_i08(reg1) \
    do { \
        T1_L = reg1; \
        T2_L = (*IFACE.mreq_rd)(SELF, PC_W++, 0x00); \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is affected     */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is reset        */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * im 0
 */

#define m_im_0() \
    do { \
        ST_L = (ST_L & ~(ST_IM1 | ST_IM2)); \
    } while(0)

/*
 * im 1
 */

#define m_im_1() \
    do { \
        ST_L = (ST_L & ~(ST_IM1 | ST_IM2)) | (ST_IM1); \
    } while(0)

/*
 * im 2
 */

#define m_im_2() \
    do { \
        ST_L = (ST_L & ~(ST_IM1 | ST_IM2)) | (ST_IM2); \
    } while(0)

/*
 * im 3
 */

#define m_im_3() \
    do { \
        ST_L = (ST_L | (ST_IM1 | ST_IM2)); \
    } while(0)


/*
 * di
 */

#define m_di() \
    do { \
        ST_L = (ST_L & ~(ST_IFF1 | ST_IFF2)); \
    } while(0)

/*
 * ei
 */

#define m_ei() \
    do { \
        ST_L = (ST_L | (ST_IFF1 | ST_IFF2)); \
    } while(0)
/*
 * push r16
 */

#define m_push_r16(reg1) \
    do { \
        T0_W = reg1; \
        MREQ_WR(--SP_W, T0_H); \
        MREQ_WR(--SP_W, T0_L); \
    } while(0)

/*
 * pop r16
 */

#define m_pop_r16(reg1) \
    do { \
        MREQ_RD(SP_W++, T0_L); \
        MREQ_RD(SP_W++, T0_H); \
        reg1 = T0_W; \
    } while(0)

/*
 * rst p
 */

#define m_rst_vec16(vector) \
    do { \
        MREQ_WR(--SP_W, PC_H); \
        MREQ_WR(--SP_W, PC_L); \
        PC_W = vector; \
    } while(0)

/*
 * neg
 */

#define m_neg() \
    do { \
        T1_L = 0x00; \
        T2_L = AF_H; \
        T0_W = T1_L - T2_L; \
        T3_L = PZSTable[T0_L]; \
        AF_H = T0_L; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (T0_L)) \
             | /* HF is set          */ (HF & (T0_L ^ T1_L ^ T2_L)) \
             | /* XF is undocumented */ (XF & (T0_L)) \
             | /* VF is affected     */ (VF & ((((T1_L & ~T2_L & ~T0_L) | (~T1_L & T2_L & T0_L)) & SF) != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is affected     */ (CF & (T0_H & CF)) \
             ; \
    } while(0)

/*
 * reti
 */

#define m_reti() \
    do { \
        MREQ_RD(SP_W++, PC_L); \
        MREQ_RD(SP_W++, PC_H); \
    } while(0)

/*
 * retn
 */

#define m_retn() \
    do { \
        if(HAS_IFF2) { \
            SET_IFF1(); \
        } \
        else { \
            CLR_IFF1(); \
        } \
        MREQ_RD(SP_W++, PC_L); \
        MREQ_RD(SP_W++, PC_H); \
    } while(0)

/*
 * rld
 */

#define m_rld() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        T0_L = ((LO_NIBBLE(T1_L) << 4) | (LO_NIBBLE(AF_H) >> 0)); \
        AF_H = ((HI_NIBBLE(AF_H) << 0) | (HI_NIBBLE(T1_L) >> 4)); \
        T3_L = PZSTable[AF_H]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
        MREQ_WR(HL_W, T0_L); \
    } while(0)

/*
 * rrd
 */

#define m_rrd() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        T0_L = ((LO_NIBBLE(AF_H) << 4) | (HI_NIBBLE(T1_L) >> 4)); \
        AF_H = ((HI_NIBBLE(AF_H) << 0) | (LO_NIBBLE(T1_L) >> 0)); \
        T3_L = PZSTable[AF_H]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
        MREQ_WR(HL_W, T0_L); \
    } while(0)

/*
 * ldir
 */

#define m_ldir() \
    do { \
        MREQ_RD(HL_W, T0_L); \
        MREQ_WR(DE_W, T0_L); \
        ++HL_W; \
        ++DE_W; \
        --BC_W; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (BC_W != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
        if(BC_W != 0) { \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
    } while(0)

/*
 * lddr
 */

#define m_lddr() \
    do { \
        MREQ_RD(HL_W, T0_L); \
        MREQ_WR(DE_W, T0_L); \
        --HL_W; \
        --DE_W; \
        --BC_W; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (BC_W != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
        if(BC_W != 0) { \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
    } while(0)

/*
 * cpir
 */

#define m_cpir() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        T0_L = AF_H - T1_L; \
        ++HL_W; \
        --BC_W; \
        AF_L = NF | (AF_L & CF) | ZSTable[T0_L] | ((AF_H ^ T1_L ^ T0_L) &HF) | (BC_W ? PF : 0); \
        if((BC_W != 0) && (T0_L != 0)) { \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
    } while(0)

/*
 * cpdr
 */

#define m_cpdr() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        T0_L = AF_H - T1_L; \
        --HL_W; \
        --BC_W; \
        AF_L = NF | (AF_L & CF) | ZSTable[T0_L] | ((AF_H ^ T1_L ^ T0_L) &HF) | (BC_W ? PF : 0); \
        if((BC_W != 0) && (T0_L != 0)) { \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
    } while(0)

/*
 * inir
 */

#define m_inir() \
    do { \
        IORQ_RD(BC_W, T1_L); \
        MREQ_WR(HL_W, T1_L); \
        ++HL_W; \
        --BC_H; \
        if(BC_H != 0) { \
            AF_L = NF; \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            AF_L = ZF | NF; \
        } \
    } while(0)

/*
 * indr
 */

#define m_indr() \
    do { \
        IORQ_RD(BC_W, T1_L); \
        MREQ_WR(HL_W, T1_L); \
        --HL_W; \
        --BC_H; \
        if(BC_H != 0) { \
            AF_L = NF; \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            AF_L = ZF | NF; \
        } \
    } while(0)

/*
 * otir
 */

#define m_otir() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        ++HL_W; \
        --BC_H; \
        IORQ_WR(BC_W, T1_L); \
        if(BC_H != 0) { \
            AF_L = NF | (HL_L + T1_L > 255 ? (CF | HF) : 0); \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            AF_L = ZF | NF | (HL_L + T1_L > 255 ? (CF | HF) : 0); \
        } \
    } while(0)

/*
 * otdr
 */

#define m_otdr() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        --HL_W; \
        --BC_H; \
        IORQ_WR(BC_W, T1_L); \
        if(BC_H != 0) { \
            AF_L = NF | (HL_L + T1_L > 255 ? (CF | HF) : 0); \
            PC_W = PREV_PC; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            AF_L = ZF | NF | (HL_L + T1_L > 255 ? (CF | HF) : 0); \
        } \
    } while(0)

/*
 * ldi
 */

#define m_ldi() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        MREQ_WR(DE_W, T1_L); \
        ++HL_W; \
        ++DE_W; \
        --BC_W; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (BC_W != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * ldd
 */

#define m_ldd() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        MREQ_WR(DE_W, T1_L); \
        --HL_W; \
        --DE_W; \
        --BC_W; \
        AF_L = /* SF is not affected */ (SF & (AF_L)) \
             | /* ZF is not affected */ (ZF & (AF_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (BC_W != 0 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * cpi
 */

#define m_cpi() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        T0_L = AF_H - T1_L; \
        ++HL_W; \
        --BC_W; \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is affected     */ (HF & (AF_H ^ T1_L ^ T0_L)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (BC_W != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * cpd
 */

#define m_cpd() \
    do { \
        MREQ_RD(HL_W, T1_L); \
        T0_L = AF_H - T1_L; \
        --HL_W; \
        --BC_W; \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is affected     */ (HF & (AF_H ^ T1_L ^ T0_L)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (BC_W != 0 ? 0xff : 0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * ini
 */

#define m_ini() \
    do { \
        IORQ_RD(BC_W, T0_L); \
        MREQ_WR(HL_W, T0_L); \
        --BC_H; \
        ++HL_W; \
        AF_L = /* SF is unknown      */ (SF & (0x00)) \
             | /* ZF is affected     */ (ZF & (BC_H == 0 ? 0xff : 0x00)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is unknown      */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is unknown      */ (PF & (0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * ind
 */

#define m_ind() \
    do { \
        IORQ_RD(BC_W, T0_L); \
        MREQ_WR(HL_W, T0_L); \
        --BC_H; \
        --HL_W; \
        AF_L = /* SF is unknown      */ (SF & (0x00)) \
             | /* ZF is affected     */ (ZF & (BC_H == 0 ? 0xff : 0x00)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is unknown      */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is unknown      */ (PF & (0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * outi
 */

#define m_outi() \
    do { \
        MREQ_RD(HL_W, T0_L); \
        --BC_H; \
        ++HL_W; \
        IORQ_WR(BC_W, T0_L); \
        AF_L = /* SF is unknown      */ (SF & (0x00)) \
             | /* ZF is affected     */ (ZF & (BC_H == 0 ? 0xff : 0x00)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is unknown      */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is unknown      */ (PF & (0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * outd
 */

#define m_outd() \
    do { \
        MREQ_RD(HL_W, T0_L); \
        --BC_H; \
        --HL_W; \
        IORQ_WR(BC_W, T0_L); \
        AF_L = /* SF is unknown      */ (SF & (0x00)) \
             | /* ZF is affected     */ (ZF & (BC_H == 0 ? 0xff : 0x00)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is unknown      */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is unknown      */ (PF & (0x00)) \
             | /* NF is set          */ (NF & (0xff)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * ld a,i
 */

#define m_ld_a_i() \
    do { \
        AF_H = IR_H; \
        T3_L = PZSTable[AF_H]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (HAS_IFF2 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * ld a,r
 */

#define m_ld_a_r() \
    do { \
        AF_H = IR_L; \
        T3_L = PZSTable[AF_H]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (HAS_IFF2 ? 0xff : 0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * ld i,a
 */

#define m_ld_i_a() \
    do { \
        IR_H = AF_H; \
    } while(0)

/*
 * ld r,a
 */

#define m_ld_r_a() \
    do { \
        IR_L = AF_H; \
    } while(0)

/*
 * in r08,(r08)
 */

#define m_in_r08_ind_r08(data, port) \
    do { \
        T1_H = BC_H; \
        T1_L = port; \
        IORQ_RD(T1_W, data); \
        AF_L = PZSTable[data] | (AF_L & CF); \
    } while(0)

/*
 * out (r08),r08
 */

#define m_out_ind_r08_r08(port, data) \
    do { \
        T1_H = BC_H; \
        T1_L = port; \
        IORQ_WR(T1_W, data); \
    } while(0)

/*
 * ld r16,(i16)
 */

#define m_ld_r16_ind_i16(reg1) \
    do { \
        MREQ_RD(PC_W++, T1_L); \
        MREQ_RD(PC_W++, T1_H); \
        MREQ_RD(T1_W++, T2_L); \
        MREQ_RD(T1_W++, T2_H); \
        reg1 = T2_W; \
    } while(0)

/*
 * ld (i16),r16
 */

#define m_ld_ind_i16_r16(reg1) \
    do { \
        T2_W = reg1; \
        MREQ_RD(PC_W++, T1_L); \
        MREQ_RD(PC_W++, T1_H); \
        MREQ_WR(T1_W++, T2_L); \
        MREQ_WR(T1_W++, T2_H); \
    } while(0)

/*
 * adc r16,r16
 */

#define m_adc_r16_r16(reg1, reg2) \
    do { \
        M_ADCW(reg1, reg2); \
    } while(0)

/*
 * sbc r16,r16
 */

#define m_sbc_r16_r16(reg1, reg2) \
    do { \
        M_SBCW(reg1, reg2); \
    } while(0)

/*
 * rlc r08
 */

#define m_rlc_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (UNSIGNED_BYTE(T1_L) >> 7); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * rlc (r16)
 */

#define m_rlc_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (UNSIGNED_BYTE(T1_L) >> 7); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * rrc r08
 */

#define m_rrc_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) | (UNSIGNED_BYTE(T1_L) << 7); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * rrc (r16)
 */

#define m_rrc_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) | (UNSIGNED_BYTE(T1_L) << 7); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * rl r08
 */

#define m_rl_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (AF_L & CF ? BIT0 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * rl (r16)
 */

#define m_rl_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (AF_L & CF ? BIT0 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * rr r08
 */

#define m_rr_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) | (AF_L & CF ? BIT7 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * rr (r16)
 */

#define m_rr_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) | (AF_L & CF ? BIT7 : 0x00); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * sla r08
 */

#define m_sla_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (SIGNED_BYTE(T1_L) << 1); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * sla (r16)
 */

#define m_sla_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (SIGNED_BYTE(T1_L) << 1); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * sra r08
 */

#define m_sra_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (SIGNED_BYTE(T1_L) >> 1); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * sra r16
 */

#define m_sra_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (SIGNED_BYTE(T1_L) >> 1); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * sll r08
 */

#define m_sll_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (BIT0); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * sll (r16)
 */

#define m_sll_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (UNSIGNED_BYTE(T1_L) << 1) | (BIT0); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit7    */ (CF & (T1_L & BIT7 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * srl r08
 */

#define m_srl_r08(data) \
    do { \
        T1_L = data; \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) & (~BIT7); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        data = T0_L; \
    } while(0)

/*
 * srl (r16)
 */

#define m_srl_ind_r16(addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (UNSIGNED_BYTE(T1_L) >> 1) & (~BIT7); \
        T3_L = PZSTable[T0_L]; \
        AF_L = /* SF is affected     */ (SF & (T3_L)) \
             | /* ZF is affected     */ (ZF & (T3_L)) \
             | /* YF is undocumented */ (YF & (0x00)) \
             | /* HF is reset        */ (HF & (0x00)) \
             | /* XF is undocumented */ (XF & (0x00)) \
             | /* PF is affected     */ (PF & (T3_L)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is data bit0    */ (CF & (T1_L & BIT0 ? 0xff : 0x00)) \
             ; \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * bit r08
 */

#define m_bit_b_r08(mask, data) \
    do { \
        T1_L = data; \
        T0_L = (T1_L & mask); \
        AF_L = /* SF is undocumented */ (SF & (T0_L & mask)) \
             | /* ZF is affected     */ (ZF & (T0_L == 0x00 ? 0xff : 0x00)) \
             | /* YF is undocumented */ (YF & (T0_L & mask)) \
             | /* HF is set          */ (HF & (0xff)) \
             | /* XF is undocumented */ (XF & (T0_L & mask)) \
             | /* PF is undocumented */ (PF & (0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * bit (r16)
 */

#define m_bit_b_ind_r16(mask, addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (T1_L & mask); \
        AF_L = /* SF is undocumented */ (SF & (T0_L & mask)) \
             | /* ZF is affected     */ (ZF & (T0_L == 0x00 ? 0xff : 0x00)) \
             | /* YF is undocumented */ (YF & (T0_L & mask)) \
             | /* HF is set          */ (HF & (0xff)) \
             | /* XF is undocumented */ (XF & (T0_L & mask)) \
             | /* PF is undocumented */ (PF & (0x00)) \
             | /* NF is reset        */ (NF & (0x00)) \
             | /* CF is not affected */ (CF & (AF_L)) \
             ; \
    } while(0)

/*
 * res r08
 */

#define m_res_b_r08(mask, data) \
    do { \
        T1_L = data; \
        T0_L = (T1_L & ~mask); \
        data = T0_L; \
    } while(0)

/*
 * res (r16)
 */

#define m_res_b_ind_r16(mask, addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (T1_L & ~mask); \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * set r08
 */

#define m_set_b_r08(mask, data) \
    do { \
        T1_L = data; \
        T0_L = (T1_L | mask); \
        data = T0_L; \
    } while(0)

/*
 * set (r16)
 */

#define m_set_b_ind_r16(mask, addr) \
    do { \
        MREQ_RD(addr, T1_L); \
        T0_L = (T1_L | mask); \
        MREQ_WR(addr, T0_L); \
    } while(0)

/*
 * exx
 */

#define m_exx() \
    do { \
      T0_W = BC_W; BC_W = BC_P; BC_P = T0_W; \
      T0_W = DE_W; DE_W = DE_P; DE_P = T0_W; \
      T0_W = HL_W; HL_W = HL_P; HL_P = T0_W; \
    } while(0)

/*
 * jr i08
 */

#define m_jr_i08() \
    do { \
        PC_W += SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W, 0x00)) + 1; \
    } while(0)

/*
 * jr nz,i08
 */

#define m_jr_nz_i08() \
    do { \
        if((AF_L & ZF) == 0) { \
            PC_W += SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W, 0x00)) + 1; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            PC_W += 1; \
        } \
    } while(0)

/*
 * jr z,i08
 */

#define m_jr_z_i08() \
    do { \
        if((AF_L & ZF) != 0) { \
            PC_W += SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W, 0x00)) + 1; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            PC_W += 1; \
        } \
    } while(0)

/*
 * jr nc,i08
 */

#define m_jr_nc_i08() \
    do { \
        if((AF_L & CF) == 0) { \
            PC_W += SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W, 0x00)) + 1; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            PC_W += 1; \
        } \
    } while(0)

/*
 * jr c,i08
 */

#define m_jr_c_i08() \
    do { \
        if((AF_L & CF) != 0) { \
            PC_W += SIGNED_BYTE((*IFACE.mreq_rd)(SELF, PC_W, 0x00)) + 1; \
            M_CYCLES += 1; \
            T_STATES += 5; \
            I_PERIOD -= 5; \
        } \
        else { \
            PC_W += 1; \
        } \
    } while(0)

/*
 * jp i16
 */

#define m_jp_i16() \
    do { \
        MREQ_RD(PC_W++, T0_L); \
        MREQ_RD(PC_W++, T0_H); \
        PC_W = T0_W; \
    } while(0)

/*
 * jp r16
 */

#define m_jp_r16(reg1) \
    do { \
        PC_W = reg1; \
    } while(0)

/*
 * jp nz,i16
 */

#define m_jp_nz_i16() \
    do { \
        if((AF_L & ZF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp z,i16
 */

#define m_jp_z_i16() \
    do { \
        if((AF_L & ZF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp nc,i16
 */

#define m_jp_nc_i16() \
    do { \
        if((AF_L & CF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp c,i16
 */

#define m_jp_c_i16() \
    do { \
        if((AF_L & CF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp po,i16
 */

#define m_jp_po_i16() \
    do { \
        if((AF_L & PF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp pe,i16
 */

#define m_jp_pe_i16() \
    do { \
        if((AF_L & PF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp p,i16
 */

#define m_jp_p_i16() \
    do { \
        if((AF_L & SF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * jp m,i16
 */

#define m_jp_m_i16() \
    do { \
        if((AF_L & SF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            PC_W = T0_W; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call i16
 */

#define m_call_i16() \
    do { \
        MREQ_RD(PC_W++, T0_L); \
        MREQ_RD(PC_W++, T0_H); \
        MREQ_WR(--SP_W, PC_H); \
        MREQ_WR(--SP_W, PC_L); \
        PC_W = T0_W; \
    } while(0)

/*
 * call nz,i16
 */

#define m_call_nz_i16() \
    do { \
        if((AF_L & ZF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call z,i16
 */

#define m_call_z_i16() \
    do { \
        if((AF_L & ZF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call nc,i16
 */

#define m_call_nc_i16() \
    do { \
        if((AF_L & CF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call c,i16
 */

#define m_call_c_i16() \
    do { \
        if((AF_L & CF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call po,i16
 */

#define m_call_po_i16() \
    do { \
        if((AF_L & PF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call pe,i16
 */

#define m_call_pe_i16() \
    do { \
        if((AF_L & PF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call p,i16
 */

#define m_call_p_i16() \
    do { \
        if((AF_L & SF) == 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * call m,i16
 */

#define m_call_m_i16() \
    do { \
        if((AF_L & SF) != 0) { \
            MREQ_RD(PC_W++, T0_L); \
            MREQ_RD(PC_W++, T0_H); \
            MREQ_WR(--SP_W, PC_H); \
            MREQ_WR(--SP_W, PC_L); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 7; \
            I_PERIOD -= 7; \
        } \
        else { \
            PC_W += 2; \
        } \
    } while(0)

/*
 * ret
 */

#define m_ret() \
    do { \
        MREQ_RD(SP_W++, T0_L); \
        MREQ_RD(SP_W++, T0_H); \
        PC_W = T0_W; \
    } while(0)

/*
 * ret nz
 */

#define m_ret_nz() \
    do { \
        if((AF_L & ZF) == 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret z
 */

#define m_ret_z() \
    do { \
        if((AF_L & ZF) != 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret nc
 */

#define m_ret_nc() \
    do { \
        if((AF_L & CF) == 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret c
 */

#define m_ret_c() \
    do { \
        if((AF_L & CF) != 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret po
 */

#define m_ret_po() \
    do { \
        if((AF_L & PF) == 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret pe
 */

#define m_ret_pe() \
    do { \
        if((AF_L & PF) != 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret p
 */

#define m_ret_p() \
    do { \
        if((AF_L & SF) == 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * ret m
 */

#define m_ret_m() \
    do { \
        if((AF_L & SF) != 0) { \
            MREQ_RD(SP_W++, T0_L); \
            MREQ_RD(SP_W++, T0_H); \
            PC_W = T0_W; \
            M_CYCLES += 2; \
            T_STATES += 6; \
            I_PERIOD -= 6; \
        } \
    } while(0)

/*
 * xxx
 */

#define m_add_r16_r16(reg1, reg2) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_ccf() \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_cpl() \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_dec_ind_r16(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_djnz_i08() \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_ex_ind_r16_r16(reg1, reg2) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_ex_r16_r16(reg1, reg2) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_inc_ind_r16(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_in_r08_ind_i08(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_ld_ind_i16_r08(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_ld_ind_r16_i08(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_ld_r08_ind_i16(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_out_ind_i08_r08(reg1) \
    do { \
    } while(0)

/*
 * xxx
 */

#define m_scf() \
    do { \
    } while(0)

/*
 * xxx
 */

enum Codes
{
    NOP,LD_BC_WORD,LD_xBC_A,INC_BC,INC_B,DEC_B,LD_B_BYTE,RLCA,
    EX_AF_AF,ADD_HL_BC,LD_A_xBC,DEC_BC,INC_C,DEC_C,LD_C_BYTE,RRCA,
    DJNZ,LD_DE_WORD,LD_xDE_A,INC_DE,INC_D,DEC_D,LD_D_BYTE,RLA,
    JR,ADD_HL_DE,LD_A_xDE,DEC_DE,INC_E,DEC_E,LD_E_BYTE,RRA,
    JR_NZ,LD_HL_WORD,LD_xWORD_HL,INC_HL,INC_H,DEC_H,LD_H_BYTE,DAA,
    JR_Z,ADD_HL_HL,LD_HL_xWORD,DEC_HL,INC_L,DEC_L,LD_L_BYTE,CPL,
    JR_NC,LD_SP_WORD,LD_xWORD_A,INC_SP,INC_xHL,DEC_xHL,LD_xHL_BYTE,SCF,
    JR_C,ADD_HL_SP,LD_A_xWORD,DEC_SP,INC_A,DEC_A,LD_A_BYTE,CCF,
    LD_B_B,LD_B_C,LD_B_D,LD_B_E,LD_B_H,LD_B_L,LD_B_xHL,LD_B_A,
    LD_C_B,LD_C_C,LD_C_D,LD_C_E,LD_C_H,LD_C_L,LD_C_xHL,LD_C_A,
    LD_D_B,LD_D_C,LD_D_D,LD_D_E,LD_D_H,LD_D_L,LD_D_xHL,LD_D_A,
    LD_E_B,LD_E_C,LD_E_D,LD_E_E,LD_E_H,LD_E_L,LD_E_xHL,LD_E_A,
    LD_H_B,LD_H_C,LD_H_D,LD_H_E,LD_H_H,LD_H_L,LD_H_xHL,LD_H_A,
    LD_L_B,LD_L_C,LD_L_D,LD_L_E,LD_L_H,LD_L_L,LD_L_xHL,LD_L_A,
    LD_xHL_B,LD_xHL_C,LD_xHL_D,LD_xHL_E,LD_xHL_H,LD_xHL_L,HALT,LD_xHL_A,
    LD_A_B,LD_A_C,LD_A_D,LD_A_E,LD_A_H,LD_A_L,LD_A_xHL,LD_A_A,
    ADD_B,ADD_C,ADD_D,ADD_E,ADD_H,ADD_L,ADD_xHL,ADD_A,
    ADC_B,ADC_C,ADC_D,ADC_E,ADC_H,ADC_L,ADC_xHL,ADC_A,
    SUB_B,SUB_C,SUB_D,SUB_E,SUB_H,SUB_L,SUB_xHL,SUB_A,
    SBC_B,SBC_C,SBC_D,SBC_E,SBC_H,SBC_L,SBC_xHL,SBC_A,
    AND_B,AND_C,AND_D,AND_E,AND_H,AND_L,AND_xHL,AND_A,
    XOR_B,XOR_C,XOR_D,XOR_E,XOR_H,XOR_L,XOR_xHL,XOR_A,
    OR_B,OR_C,OR_D,OR_E,OR_H,OR_L,OR_xHL,OR_A,
    CP_B,CP_C,CP_D,CP_E,CP_H,CP_L,CP_xHL,CP_A,
    RET_NZ,POP_BC,JP_NZ,JP,CALL_NZ,PUSH_BC,ADD_BYTE,RST00,
    RET_Z,RET,JP_Z,PFX_CB,CALL_Z,CALL,ADC_BYTE,RST08,
    RET_NC,POP_DE,JP_NC,OUTA,CALL_NC,PUSH_DE,SUB_BYTE,RST10,
    RET_C,EXX,JP_C,INA,CALL_C,PFX_DD,SBC_BYTE,RST18,
    RET_PO,POP_HL,JP_PO,EX_HL_xSP,CALL_PO,PUSH_HL,AND_BYTE,RST20,
    RET_PE,LD_PC_HL,JP_PE,EX_DE_HL,CALL_PE,PFX_ED,XOR_BYTE,RST28,
    RET_P,POP_AF,JP_P,DI,CALL_P,PUSH_AF,OR_BYTE,RST30,
    RET_M,LD_SP_HL,JP_M,EI,CALL_M,PFX_FD,CP_BYTE,RST38
};

#define WrZ80(addr,data)  ((*IFACE.mreq_wr)((SELF),(addr),(data)))
#define RdZ80(addr)       ((*IFACE.mreq_rd)((SELF),(addr),(0x00)))
#define OutZ80(addr,data) ((*IFACE.iorq_wr)((SELF),(addr),(data)))
#define InZ80(addr)       ((*IFACE.iorq_rd)((SELF),(addr),(0x00)))

#define S(Fl)        REGS.AF.b.l|=Fl
#define R(Fl)        REGS.AF.b.l&=~(Fl)
#define FLAGS(Rg,Fl) REGS.AF.b.l=Fl|ZSTable[Rg]

#define M_POP(Rg)      \
  REGS.Rg.b.l=RdZ80(REGS.SP.w.l++);REGS.Rg.b.h=RdZ80(REGS.SP.w.l++)

#define M_PUSH(Rg)     \
  WrZ80(--REGS.SP.w.l,REGS.Rg.b.h);WrZ80(--REGS.SP.w.l,REGS.Rg.b.l)

#define M_CALL         \
  WZ.b.l=RdZ80(REGS.PC.w.l++);WZ.b.h=RdZ80(REGS.PC.w.l++);         \
  WrZ80(--REGS.SP.w.l,REGS.PC.b.h);WrZ80(--REGS.SP.w.l,REGS.PC.b.l); \
  REGS.PC.w.l=WZ.w.l

#define M_JP  WZ.b.l=RdZ80(REGS.PC.w.l++);WZ.b.h=RdZ80(REGS.PC.w.l);REGS.PC.w.l=WZ.w.l
#define M_JR  REGS.PC.w.l+=(int8_t)RdZ80(REGS.PC.w.l)+1
#define M_RET REGS.PC.b.l=RdZ80(REGS.SP.w.l++);REGS.PC.b.h=RdZ80(REGS.SP.w.l++)

#define M_RST(Ad)      \
  WrZ80(--REGS.SP.w.l,REGS.PC.b.h);WrZ80(--REGS.SP.w.l,REGS.PC.b.l);REGS.PC.w.l=Ad

#define M_LDWORD(Rg)   \
  REGS.Rg.b.l=RdZ80(REGS.PC.w.l++);REGS.Rg.b.h=RdZ80(REGS.PC.w.l++)

#define M_SUB(Rg)      \
  WZ.w.l=REGS.AF.b.h-Rg;    \
  REGS.AF.b.l=           \
    ((REGS.AF.b.h^Rg)&(REGS.AF.b.h^WZ.b.l)&0x80? VF:0)| \
    NF|-WZ.b.h|ZSTable[WZ.b.l]|                      \
    ((REGS.AF.b.h^Rg^WZ.b.l)&HF);                     \
  REGS.AF.b.h=WZ.b.l

#define M_IN(Rg)        \
  Rg=InZ80(REGS.BC.w.l);  \
  REGS.AF.b.l=PZSTable[Rg]|(REGS.AF.b.l&CF)

#define M_INC(Rg)       \
  Rg++;                 \
  REGS.AF.b.l=            \
    (REGS.AF.b.l&CF)|ZSTable[Rg]|           \
    (Rg==0x80? VF:0)|(Rg&0x0F? 0:HF)

#define M_DEC(Rg)       \
  Rg--;                 \
  REGS.AF.b.l=            \
    NF|(REGS.AF.b.l&CF)|ZSTable[Rg]| \
    (Rg==0x7F? VF:0)|((Rg&0x0F)==0x0F? HF:0)

#define M_ADDW(Rg1,Rg2) \
  WZ.w.l=(REGS.Rg1.w.l+REGS.Rg2.w.l)&0xFFFF;                        \
  REGS.AF.b.l=                                             \
    (REGS.AF.b.l&~(HF|NF|CF))|                 \
    ((REGS.Rg1.w.l^REGS.Rg2.w.l^WZ.w.l)&0x1000? HF:0)|          \
    (((long)REGS.Rg1.w.l+(long)REGS.Rg2.w.l)&0x10000? CF:0); \
  REGS.Rg1.w.l=WZ.w.l

#define M_ADCW(reg1, reg2) \
  T2_W = reg2; \
  T1_L=AF_L&CF;WZ_W=(reg1+T2_W+T1_L)&0xFFFF; \
  AF_L= \
    (((long)reg1+(long)T2_W+(long)T1_L)&0x10000? CF:0)| \
    (~(reg1^T2_W)&(T2_W^WZ_W)&0x8000? VF:0)| \
    ((reg1^T2_W^WZ_W)&0x1000? HF:0)| \
    (WZ_W? 0:ZF)|(WZ.b.h&SF); \
  reg1=WZ_W

#define M_SBCW(reg1, reg2) \
  T2_W = reg2; \
  T1_L=AF_L&CF;WZ_W=(reg1-T2_W-T1_L)&0xFFFF; \
  AF_L= \
    NF| \
    (((long)reg1-(long)T2_W-(long)T1_L)&0x10000? CF:0)| \
    ((reg1^T2_W)&(reg1^WZ_W)&0x8000? VF:0)| \
    ((reg1^T2_W^WZ_W)&0x1000? HF:0)| \
    (WZ_W? 0:ZF)|(WZ.b.h&SF); \
  reg1=WZ_W

#ifdef __cplusplus
}
#endif

#endif /* __XCPC_CPU_Z80A_PRIV_H__ */
