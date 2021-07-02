//
// Created by Xialin He on 2021/6/28.
//

#ifndef RISC_V_SIMULATOR_HPP
#define RISC_V_SIMULATOR_HPP
#include<iostream>
#include "Types.hpp"
#include <cmath>

using namespace std;
unsigned char memory[1000000];
unsigned int a[100];
class Simulator{
public:
    int sext(int n,unsigned int x_){
        if (x_ & (1u << (n - 1))){
            return x_ - (1u << n);
        } else return x_;
    }
    int x[32];
    unsigned int pc = 0;
    Simulator() {
        x[0] = 0;
        pc = 0;
    }
    type funct3(unsigned int x1,unsigned int opt){
        if(opt == 99) {
            switch (x1) {
                case 0:
                    return BEQ;
                case 1:
                    return BNE;
                case 4:
                    return BLT;
                case 5:
                    return BGE;
                case 6:
                    return BLTU;
                case 7:
                    return BGEU;
                default: throw("e");
            }
        }else if(opt == 3){
            switch (x1) {
                case 0:
                    return LB;
                case 1:
                    return LH;
                case 2:
                    return LW;
                case 4:
                    return LBU;
                case 5:
                    return LHU;
                default:throw("e");
            }
        }else if(opt == 35){
            switch(x1){
                case 0:
                    return SB;
                case 1:
                    return SH;
                case 2:
                    return SW;
                default: throw("d");
            }
        }else if(opt == 19){
            switch (x1) {
                case 0:
                    //printf("ADDI");
                    return ADDI;
                case 2:
                    //printf("SLTI");
                    return SLTI;
                case 3:
                    //printf("SLTIU");
                    return SLTIU;
                case 4:
                    //printf("XORI");
                    return XORI;
                case 6:
                    //printf("ORI");
                    return ORI;
                case 7:
                    //printf("ANDI");
                    return ANDI;
                default:throw("g");
            }
        }
    }
    type funct7(unsigned int x1,unsigned int y,unsigned int opt){
        if(opt == 19){
            if(x1 == 0){
                //printf("ADDI");
                return ADDI;
            }
            else if(x1 == 2){
                //printf("ALTI");
                return SLTI;
            }
            else if(x1 == 3){
                //printf("SLTIU");
                return SLTIU;
            }
            else if(x1 == 4){
                //printf("XORI");
                return XORI;
            }
            else if(x1 == 6){
                //printf("ORI");
                return ORI;
            }
            else if(x1 == 7){
                //printf("ANDI");
                return ANDI;
            }
            else if(x1 == 1 && y == 0){
                //printf("SLLI");
                return SLLI;
            }
            else if(x1 == 5 && y == 0){
                //printf("SRLI");
                return SRLI;
            }
            else if(x1 == 5 && y == 32){
                //printf("SRAI");
                return SRAI;
            }
        }else if(opt == 51){
            if(x1 == 0 && y == 0){
                //printf("ADD");
                return ADD;
            }
            else if(x1 == 0 && y == 32){
                //printf("SUB");
                return SUB;
            }
            else if(x1 == 1 && y == 0){
                //printf("SLL");
                return SLL;
            }
            else if(x1 == 2 && y == 0){
                //printf("SLT");
                return SLT;
            }
            else if(x1 == 3 && y == 0){
                //printf("SLTU");
                return SLTU;
            }
            else if(x1 == 4 && y == 0){
                //printf("XOR");
                return XOR;
            }
            else if(x1 == 5 && y == 0){
                //printf("SRL");
                return SRL;
            }
            else if(x1 == 5 && y == 32){
                //printf("SRA");
                return SRA;
            }
            else if(x1 == 6 && y == 0){
                //printf("OR");
                return OR;
            }
            else if(x1 == 7 && y == 0){
                //printf("AND");
                return AND;
            }
        }
    }
    type gettokentype(unsigned int x_){
        unsigned int case1 = x_ & 127;
        unsigned int x1 = x_;
        unsigned int x2 = x_;
        x1 = x1 >> 12;
        x1 = x1 & 7;
        x2 = x2 >> 25;
        switch (case1) {
            case 55: {
                //printf("LUI");
                return LUI;
            }
            case 23: {
                //printf("AUIPC");
                return AUIPC;
            }
            case 111: {
                //printf("JAL");
                return JAL;
            }
            case 103: {
                //printf("JALR");
                return JALR;
            }
            case 99: {
                return funct3(x1,case1);
            }
            case 3:{//0000011
                return funct3(x1,case1);
            }
            case 35:{//0100011
                return funct3(x1,case1);
            }
            case 19:{//0010011
                return funct7(x1,x2,case1);
            }
            case 51:{//0110011
                return funct7(x1,x2,case1);
            }
            default:throw ("e");
        }
    }
    BIG_TYPE gettokenbigtype(unsigned int x_){
        unsigned int y = x_ & 127;
        unsigned int x1 = x_ << 12;
        x1 &= 7;
        if(y == 0b0110111){
            //printf(" U ");
            return U;
        }
        if(y == 0b0010111){
            //printf(" U ");
            return U;
        }
        if(y == 0b1101111){
            //printf(" J ");
            return J;
        }
        if(y == 0b1100011){
            //printf(" B ");
            return B;
        }
        if(y == 0b0000011){
            //printf(" I ");
            return I;
        }
        if(y == 0b1100111){
            //printf(" I ");
            return I;
        }
        if(y == 0b0100011){
            //printf(" S ");
            return S;
        }
        if(y == 0b0110011){
            //printf(" R ");
            return R;
        }
        if(y == 0b0010011){
            if(x1 == 1 || x1 == 5){
                //printf(" R ");
                return R;
            }
            else {
                //printf(" I ");
                return I;
            }
        }
    }
    struct BUFFER{
        int bubble = 0;
        BIG_TYPE BT;
        type t;
        unsigned int command;
        unsigned int ans;
        unsigned int offset;
        int len = -1;
    };
    struct PREIF{
        int pc = 0;
        bool endornot = false;
        int bubble = 0;
    }preIF;
    struct PREID{
        int pc;
        bool endornot = false;
        bool empty = true;
        int bubble = 1;
        BIG_TYPE BT;
        type t;
        unsigned int command;
        unsigned int rs1,rs2,rd;
        int rs1_value,rs2_value;
        unsigned int imm;
    }preID;
    struct PREEX{
        int pc;
        bool endornot = false;
        bool empty = true;
        int bubble = 2;
        BIG_TYPE BT;
        type t;
        unsigned int command;
        unsigned int rs1,rs2,rd;
        unsigned int imm;
        bool ifmem = false;
        bool pc_possible_change = false;
    }preEX;
    struct PREMEM{
        int pc;
        bool endornot = false;
        bool empty = true;
        int bubble = 3;
        BIG_TYPE BT;
        type t;
        unsigned int command,rd;
        unsigned int rd_value;
        bool memo = false;
        struct memory_{
            unsigned int offset,value;
            int len = -1;
        }M;
        bool ifpcchanged = false;
    }preMEM;
    struct PREWB{
        int pc;
        bool endornot = false;
        bool empty = true;
        int bubble = 4;
        BIG_TYPE BT;
        type t;
        int command,rd;
        int rd_value;
    }preWB;
    void IF(){
        if(preIF.endornot)return;
        if(preIF.bubble){
            preIF.bubble--;
            cout << "IF BUBBLE" << " " << preIF.bubble << endl;
            return;
        }

        unsigned int command = (memory[pc + 3] << 24) + (memory[pc + 2] << 16) + (memory[pc + 1] << 8) + memory[pc];

            if(preEX.pc_possible_change) {
                preEX.pc_possible_change = false;
                preIF.bubble += 2;
                preID.bubble += 3;
                preID.empty = false;
                return;
            }
        //unsigned int command = (memory[pc] << 24) + (memory[pc + 1] << 16) + (memory[pc + 2] << 8) + memory[pc + 3];
        //unsigned int command = (memory[pc + 3] << 24) + (memory[pc + 2] << 16) + (memory[pc + 1] << 8) + memory[pc];
        if(command == 0x0ff00513){
            preIF.endornot = true;
        }
        if(command == 4213174511){
            cout << " sdfbs" << endl;
        }
        preID.command = command;
        preID.empty = false;
        pc += 4;
        preID.pc = pc - 4;

        cout << command << "\t" << pc << endl;
        //cout << (unsigned)x[12] << "\t" << (unsigned)x[11] <<endl;
        return;
    }
    void ID(){
        if(preID.endornot)return;
        if(preID.bubble){
            preID.bubble--;
            cout << "ID bubble" << " " << preID.bubble<<endl;
            return;
        }

        else {
            if (preID.empty) {
                return;
            } else {
                if(preID.command == 0x0ff00513){
                    preID.endornot = true;
                    preEX.command = preID.command;
                    preEX.empty = false;
                    return;
                }
                preEX.empty = false;
                BIG_TYPE BT = gettokenbigtype(preID.command);
                preEX.pc = preID.pc;
                preID.empty = true;
                preEX.t = gettokentype(preID.command);
                preID.BT = BT;
                preEX.BT = preID.BT;
                preEX.command = preID.command;
                preEX.rd = (preID.command >> 7) & 31;
                preEX.rs1 = (preID.command >> 15) & 31;
                preEX.rs2 = (preID.command >> 20) & 31;
                if (BT == R) {
                    preEX.rd = (preID.command >> 7) & 31;
                    preEX.rs1 = (preID.command >> 15) & 31;
                    preEX.rs2 = (preID.command >> 20) & 31;
                } else if (BT == I) {
                    unsigned int rd = (preID.command >> 7) & 31;
                    unsigned int rs1 = (preID.command >> 15) & 31;
                    unsigned int imm110 = preID.command >> 20;
                    imm110 = sext(12, imm110);
                    preEX.rd = rd;
                    preEX.rs1 = rs1;
                    preEX.imm = imm110;
                } else if (BT == S) {
                    unsigned int rs1 = (preID.command >> 15) & 31;
                    unsigned int rs2 = (preID.command >> 20) & 31;
                    unsigned int imm115 = preID.command >> 25;
                    unsigned int imm40 = (preID.command >> 7) & 31;
                    unsigned int imm = (imm115 << 5) + imm40;
                    imm = sext(12, imm);
                    preEX.rs1 = rs1;
                    preEX.rs2 = rs2;
                    preEX.imm = imm;
                } else if (BT == B) {
                    unsigned int rs1 = (preID.command >> 15) & 31;
                    unsigned int rs2 = (preID.command >> 20) & 31;
                    unsigned int imm = ((preID.command >> 31) << 12) + (((preID.command >> 7) & 1) << 11) +
                                       (((preID.command >> 25) & 63) << 5) + (((preID.command >> 8) & 15) << 1);
                    imm = sext(13, imm);
                    preEX.rs1 = rs1;
                    preEX.rs2 = rs2;
                    preEX.imm = imm;
                } else if (BT == U) {
                    unsigned int imm3112 = (preID.command >> 12) << 12;
                    preEX.rd = (preID.command >> 7) & 31;
                    preEX.imm = imm3112;
                } else if (BT == J) {
                    preEX.rd = (preID.command >> 7) & 31;
                    unsigned int imm = ((preID.command >> 31) << 20) + (((preID.command >> 12) & 255) << 12) +
                                       (((preID.command >> 20) & 1) << 11) + (((preID.command >> 21) & 1023) << 1);
                    imm = sext(21, imm);
                    preEX.imm = imm;
                }
                if (BT == B || BT == J || preEX.t == JALR || preEX.t == AUIPC) {
                    preEX.pc_possible_change = true;
//                    if (preMEM.ifpcchanged) {
//                        preEX.bubble += 2;
//                        preID.bubble += 2;
//                        preIF.bubble += 2;
//                        return;
//                    }
                }
                if (preEX.rs1 != 0 && preEX.rs1 == preMEM.rd && !preMEM.memo) {
                    preEX.bubble += 2;
                    preEX.empty = false;
                    preID.bubble += 2;
                    preID.empty = false;
                    preIF.bubble += 2;
                    return;
                }
                if (preEX.rs2 != 0 && preEX.rs2 == preMEM.rd && !preMEM.memo) {
                    preEX.bubble += 2;
                    preID.bubble += 2;
                    preIF.bubble += 2;
                    preEX.empty = false;
                    preID.empty = false;
                    return;
                }
                if (preEX.rs1 != 0 && preEX.rs1 == preWB.rd) {
                    preEX.bubble++;
                    preID.bubble++;
                    preIF.bubble++;
                    preEX.empty = false;
                    preID.empty = false;
                    return;
                }
                if (preEX.rs2 != 0 && preEX.rs2 == preWB.rd) {
                    preEX.bubble++;
                    preID.bubble++;
                    preIF.bubble++;
                    preEX.empty = false;
                    preID.empty = false;
                    return;
                }
                if (preMEM.memo) {
                    if (preEX.t == LB || preEX.t == LH || preEX.t == LW || preEX.t == LBU || preEX.t == LHU && preEX.rs1 != 0) {
                        if (x[preEX.rs1] + preEX.imm == preMEM.M.offset ||
                            x[preEX.rs1] + preEX.imm == preMEM.M.offset + 1 ||
                            x[preEX.rs1] + preEX.imm == preMEM.M.offset + 2 ||
                            x[preEX.rs1] + preEX.imm == preMEM.M.offset + 3) {
                            preEX.bubble++;
                            preID.bubble++;
                            preIF.bubble++;
                            preEX.empty = false;
                            preID.empty = false;
                            return;
                        }
                    }
                }
            }
        }
    }
    void EX(){
        if(preEX.endornot)return;
        if(preEX.bubble){
            preEX.bubble--;
            cout << "EX bubble" << " "<< preEX.bubble << endl;
            return;
        }

        else {
            if (preEX.empty) {
                return;
            } else {
                if(preEX.command == 0x0ff00513){
                    preEX.endornot = true;
                    preMEM.command = 0x0ff00513;
                    preMEM.empty = false;
                    return;
                }
                preEX.pc_possible_change = false;
                preMEM.empty = false;
                preEX.empty = true;
                BIG_TYPE BT = preEX.BT;
                preMEM.BT = BT;
                unsigned int command = preEX.command;
                preMEM.command = command;
                unsigned int rd = preEX.rd;
                unsigned int rs1 = preEX.rs1;
                unsigned int rs2 = preEX.rs2;
                preMEM.rd = rd;
                if (BT == R) {
                    type t = gettokentype(command);
                    preMEM.t = t;
                    int ans = 0;
                    if (t == ADD) {
                        ans = x[rs1] + x[rs2];
                    } else if (t == SUB) {
                        ans = x[rs1] - x[rs2];
                    } else if (t == SLL) {
                        ans = x[rs1] << (x[rs2] & 0b11111);
                    } else if (t == SLT) {
                        ans = (x[rs1] < x[rs2]);
                    } else if (t == SLTU) {
                        ans = ((unsigned int) x[rs1] < (unsigned int) x[rs2]);
                    } else if (t == XOR) {
                        ans = x[rs1] ^ x[rs2];
                    } else if (t == SRL) {
                        ans = ((unsigned) x[rs1]) >> (unsigned int) (x[rs2] & 0b11111);
                    } else if (t == SRA) {
                        ans = x[rs1] >> (x[rs2] & 0b11111);
                    } else if (t == OR) {
                        ans = x[rs1] | x[rs2];
                    } else if (t == AND) {
                        ans = x[rs1] & x[rs2];
                    }
                    preMEM.rd_value = ans;
                    preMEM.rd = rd;
                } else if (BT == I) {
//            unsigned int rd = (command >> 7) & 31;
//            unsigned int rs1 = (command >> 15) & 31;
                    unsigned int imm110 = command >> 20;
                    int ans = 0;
                    imm110 = sext(12, imm110);
                    type t = gettokentype(command);
                    preMEM.t = t;
                    if (t == LB) {
                        unsigned int buffer = x[rs1] + imm110;
                        ans = memory[buffer];
                        ans = sext(8, ans);
                        //x[rd]=ans;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                    } else if (t == JALR) {
                        unsigned int t_ = preEX.pc + 4;
                        pc = (x[rs1] + imm110) & (~1);
                        //pc -= 4;
                        preMEM.ifpcchanged = true;
                        //x[rd]=t_;
                        preMEM.rd_value = t_;
                        preMEM.rd = rd;
                        if (!rd)return;
                    } else if (t == LH) {
                        unsigned int pos = x[rs1] + imm110;
                        unsigned int tmp = (memory[pos + 1] << 8) + memory[pos];
                        tmp = sext(16, tmp);
                        //x[rd] = tmp;
                        preMEM.rd_value = tmp;
                        preMEM.rd = rd;
                    } else if (t == LW) {
                        unsigned int pos = x[rs1] + imm110;
                        unsigned int tmp =
                                (memory[pos + 3] << 24) + (memory[pos + 2] << 16) + (memory[pos + 1] << 8) +
                                memory[pos];
                        //x[rd]=tmp;
                        preMEM.rd_value = tmp;
                        preMEM.rd = rd;
                    } else if (t == LBU) {
                        unsigned int buffer = (unsigned) x[rs1] + (unsigned) imm110;
                        ans = memory[buffer];
                        //x[rd] = ans;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                    } else if (t == LHU) {
                        unsigned int pos = (unsigned) x[rs1] + imm110;
                        unsigned int tmp = (memory[pos + 1] << 8) + memory[pos];
                        //x[rd]=tmp;
                        preMEM.rd_value = tmp;
                        preMEM.rd = rd;
                    } else if (t == ADDI) {
                        ans = x[rs1] + imm110;
                        //x[rd]=ans;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                    } else if (t == SLTI) {
                        ans = (x[rs1] < imm110);
                        //x[rd]=ans;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                    } else if (t == SLTIU) {
                        ans = ((unsigned) x[rs1] < (unsigned) imm110);
                        //x[rd]=ans;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                    } else if (t == XORI) {
                        ans = x[rs1] ^ imm110;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                        //
                    } else if (t == ANDI) {
                        ans = x[rs1] & imm110;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                        //
                    } else if (t == SLLI) {
                        //unsigned int rs2 = (command >> 20) & 31;
                        ans = x[rs1] << rs2;
                        ////printf(" %u\n",rs2);
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                        preMEM.BT = R;
                    } else if (t == SRLI) {
                        //unsigned int rs2 = (command >> 20) & 31;
                        ans = (unsigned) x[rs1] >> (unsigned) rs2;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                        preMEM.BT = R;
                    } else if (t == SRAI) {
                        //unsigned int rs2 = (command >> 20) & 31;
                        ans = x[rs1] >> rs2;
                        preMEM.rd_value = ans;
                        preMEM.rd = rd;
                        preMEM.BT = R;
                    }
                } else if (BT == S) {
//            unsigned int rs1 = (command >> 15) & 31;
//            unsigned int rs2 = (command >> 20) & 31;
                    unsigned int imm115 = command >> 25;
                    unsigned int imm40 = (command >> 7) & 31;
                    unsigned int imm = (imm115 << 5) + imm40;
                    imm = sext(12, imm);
                    type t = gettokentype(command);
                    preMEM.t = t;
                    if (t == SB) {
                        unsigned int offset = x[rs1] + imm;
                        //memory[offset] = (x[rs2] & ((1 << 8) - 1));
                        preMEM.memo = true;
                        preMEM.M.value = (x[rs2] & ((1 << 8) - 1));
                        preMEM.M.offset = offset;
                        preMEM.M.len = 1;
                    } else if (t == SH) {
                        unsigned int offset = x[rs1] + imm;
                        //memory[offset] = (x[rs2] & ((1 << 16) - 1));
                        preMEM.memo = true;
                        preMEM.M.value = (x[rs2] & ((1 << 16) - 1));
                        preMEM.M.offset = offset;
                        preMEM.M.len = 2;
                    } else if (t == SW) {
                        unsigned int offset = x[rs1] + imm;
                        //memory[offset] = x[rs2];
                        preMEM.memo = true;
                        preMEM.M.value = x[rs2];
                        preMEM.M.offset = offset;
                        preMEM.M.len = 4;
                    }
                } else if (BT == B) {
                    unsigned int imm =
                            ((command >> 31) << 12) + (((command >> 7) & 1) << 11) + (((command >> 25) & 63) << 5) +
                            (((command >> 8) & 15) << 1);
                    imm = sext(13, imm);
                    type t = gettokentype(command);
                    if (t == BEQ) {
                        if (x[rs1] == x[rs2]) {
                            preMEM.ifpcchanged = true;
                            pc = imm + preEX.pc;
                        }
                    } else if (t == BNE) {
                        if (x[rs1] != x[rs2]) {
                            preMEM.ifpcchanged = true;
                            pc = imm + preEX.pc;
                        }
                    } else if (t == BLT) {
                        if (x[rs1] < x[rs2]) {
                            preMEM.ifpcchanged = true;
                            pc = imm + preEX.pc;
                        }
                    } else if (t == BGE) {
                        if (x[rs1] >= x[rs2]) {
                            preMEM.ifpcchanged = true;
                            pc = imm + preEX.pc;
                        }
                    } else if (t == BLTU) {
                        if ((unsigned) x[rs1] < (unsigned) x[rs2]) {
                            preMEM.ifpcchanged = true;
                            pc = imm + preEX.pc;
                        }
                    } else if (t == BGEU) {
                        if ((unsigned) x[rs1] >= (unsigned) x[rs2]) {
                            preMEM.ifpcchanged = true;
                            pc = imm + preEX.pc;
                        }
                    }
                } else if (BT == U) {
                    unsigned int imm3112 = (command >> 12) << 12;
                    type t = gettokentype(command);
                    unsigned int ans = 0;
                    if (t == AUIPC) {
                        ans = preEX.pc + imm3112;
                    } else if (t == LUI) {
                        ans = imm3112;
                    }
                    preMEM.rd_value = ans;
                    preMEM.rd = rd;
                } else if (BT == J) {
                    unsigned int imm =
                            ((command >> 31) << 20) + (((command >> 12) & 255) << 12) + (((command >> 20) & 1) << 11) +
                            (((command >> 21) & 1023) << 1);
                    imm = sext(21, imm);
                    unsigned int ans = preEX.pc + 4;
                    preMEM.ifpcchanged = true;
                    pc = imm + preEX.pc;
                    preMEM.rd_value = ans;
                    preMEM.rd = rd;
                    if (!rd)return;
                }
            }
        }
    }
    void MEM(){
        if(preMEM.endornot)return;
        if(preMEM.bubble){
            preMEM.bubble--;
            cout << "MEM bubble" << " " << preMEM.bubble << endl;
            return;
        }

        if(preMEM.empty){
            return;
        }
        else {
            if(preMEM.command == 0x0ff00513){
                preMEM.endornot = true;
                preWB.command = 0x0ff00513;
                preWB.empty = false;
                return;
            }
            preWB.empty = false;
            preMEM.empty = true;
            unsigned int ans = preMEM.rd_value;
            unsigned int offset = preMEM.rd;
            BIG_TYPE BT = preMEM.BT;
            preWB.command = preMEM.command;
            preWB.rd = preMEM.rd;
            preWB.BT = preMEM.BT;
            preWB.rd_value = preMEM.rd_value;
            if (BT == S) {
                if (preMEM.memo) {
                    preMEM.memo = false;
                    int len = preMEM.M.len;
                    offset = preMEM.M.offset;
                    ans = preMEM.M.value;
                    memory[offset] = ans & 255;
                    if (len > 1)memory[offset + 1] = (ans >> 8) & 255;
                    if (len > 2)memory[offset + 2] = (ans >> 16) & 255;
                    if (len > 2)memory[offset + 3] = (ans >> 24) & 255;
                }
            }
        }
    }
    bool WB() {
        if(preWB.command == 0x0ff00513){
            printf("%u",(x[10] & 255));
            return false;
        }
        if (preWB.bubble) {

            preWB.bubble--;
            cout << "WB bubble" << " " << preWB.bubble << endl;
            return true;
        }

        if (!preWB.empty) {
            BIG_TYPE BT = preWB.BT;
            int offset = preWB.rd;
            int ans = preWB.rd_value;
//        if(BT == S || BT == B)return;
            if (BT == R) {
                if (offset == 0) {

                    return true;
                }
                x[offset] = ans;
                return true;
            } else if (BT == I) {
                if (offset == 0) {

                    return true;
                }
                x[offset] = ans;
                return true;
            } else if (BT == U) {
                if (offset == 0) {

                    return true;
                }
                x[offset] = ans;
                return true;
            } else if (BT == J) {
                if (offset == 0) {

                    return true;
                }
                x[offset] = ans;
                return true;
            }
            ;
            //printf("%u\t%u\n",preWB.command,pc);
        }else return true;
    }
    void RUN(){
//        while(true){
//            if(IF()){
//                ID();
//                EX();
//                MEM();
//                WB();
//            }else break;
//        }
        while(WB()){
            MEM();
            EX();
            ID();
            IF();
        }
    }
};

#endif //RISC_V_SIMULATOR_HPP