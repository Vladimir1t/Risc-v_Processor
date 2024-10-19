#include <iostream>
#include <fstream>

#include "risc_asm.hpp"
#include "risc_proc.hpp"
//#include "instr_regs.hpp"

int main(int argc, const char* argv[]) {

    if (argc < 3)
        return 0;
    
    std::ifstream asm_file;
    asm_file.open(argv[1]);

    std::ofstream bytecode;
    bytecode.open(argv[2], std::ios::binary);

    if (!(asm_file.is_open() && bytecode.is_open())) {
        std::cerr << "file wasn't opened\n";
        return 0;
    }

    std::string str_com;

    while (asm_file >> str_com) {
        std::cout << "command = " << str_com << std::endl;
        for (auto command : Instruction::commands) {
            if (command.name == str_com) {

                std::cout << "find instr\n";
                command.func(asm_file, bytecode);
            }
        }
        
    }
    asm_file.close();
    bytecode.close();

    return 0;
}