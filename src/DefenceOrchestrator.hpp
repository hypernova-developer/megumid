#ifndef DEFENCE_ORCHESTRATOR_HPP
#define DEFENCE_ORCHESTRATOR_HPP

#include <string>

namespace mahoraga
{
    class DefenceOrchestrator
    {
    public:
        DefenceOrchestrator();
        ~DefenceOrchestrator();
        void executeMitigation(const std::string& threatDetails);
    };
}

#endif
