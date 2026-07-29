#ifndef MEGUMI_DAEMON_HPP
#define MEGUMI_DAEMON_HPP

#include <string>
#include <memory>
#include <thread>
#include "DefenceOrchestrator.hpp"

namespace mahoraga
{
    class MegumiDaemon
    {
    public:
        MegumiDaemon(const std::string& targetBinary);
        ~MegumiDaemon();
        void start();
        void stop();

    private:
        std::string binaryPath;
        bool active;
        std::unique_ptr<DefenceOrchestrator> orchestrator;
        std::thread workerThread;
        void processStream();
    };
}

#endif
