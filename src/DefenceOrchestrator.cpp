#include "DefenceOrchestrator.hpp"
#include <iostream>

namespace mahoraga
{
    DefenceOrchestrator::DefenceOrchestrator()
    {
    }

    DefenceOrchestrator::~DefenceOrchestrator()
    {
    }

    void DefenceOrchestrator::executeMitigation(const std::string& threatDetails)
    {
        std::cout << "[MEGUMID ALERT] Threat mitigation executed for: " << threatDetails << std::endl;
    }
}
