#include "BrainDuck.h"
int IncrementInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    vm.setCurrentTape(vm.getCurrentTape() + 1);
    return 1;
}

int DecrementInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    vm.setCurrentTape(vm.getCurrentTape() - 1);
    return 1;
}

int MoveLeftInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    vm.decreaseTapeIndex();
    return 1;
}

int MoveRightInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    vm.increaseTapeIndex();
    return 1;
}

int LoopBeginInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    if (vm.getCurrentTape() == 0)
    {
        int balance = 1;
        size_t cnt = vm.getProgramCount();
        while (balance != 0)
        {
            cnt++;
            if (vm.getProgram()[cnt] == '[')
            {
                balance++;
            }
            else if (vm.getProgram()[cnt] == ']')
            {
                balance--;
            }
        }
        return cnt - vm.getProgramCount();
    }
    else
    {
        return 1;
    }
}

int LoopEndInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    if (vm.getCurrentTape() != 0)
    {
        int balance = 1;
        size_t cnt = vm.getProgramCount();
        while (balance != 0)
        {
            cnt--;
            if (vm.getProgram()[cnt] == '[')
            {
                balance--;
            }
            else if (vm.getProgram()[cnt] == ']')
            {
                balance++;
            }
        }
        return cnt - vm.getProgramCount();
    }
    else
    {
        return 1;
    }
}

int InputInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    char input;
    ss >> input;
    vm.setCurrentTape(input);
    return 1;
}

int OutputInstruction::execute(std::istream &ss, BrainDuckVM &vm)
{
    // Your code here
    std::cout << vm.getCurrentTape();
    return 1;
}