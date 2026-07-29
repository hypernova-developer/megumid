#include "MegumiDaemon.hpp"
#include <memory>
#include <csignal>

std::unique_ptr<mahoraga::MegumiDaemon> globalDaemon = nullptr;

void handleSignal(int signal)
{
    if (globalDaemon)
    {
        globalDaemon->stop();
    }
}

int main()
{
    std::signal(SIGINT, handleSignal);
    std::signal(SIGTERM, handleSignal);

    std::string targetPath = "/usr/local/bin/mahoraga";
    globalDaemon = std::make_unique<mahoraga::MegumiDaemon>(targetPath);
    globalDaemon->start();

    return 0;
}
