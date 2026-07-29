#include "MegumiDaemon.hpp"
#include <iostream>
#include <array>
#include <algorithm>
#include <cstdio>

namespace mahoraga
{
    MegumiDaemon::MegumiDaemon(const std::string& targetBinary)
        : binaryPath(targetBinary)
        , active(false)
        , orchestrator(std::make_unique<DefenceOrchestrator>())
    {
    }

    MegumiDaemon::~MegumiDaemon()
    {
        stop();
    }

    void MegumiDaemon::start()
    {
        active = true;
        processStream();
    }

    void MegumiDaemon::stop()
    {
        active = false;
    }

    void MegumiDaemon::processStream()
    {
        std::string command = binaryPath + " --spin";
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);

        if (!pipe)
        {
            return;
        }

        std::array<char, 256> buffer;
        while (active && fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
        {
            std::string line(buffer.data());
            std::string lowerLine = line;
            std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);

            if (lowerLine.find("abnormal") != std::string::npos)
            {
                orchestrator->executeMitigation(line);
            }
        }
    }
}
